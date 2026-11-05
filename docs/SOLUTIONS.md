# Selected Solution Notes

These notes explain the reasoning behind existing submissions in this repository. Source files remain in their original contest folders.

## Codeforces 2283A — Numbers on the Board

[Problem](https://codeforces.com/contest/2283/problem/A) · [Source](../2283/A%20-%20Numbers%20on%20the%20Board/solution.cpp)

If the interval [l,r] does not contain zero, all available values have the same sign. A retained number can equal the sum of all retained numbers only when it is the sole remaining value. Keeping one value is always possible, so the answer is r-l.

When the interval contains zero, let p=l+r. The answer is max(0, |p|-1).

The idea is to remove values from the longer side until the remaining interval's endpoint sum is either 0, 1, or -1. In those cases, the total sum of the remaining consecutive interval is itself one of its elements (zero when the endpoints sum to zero). The required number of removed elements is exactly the amount by which |l+r| exceeds one.

- **Time:** O(1) per test case
- **Extra space:** O(1)

## Codeforces 2283E — Partition of a Binary String

[Problem](https://codeforces.com/contest/2283/problem/E) · [Source](../2283/E%20-%20Partition%20of%20a%20Binary%20String/solution.cpp)

Split the string into maximal alternating runs. A valid set containing both binary characters can only be a pair of adjacent positions or three consecutive positions of the form 010 / 101: every opposite-colour pair in the set must be adjacent. Hence a run of length at least two can be partitioned optimally into mixed sets of size two or three.

Let dp[i] count the ways to tile an alternating run of length i with blocks of size two and three:

```
dp[0] = 1, dp[1] = 0
dp[i] = dp[i-2] + dp[i-3]
```

where the second term is omitted for i < 3. Every position in such a run contributes two to the maximum cost.

A maximal alternating run of length one is a position that cannot participate in a mixed set in an optimal partition. All such positions can be grouped arbitrarily with positions of the same character. If their counts are c0 and c1, the number of ways to partition them is B(c0) * B(c1), where B(j) is the j-th Bell number.

Therefore the maximum cost is 2n-c0-c1, and the number of optimal partitions is the product of the run tiling counts and the two Bell numbers, modulo 998244353.

- **Per test case:** O(n)
- **Precomputation:** O(N^2) time and O(N) space for N=5000

## Codeforces 2283F — Minimize the Graph

[Problem](https://codeforces.com/contest/2283/problem/F) · [Source](../2283/F%20-%20Minimize%20the%20Graph/solution.cpp)

The graph is a DAG because every edge goes from a smaller vertex index to a larger one. Its minimum equivalent graph is its transitive reduction: an original edge x -> i is retained exactly when no path of two or more edges can replace it.

For each vertex x, define nxt[x] as the smallest vertex y>x whose incoming interval contains x, or n+1 if there is no such vertex. A DSU-on-next structure assigns this first interval endpoint while scanning vertices in increasing order; each position is assigned once.

Consider an original edge x -> i, where x is in [l[i],r[i]]. It is redundant precisely when nxt[x] <= r[i]: in that case x -> nxt[x] -> i is a valid two-edge path, because nxt[x] lies inside the interval [l[i],r[i]]. Conversely, any two-edge replacement would have an intermediate vertex in that interval, so the first such endpoint would also be at most r[i].

Thus, for every vertex i, count positions x in [l[i],r[i]] with nxt[x] > r[i]. Sort positions by decreasing nxt, sort interval queries by decreasing right endpoint, and activate qualifying positions in a Fenwick tree. The interval sum is the number of indispensable incoming edges.

- **Time:** O(n log n) per test case
- **Extra space:** O(n)
