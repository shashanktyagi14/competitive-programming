#!/usr/bin/env python3
"""Generate docs/INDEX.md from the CFPusher topic tables in README.md."""

from __future__ import annotations

import re
from collections import defaultdict
from pathlib import Path
from urllib.parse import unquote

ROOT = Path(__file__).resolve().parents[1]
README = ROOT / "README.md"
OUTPUT = ROOT / "docs" / "INDEX.md"
ROW = re.compile(
    r"^\|\s*([^|]+?)\s*\|\s*\[([^]]+)\]\((https://codeforces\.com/contest/\d+/problem/[A-Z0-9]+)\)"
    r"\s*\|\s*([^|]+?)\s*\|\s*\[[^]]+\]\((https://github\.com/[^)]+/blob/HEAD/[^)]+)\)\s*\|\s*$"
)


def main() -> None:
    text = README.read_text(encoding="utf-8")
    section = "Uncategorized"
    entries: dict[str, dict[str, dict[str, str]]] = defaultdict(dict)

    for line in text.splitlines():
        if line.startswith("### "):
            section = line[4:].strip()
            continue
        match = ROW.match(line)
        if not match:
            continue
        problem_id, title, problem_url, difficulty, source_url = match.groups()
        contest = problem_url.split("/")[4]
        source_path = unquote(source_url.split("/blob/HEAD/", 1)[1])
        item = entries[contest].setdefault(problem_id, {
            "title": title,
            "problem_url": problem_url,
            "difficulty": difficulty.strip(),
            "source_path": source_path,
            "topics": "",
        })
        topics = [topic for topic in item["topics"].split(", ") if topic]
        if section != "Uncategorized" and section not in topics:
            topics.append(section)
        item["topics"] = ", ".join(topics)

    lines = [
        "# Contest-wise Index",
        "",
        "Generated from the topic tables in the root CFPusher README. The root README remains the canonical topic-wise index.",
        "",
    ]
    for contest in sorted(entries, key=int, reverse=True):
        lines.extend([
            f"## Codeforces Round {contest}",
            "",
            "| Problem | Difficulty | Topics | Solution |",
            "|---|---:|---|---|",
        ])
        for problem_id in sorted(entries[contest], key=lambda value: (int(re.match(r"\d+", value).group()), value)):
            item = entries[contest][problem_id]
            source = "../" + item["source_path"].replace(" ", "%20")
            topics = item["topics"] or "Uncategorized"
            lines.append(
                f"| [{problem_id} — {item['title']}]({item['problem_url']}) | "
                f"{item['difficulty']} | {topics} | [C++](<{source}>) |"
            )
        lines.append("")

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text("\n".join(lines), encoding="utf-8")
    print(f"Wrote {OUTPUT.relative_to(ROOT)} with {sum(map(len, entries.values()))} problems.")


if __name__ == "__main__":
    main()
