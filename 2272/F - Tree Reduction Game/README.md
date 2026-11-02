<h2><a href="https://codeforces.com/contest/2272/problem/F" target="_blank" rel="noopener noreferrer">2272F — Tree Reduction Game</a></h2>

| | |
|---|---|
| **Difficulty** | Unrated |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2272F](https://codeforces.com/contest/2272/problem/F) |

## Topics
`dfs and similar` `dp` `games` `trees`

---

## Problem Statement

<div class="header"><div class="title">F. Tree Reduction Game</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p> </p><p>Alice and Bob are playing a game on a tree with $$$n$$$ vertices. Alice moves first, and then they take turns.</p><p>At any moment, the tree has a designated root. Suppose the current root is $$$u$$$. On their turn, the current player must choose a child $$$v$$$ of $$$u$$$ and perform exactly one of the following operations:</p><ol> <li> Make $$$v$$$ the new root. </li><li> Delete the entire subtree$$$^{\text{∗}}$$$ rooted at $$$v$$$. </li></ol><p>Here, parent-child relationships are determined with respect to the current root.</p><p>During the entire game, each vertex can become the root <span class="tex-font-style-bf">at most once</span>.</p><p>If a player has no valid move on their turn, that player loses.</p><p>Before the game begins, as compensation for moving second, Bob may choose any vertex as the initial root.</p><p>Given the tree, determine the winner assuming both players play optimally. If Bob can win, output all vertices that he can choose as the initial root to guarantee a victory, <span class="tex-font-style-bf">in increasing order</span>.</p><div class="statement-footnote"><p>$$$^{\text{∗}}$$$The subtree rooted at vertex $$$v$$$ is the set of all vertices that pass through $$$v$$$ on a simple path to the root (including $$$v$$$ itself).</p></div></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows.</p><p>The first line of each test case contains a single integer $$$n$$$ ($$$2 \le n \le 5 \cdot 10^5$$$), the number of vertices in the tree.</p><p>Each of the next $$$n-1$$$ lines contains two integers $$$u$$$ and $$$v$$$ ($$$1 \le u,v \le n$$$, $$$u \ne v$$$), denoting an edge between vertices $$$u$$$ and $$$v$$$. It is guaranteed that the given graph is a tree.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$5 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><ul><li> If Alice wins, print <span class="tex-font-style-tt">Alice</span>.</li><li> Otherwise, print <span class="tex-font-style-tt">Bob</span> on the first line. On the second line, print an integer $$$k$$$, the number of vertices that Bob can choose as the initial root to guarantee his victory. On the third line, print $$$k$$$ distinct integers $$$v_1,v_2,\ldots,v_k$$$ <span class="tex-font-style-bf">in increasing order</span>, denoting all such vertices.</li></ul></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009086428034687114" id="id003671485237345157" class="input-output-copier">Copy</div></div><pre data-content="6
2
1 2
3
1 2
2 3
5
1 2
1 3
1 4
1 5
5
1 2
2 3
3 4
4 5
7
1 2
2 3
1 4
4 5
1 6
6 7
7
1 2
1 3
2 4
2 5
3 6
3 7
" id="id009086428034687114"><div class="test-example-line test-example-line-even test-example-line-0">6</div><div class="test-example-line test-example-line-odd test-example-line-1">2</div><div class="test-example-line test-example-line-odd test-example-line-1">1 2</div><div class="test-example-line test-example-line-even test-example-line-2">3</div><div class="test-example-line test-example-line-even test-example-line-2">1 2</div><div class="test-example-line test-example-line-even test-example-line-2">2 3</div><div class="test-example-line test-example-line-odd test-example-line-3">5</div><div class="test-example-line test-example-line-odd test-example-line-3">1 2</div><div class="test-example-line test-example-line-odd test-example-line-3">1 3</div><div class="test-example-line test-example-line-odd test-example-line-3">1 4</div><div class="test-example-line test-example-line-odd test-example-line-3">1 5</div><div class="test-example-line test-example-line-even test-example-line-4">5</div><div class="test-example-line test-example-line-even test-example-line-4">1 2</div><div class="test-example-line test-example-line-even test-example-line-4">2 3</div><div class="test-example-line test-example-line-even test-example-line-4">3 4</div><div class="test-example-line test-example-line-even test-example-line-4">4 5</div><div class="test-example-line test-example-line-odd test-example-line-5">7</div><div class="test-example-line test-example-line-odd test-example-line-5">1 2</div><div class="test-example-line test-example-line-odd test-example-line-5">2 3</div><div class="test-example-line test-example-line-odd test-example-line-5">1 4</div><div class="test-example-line test-example-line-odd test-example-line-5">4 5</div><div class="test-example-line test-example-line-odd test-example-line-5">1 6</div><div class="test-example-line test-example-line-odd test-example-line-5">6 7</div><div class="test-example-line test-example-line-even test-example-line-6">7</div><div class="test-example-line test-example-line-even test-example-line-6">1 2</div><div class="test-example-line test-example-line-even test-example-line-6">1 3</div><div class="test-example-line test-example-line-even test-example-line-6">2 4</div><div class="test-example-line test-example-line-even test-example-line-6">2 5</div><div class="test-example-line test-example-line-even test-example-line-6">3 6</div><div class="test-example-line test-example-line-even test-example-line-6">3 7</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id002463212223417227" id="id008426218417975695" class="input-output-copier">Copy</div></div><pre data-content="Alice
Bob
1
2
Bob
1
1
Bob
2
2 4
Bob
3
2 4 6
Bob
1
1
" id="id002463212223417227"><div class="test-example-line test-example-line-odd test-example-line-1">Alice</div><div class="test-example-line test-example-line-even test-example-line-2">Bob</div><div class="test-example-line test-example-line-even test-example-line-2">1</div><div class="test-example-line test-example-line-even test-example-line-2">2</div><div class="test-example-line test-example-line-odd test-example-line-3">Bob</div><div class="test-example-line test-example-line-odd test-example-line-3">1</div><div class="test-example-line test-example-line-odd test-example-line-3">1</div><div class="test-example-line test-example-line-even test-example-line-4">Bob</div><div class="test-example-line test-example-line-even test-example-line-4">2</div><div class="test-example-line test-example-line-even test-example-line-4">2 4</div><div class="test-example-line test-example-line-odd test-example-line-5">Bob</div><div class="test-example-line test-example-line-odd test-example-line-5">3</div><div class="test-example-line test-example-line-odd test-example-line-5">2 4 6</div><div class="test-example-line test-example-line-even test-example-line-6">Bob</div><div class="test-example-line test-example-line-even test-example-line-6">1</div><div class="test-example-line test-example-line-even test-example-line-6">1</div></pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, regardless of which vertex Bob chooses as the initial root, Alice can remove the only child subtree on her first move. Bob then has no legal move, so Alice wins.</p><p>In the fifth test case, vertices $$$2$$$, $$$4$$$, and $$$6$$$ are winning choices for Bob. We explain vertex $$$2$$$; the other two cases are symmetric.</p><p>If Bob chooses vertex $$$2$$$ as the initial root, its children are $$$1$$$ and $$$3$$$.</p><ul> <li> If Alice changes the root from $$$2$$$ to $$$1$$$, Bob can change the root from $$$1$$$ to $$$4$$$ (or $$$6$$$). </li><li> If Alice deletes the subtree rooted at $$$1$$$, Bob deletes the subtree rooted at $$$3$$$, leaving Alice with no legal move. </li><li> If Alice changes the root from $$$2$$$ to $$$3$$$, Bob deletes the subtree rooted at $$$2$$$, again leaving Alice with no legal move. </li><li> If Alice deletes the subtree rooted at $$$3$$$, Bob deletes the subtree rooted at $$$1$$$. </li></ul><p>Thus Bob can force a win when the initial root is $$$2$$$. By symmetry, the same holds for $$$4$$$ and $$$6$$$. If Bob chooses any of $$$1$$$, $$$3$$$, $$$5$$$, or $$$7$$$, Alice has a winning strategy. Therefore the answer is $$$2,4,6$$$.</p></div>