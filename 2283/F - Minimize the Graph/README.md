<h2><a href="https://codeforces.com/contest/2283/problem/F" target="_blank" rel="noopener noreferrer">2283F — Minimize the Graph</a></h2>

| | |
|---|---|
| **Difficulty** | Unrated |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2283F](https://codeforces.com/contest/2283/problem/F) |

## Topics
_No tags available_

---

## Problem Statement

<div class="header"><div class="title">F. Minimize the Graph</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a directed graph with $$$n$$$ vertices, numbered from $$$1$$$ to $$$n$$$. The graph is constructed as follows: for each vertex $$$i$$$ from $$$2$$$ to $$$n$$$, you are given two integers $$$l_i$$$ and $$$r_i$$$ ($$$1 \le l_i \le r_i  \lt  i$$$). For each integer $$$j \in [l_i, r_i]$$$, the graph contains a directed edge from $$$j$$$ to $$$i$$$. There are no other edges in the graph.</p><p>Consider a second directed graph on the same $$$n$$$ vertices. For any two distinct vertices $$$x$$$ and $$$y$$$, a path from $$$x$$$ to $$$y$$$ must exist in the second graph if and only if it exists in the first graph.</p><p>Find the minimum possible number of edges in the second graph.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases.</p><p>The first line of each test case contains one integer $$$n$$$ ($$$2 \le n \le 3 \cdot 10^5$$$) — the number of vertices.</p><p>The next $$$n-1$$$ lines describe the edges of the graph. The $$$i$$$-th of these lines contains two integers $$$l_{i+1}$$$ and $$$r_{i+1}$$$ ($$$1 \le l_{i+1} \le r_{i+1} \le i$$$).</p><p>Additional constraints on the input:</p><ul> <li> the sum of $$$n$$$ over all test cases does not exceed $$$3 \cdot 10^5$$$. </li></ul></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, print one integer — the minimum possible number of edges in the second graph.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005394266853057655" id="id009669321569533272" class="input-output-copier">Copy</div></div><pre data-content="5
5
1 1
1 2
2 3
2 4
6
1 1
1 1
2 3
2 3
4 5
5
1 1
1 2
1 3
1 4
6
1 1
1 1
1 1
2 4
2 4
6
1 1
1 2
1 1
2 4
3 5
" id="id005394266853057655"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-odd test-example-line-1">1 1</div><div class="test-example-line test-example-line-odd test-example-line-1">1 2</div><div class="test-example-line test-example-line-odd test-example-line-1">2 3</div><div class="test-example-line test-example-line-odd test-example-line-1">2 4</div><div class="test-example-line test-example-line-even test-example-line-2">6</div><div class="test-example-line test-example-line-even test-example-line-2">1 1</div><div class="test-example-line test-example-line-even test-example-line-2">1 1</div><div class="test-example-line test-example-line-even test-example-line-2">2 3</div><div class="test-example-line test-example-line-even test-example-line-2">2 3</div><div class="test-example-line test-example-line-even test-example-line-2">4 5</div><div class="test-example-line test-example-line-odd test-example-line-3">5</div><div class="test-example-line test-example-line-odd test-example-line-3">1 1</div><div class="test-example-line test-example-line-odd test-example-line-3">1 2</div><div class="test-example-line test-example-line-odd test-example-line-3">1 3</div><div class="test-example-line test-example-line-odd test-example-line-3">1 4</div><div class="test-example-line test-example-line-even test-example-line-4">6</div><div class="test-example-line test-example-line-even test-example-line-4">1 1</div><div class="test-example-line test-example-line-even test-example-line-4">1 1</div><div class="test-example-line test-example-line-even test-example-line-4">1 1</div><div class="test-example-line test-example-line-even test-example-line-4">2 4</div><div class="test-example-line test-example-line-even test-example-line-4">2 4</div><div class="test-example-line test-example-line-odd test-example-line-5">6</div><div class="test-example-line test-example-line-odd test-example-line-5">1 1</div><div class="test-example-line test-example-line-odd test-example-line-5">1 2</div><div class="test-example-line test-example-line-odd test-example-line-5">1 1</div><div class="test-example-line test-example-line-odd test-example-line-5">2 4</div><div class="test-example-line test-example-line-odd test-example-line-5">3 5</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0040409150912093716" id="id0035843295932410335" class="input-output-copier">Copy</div></div><pre data-content="4
8
4
9
6
" id="id0040409150912093716"><div class="test-example-line test-example-line-odd test-example-line-1">4</div><div class="test-example-line test-example-line-even test-example-line-2">8</div><div class="test-example-line test-example-line-odd test-example-line-3">4</div><div class="test-example-line test-example-line-even test-example-line-4">9</div><div class="test-example-line test-example-line-odd test-example-line-5">6</div></pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, you can add the edges $$$1 \to 2$$$, $$$2 \to 3$$$, $$$3 \to 4$$$, and $$$4 \to 5$$$ to the second graph.</p><p>In the second test case, you can add the edges $$$1 \to 2$$$, $$$1 \to 3$$$, $$$2 \to 4$$$, $$$3 \to 4$$$, $$$2 \to 5$$$, $$$3 \to 5$$$, $$$4 \to 6$$$, and $$$5 \to 6$$$ to the second graph.</p></div>