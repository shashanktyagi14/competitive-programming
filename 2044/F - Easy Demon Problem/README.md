<h2><a href="https://codeforces.com/contest/2044/problem/F" target="_blank" rel="noopener noreferrer">2044F — Easy Demon Problem</a></h2>

| | |
|---|---|
| **Difficulty** | 1900 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2044F](https://codeforces.com/contest/2044/problem/F) |

## Topics
`binary search` `brute force` `data structures` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">F. Easy Demon Problem</div><div class="time-limit"><div class="property-title">time limit per test</div>4 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>For an arbitrary grid, Robot defines its <span class="tex-font-style-it">beauty</span> to be the sum of elements in the grid. </p><p>Robot gives you an array $$$a$$$ of length $$$n$$$ and an array $$$b$$$ of length $$$m$$$. You construct a $$$n$$$ by $$$m$$$ grid $$$M$$$ such that $$$M_{i,j}=a_i\cdot b_j$$$ for all $$$1 \leq i \leq n$$$ and $$$1 \leq j \leq m$$$.</p><p>Then, Robot gives you $$$q$$$ queries, each consisting of a single integer $$$x$$$. For each query, determine whether or not it is possible to perform the following operation <span class="tex-font-style-bf">exactly</span> once so that $$$M$$$ has a <span class="tex-font-style-it">beauty</span> of $$$x$$$:</p><ol> <li> Choose integers $$$r$$$ and $$$c$$$ such that $$$1 \leq r \leq n$$$ and $$$1 \leq c \leq m$$$ </li><li> Set $$$M_{i,j}$$$ to be $$$0$$$ for all ordered pairs $$$(i,j)$$$ such that $$$i=r$$$, $$$j=c$$$, or both. </li></ol><p>Note that queries are <span class="tex-font-style-bf">not persistent</span>, meaning that you do not actually set any elements to $$$0$$$ in the process — you are only required to output if it is possible to find $$$r$$$ and $$$c$$$ such that if the above operation is performed, the <span class="tex-font-style-it">beauty</span> of the grid will be $$$x$$$. Also, note that you must perform the operation for each query, even if the beauty of the original grid is already $$$x$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains three integers $$$n$$$, $$$m$$$, and $$$q$$$ ($$$1 \leq n,m \leq 2\cdot 10^5, 1 \leq q \leq 5\cdot 10^4$$$) — the length of $$$a$$$, the length of $$$b$$$, and the number of queries respectively.</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$0 \leq |a_i| \leq n$$$).</p><p>The third line contains $$$m$$$ integers $$$b_1, b_2, \ldots, b_m$$$ ($$$0 \leq |b_i| \leq m$$$).</p><p>The following $$$q$$$ lines each contain a single integer $$$x$$$ ($$$1 \leq |x| \leq 2\cdot 10^5$$$), the beauty of the grid you wish to achieve by setting all elements in a row and a column to $$$0$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each testcase, output "<span class="tex-font-style-tt">YES</span>" (without quotes) if there is a way to perform the aforementioned operation such that the beauty is $$$x$$$, and "<span class="tex-font-style-tt">NO</span>" (without quotes) otherwise.</p><p>You can output "<span class="tex-font-style-tt">YES</span>" and "<span class="tex-font-style-tt">NO</span>" in any case (for example, strings "<span class="tex-font-style-tt">yES</span>", "<span class="tex-font-style-tt">yes</span>" and "<span class="tex-font-style-tt">Yes</span>" will be recognized as a positive response).</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002122579961096699" id="id00057827668948976174" class="input-output-copier">Copy</div></div><pre data-content="3 3 6
-2 3 -3
-2 2 -1
-1
1
-2
2
-3
3
" id="id002122579961096699"><div class="test-example-line test-example-line-odd test-example-line-1">3 3 6</div><div class="test-example-line test-example-line-odd test-example-line-1">-2 3 -3</div><div class="test-example-line test-example-line-odd test-example-line-1">-2 2 -1</div><div class="test-example-line test-example-line-odd test-example-line-1">-1</div><div class="test-example-line test-example-line-odd test-example-line-1">1</div><div class="test-example-line test-example-line-odd test-example-line-1">-2</div><div class="test-example-line test-example-line-odd test-example-line-1">2</div><div class="test-example-line test-example-line-odd test-example-line-1">-3</div><div class="test-example-line test-example-line-odd test-example-line-1">3</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id007193857287897321" id="id005576762514577277" class="input-output-copier">Copy</div></div><pre id="id007193857287897321">NO
YES
NO
NO
YES
NO
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00700255447901546" id="id006068984731430891" class="input-output-copier">Copy</div></div><pre data-content="5 5 6
1 -2 3 0 0
0 -2 5 0 -3
4
-3
5
2
-1
2
" id="id00700255447901546"><div class="test-example-line test-example-line-odd test-example-line-1">5 5 6</div><div class="test-example-line test-example-line-odd test-example-line-1">1 -2 3 0 0</div><div class="test-example-line test-example-line-odd test-example-line-1">0 -2 5 0 -3</div><div class="test-example-line test-example-line-odd test-example-line-1">4</div><div class="test-example-line test-example-line-odd test-example-line-1">-3</div><div class="test-example-line test-example-line-odd test-example-line-1">5</div><div class="test-example-line test-example-line-odd test-example-line-1">2</div><div class="test-example-line test-example-line-odd test-example-line-1">-1</div><div class="test-example-line test-example-line-odd test-example-line-1">2</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004230878057689168" id="id002723914225072325" class="input-output-copier">Copy</div></div><pre id="id004230878057689168">YES
YES
YES
YES
NO
YES
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the second example, the grid is</p><p> <span class="tex-font-style-tt">0 -2 5 0 -3</span></p><p><span class="tex-font-style-tt">0 4 -10 0 6</span></p><p><span class="tex-font-style-tt">0 -6 15 0 -9</span></p><p><span class="tex-font-style-tt">0 0 0 0 0</span></p><p><span class="tex-font-style-tt">0 0 0 0 0</span></p><p>By performing the operation with $$$r=4$$$ and $$$c=2$$$, we create the following grid:</p><p><span class="tex-font-style-tt">0 0 5 0 -3</span></p><p><span class="tex-font-style-tt">0 0 -10 0 6</span></p><p><span class="tex-font-style-tt">0 0 15 0 -9</span></p><p><span class="tex-font-style-tt">0 0 0 0 0</span></p><p><span class="tex-font-style-tt">0 0 0 0 0</span></p><p>which has <span class="tex-font-style-it">beauty</span> $$$4$$$. Thus, we output <span class="tex-font-style-tt">YES</span>.</p><p>In the second query, selecting $$$r=3$$$ and $$$c=5$$$ creates a grid with <span class="tex-font-style-it">beauty</span> $$$-3$$$.</p><p>In the third query, selecting $$$r=3$$$ and $$$c=3$$$ creates a grid with <span class="tex-font-style-it">beauty</span> $$$5$$$.</p></div>