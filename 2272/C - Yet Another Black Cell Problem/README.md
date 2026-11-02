<h2><a href="https://codeforces.com/contest/2272/problem/C" target="_blank" rel="noopener noreferrer">2272C — Yet Another Black Cell Problem</a></h2>

| | |
|---|---|
| **Difficulty** | Unrated |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2272C](https://codeforces.com/contest/2272/problem/C) |

## Topics
`binary search` `constructive algorithms` `dp` `greedy`

---

## Problem Statement

<div class="header"><div class="title">C. Yet Another Black Cell Problem</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p> </p><p><span class="tex-font-style-it">Inspired by <a href="https://codeforces.com/contest/2026/problem/B">this problem</a>.</span></p><p>There is a strip divided into cells numbered from $$$0$$$ to $$$10^9$$$ from left to right. Initially, all cells are white.</p><p>An array $$$a$$$ of length $$$n$$$ is given, containing the indices of $$$n$$$ cells. We want to paint all these $$$n$$$ cells black.</p><p>Given an integer $$$x$$$, you may choose an integer $$$y$$$ such that $$$0 \le y \le x$$$, and then arbitrarily select $$$y$$$ cells that are <span class="tex-font-style-bf">not in</span> $$$a$$$. We also want to paint these selected $$$y$$$ cells black while keeping all non-selected cells white.</p><p>You may perform the following operation any number of times:</p><ul> <li> Choose two distinct cells $$$i$$$ and $$$j$$$ such that $$$1 \le |i-j| \le k$$$, and paint them black, regardless of whether they were originally black or white. </li></ul><p>Find the minimum value of $$$k$$$ for which it is possible to paint all the required cells black while keeping other cells white.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows.</p><p>The first line of each test case contains two integers $$$n$$$ and $$$x$$$ ($$$2\leq n\leq 2\cdot 10^5,0\leq x\leq n$$$).</p><p>The second line contains $$$n$$$ integers $$$a_1,a_2,\ldots,a_n$$$ ($$$0\leq a_i\leq 10^{9}$$$). It is guaranteed that $$$a_i \lt a_{i+1}$$$ for all $$$1 \leq i  \lt  n$$$.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$2\cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, print a single integer — the minimum value of $$$k$$$ for which it is possible to paint all the required cells black while keeping other cells white.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0014618532437492904" id="id007670522622927035" class="input-output-copier">Copy</div></div><pre data-content="4
2 0
1 3
2 1
1 3
3 1
2 5 7
10 2
0 6 8 10 13 14 16 19 25 31
" id="id0014618532437492904"><div class="test-example-line test-example-line-even test-example-line-0">4</div><div class="test-example-line test-example-line-odd test-example-line-1">2 0</div><div class="test-example-line test-example-line-odd test-example-line-1">1 3</div><div class="test-example-line test-example-line-even test-example-line-2">2 1</div><div class="test-example-line test-example-line-even test-example-line-2">1 3</div><div class="test-example-line test-example-line-odd test-example-line-3">3 1</div><div class="test-example-line test-example-line-odd test-example-line-3">2 5 7</div><div class="test-example-line test-example-line-even test-example-line-4">10 2</div><div class="test-example-line test-example-line-even test-example-line-4">0 6 8 10 13 14 16 19 25 31</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0026766034603655675" id="id002606278772788674" class="input-output-copier">Copy</div></div><pre data-content="2
1
2
3
" id="id0026766034603655675"><div class="test-example-line test-example-line-odd test-example-line-1">2</div><div class="test-example-line test-example-line-even test-example-line-2">1</div><div class="test-example-line test-example-line-odd test-example-line-3">2</div><div class="test-example-line test-example-line-even test-example-line-4">3</div></pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, we cannot paint any cell other than $$$1$$$ and $$$3$$$ black because $$$x=0$$$. So it's optimal to set $$$k=2$$$ and choose $$$i=1,j=3$$$ in the first operation.</p><p>In the second example, we can set $$$k=1$$$, which is the minimal available value. We first choose $$$i=1,j=2$$$ to paint and then choose $$$i=2,j=3$$$ to paint. After that, cells $$$1,2,3$$$ are painted black, only cell $$$2$$$ is not in the given list, which satisfies the condition $$$x=1$$$.</p></div>