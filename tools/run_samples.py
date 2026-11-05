#!/usr/bin/env python3
"""Compile C++ regression fixtures and compare normalized output."""

from __future__ import annotations

import json
import os
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "tests" / "manifest.json"


def run_case(case: dict, compiler: list[str], standard: str, build_dir: Path) -> bool:
    source = ROOT / case["source"]
    if not source.is_file():
        print(f"FAIL {case['name']}: source not found: {case['source']}")
        return False

    suffix = ".exe" if os.name == "nt" else ""
    executable = build_dir / (f"case_{abs(hash(case['name']))}" + suffix)
    command = compiler + [f"-std={standard}", "-O2", "-pipe", str(source), "-o", str(executable)]

    try:
        compiled = subprocess.run(command, capture_output=True, text=True)
    except FileNotFoundError:
        print(f"FAIL {case['name']}: compiler not found: {compiler[0]}")
        return False
    if compiled.returncode:
        print(f"FAIL {case['name']}: compilation failed")
        print(compiled.stderr)
        return False

    try:
        completed = subprocess.run(
            [str(executable)],
            input=case["input"],
            capture_output=True,
            text=True,
            timeout=5,
        )
    except subprocess.TimeoutExpired:
        print(f"FAIL {case['name']}: execution timed out")
        return False

    if completed.returncode:
        print(f"FAIL {case['name']}: program exited with {completed.returncode}")
        print(completed.stderr)
        return False

    if completed.stdout.split() != case["expected"].split():
        print(f"FAIL {case['name']}")
        print(f"  expected: {' '.join(case['expected'].split())}")
        print(f"  actual:   {' '.join(completed.stdout.split())}")
        return False

    print(f"PASS {case['name']}")
    return True


def main() -> int:
    try:
        data = json.loads(MANIFEST.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError) as exc:
        print(f"Could not read {MANIFEST}: {exc}", file=sys.stderr)
        return 2

    compiler = shlex.split(os.environ.get("CXX", "g++"))
    if not compiler:
        print("CXX must name a C++ compiler.", file=sys.stderr)
        return 2

    passed = failed = 0
    with tempfile.TemporaryDirectory(prefix="cp-regression-") as temp:
        for case in data.get("cases", []):
            if run_case(case, compiler, data.get("compiler_standard", "c++17"), Path(temp)):
                passed += 1
            else:
                failed += 1

    print(f"\nSummary: {passed} passed, {failed} failed")
    return 0 if failed == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
