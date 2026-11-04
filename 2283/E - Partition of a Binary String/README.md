<h2><a href="https://codeforces.com/contest/2283/problem/E" target="_blank" rel="noopener noreferrer">2283E — Partition of a Binary String</a></h2>

| | |
|---|---|
| **Difficulty** | Unrated |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2283E](https://codeforces.com/contest/2283/problem/E) |

## Topics
_No tags available_

---

## Problem Statement

<div class="header"><div class="title">E. Partition of a Binary String</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a binary string $$$s$$$ of length $$$n$$$. The characters of the string are numbered from $$$1$$$ to $$$n$$$.</p><p>You have to partition all integers from $$$1$$$ to $$$n$$$ into nonempty sets so that each integer belongs to exactly one set. For each pair of distinct integers $$$x$$$ and $$$y$$$ in the same set, at least one of the following conditions must hold: </p><ul> <li> $$$s_x = s_y$$$; </li><li> $$$|x-y| = 1$$$. </li></ul><p>For a set $$$M$$$, let $$$f(M)$$$ be the number of distinct characters among $$$s_x$$$ over all $$$x \in M$$$. The cost of the set $$$M$$$ is $$$|M| \cdot f(M)$$$, where $$$|M|$$$ is the number of elements in $$$M$$$. The cost of a partition is the sum of the costs of all its sets.</p><p>For example, if the string $$$s$$$ is <span class="tex-font-style-tt">10001000</span>, the partition into the sets $$$\{1, 2\}, \{3, 8\}, \{4, 5, 6\}, \{7\}$$$ is valid, and its cost is $$$2 \cdot 2 + 2 \cdot 1 + 3 \cdot 2 + 1 \cdot 1 = 13$$$.</p><p>Find the maximum possible cost of a partition and the number of partitions with this cost. Partitions that differ only in the order of the sets or the order of elements within the sets are considered the same. Output the number of partitions modulo $$$998\,244\,353$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \le t \le 500$$$) — the number of test cases.</p><p>The first line of each test case contains one integer $$$n$$$ ($$$1 \le n \le 5000$$$) — the length of the string.</p><p>The second line of each test case contains one string $$$s$$$ of length $$$n$$$, consisting only of the characters <span class="tex-font-style-tt">0</span> and <span class="tex-font-style-tt">1</span>.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, print two integers: the maximum cost of a partition and the number of partitions with this cost (taken modulo $$$998\,244\,353$$$).</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00853108656503338" id="id001549955929804656" class="input-output-copier">Copy</div></div><pre data-content="3
8
10001000
6
000111
8
01010101
" id="id00853108656503338"><div class="test-example-line test-example-line-even test-example-line-0">3</div><div class="test-example-line test-example-line-odd test-example-line-1">8</div><div class="test-example-line test-example-line-odd test-example-line-1">10001000</div><div class="test-example-line test-example-line-even test-example-line-2">6</div><div class="test-example-line test-example-line-even test-example-line-2">000111</div><div class="test-example-line test-example-line-odd test-example-line-3">8</div><div class="test-example-line test-example-line-odd test-example-line-3">01010101</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006350908144361086" id="id00017933783310591478" class="input-output-copier">Copy</div></div><pre data-content="13 5
8 4
16 4
" id="id006350908144361086"><div class="test-example-line test-example-line-odd test-example-line-1">13 5</div><div class="test-example-line test-example-line-even test-example-line-2">8 4</div><div class="test-example-line test-example-line-odd test-example-line-3">16 4</div></pre></div></div></div>