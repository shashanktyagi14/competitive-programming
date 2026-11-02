# Competitive Programming

A curated collection of standalone C++23 reference solutions for common competitive-programming patterns. Each source file has its own `main()` and can be compiled independently.

## Compile

```bash
g++ -std=c++23 -O2 -pipe -static -s -o solution path/to/file.cpp
./solution
```

All graph vertices and array ranges are **1-indexed in input**, unless a file's description explicitly says otherwise. String-match positions and the linked-list cycle entry index are 0-indexed. Inputs are whitespace-separated.

## Arrays and hashing

| File | Task / input |
|---|---|
| `arrays/two_sum.cpp` | `n target`, then n values; print a 1-indexed pair or -1. |
| `arrays/maximum_subarray_sum.cpp` | `n`, then n values; print the maximum non-empty subarray sum. |
| `arrays/prefix_sum_queries.cpp` | `n q`, n values, then q range queries `l r`; print each range sum. |
| `arrays/range_addition.cpp` | `n q`, initial array, then q updates `l r x`; print the final array. |
| `arrays/subarray_sum_equals_k.cpp` | `n k`, then n values; count subarrays whose sum is k. |
| `arrays/longest_consecutive_sequence.cpp` | `n`, then n values; print the longest consecutive-value run length. |
| `arrays/rotate_array.cpp` | `n k`, then n values; rotate right by k positions. |
| `arrays/merge_intervals.cpp` | `n`, then n interval pairs; print their merged union. |
| `arrays/majority_element.cpp` | `n`, then n values; print a value occurring more than n/2 times, or -1. |
| `arrays/product_except_self.cpp` | `n`, then n values; print each position's product excluding itself. |

## Strings

| File | Task / input |
|---|---|
| `strings/valid_parentheses.cpp` | One bracket string; print YES or NO. |
| `strings/longest_unique_substring.cpp` | One token string; print the longest substring length with distinct characters. |
| `strings/group_anagrams.cpp` | `n`, then n lowercase words; print anagram groups. |
| `strings/kmp_search.cpp` | Text and pattern tokens; print the match count and 0-indexed match positions. |
| `strings/z_function.cpp` | One string; print its Z-array (z[0] is 0). |

## Binary search and ordering

| File | Task / input |
|---|---|
| `search/binary_search.cpp` | `n target`, then a sorted array; print the first 0-indexed match or -1. |
| `search/lower_upper_bound.cpp` | `n x`, then a sorted array; print 0-indexed lower and upper bounds. |
| `search/search_rotated_array.cpp` | `n target`, then a rotated strictly increasing array; print its 0-indexed position or -1. |
| `search/book_allocation.cpp` | `n k`, then non-negative page counts; minimize the maximum pages assigned to a student. |
| `search/integer_square_root.cpp` | One non-negative 64-bit integer; print its floor square root. |

## Mathematics and bit manipulation

| File | Task / input |
|---|---|
| `math/gcd_lcm.cpp` | Two positive integers; print gcd and lcm. |
| `math/sieve_of_eratosthenes.cpp` | n; print all primes not exceeding n. |
| `math/modular_exponentiation.cpp` | `a b mod` with b non-negative and mod positive; print a^b modulo mod. |
| `math/prime_factorization.cpp` | One positive integer; print its prime factors and exponents. |
| `math/nCr_mod.cpp` | `n r` with n < 1,000,000,007; print C(n,r) modulo 1,000,000,007. |
| `math/xor_prefix.cpp` | n; print XOR of all integers from 0 through n. |
| `arrays/two_sum_sorted.cpp` | `n target`, then a sorted array; print a 1-indexed pair or -1. |
| `arrays/three_sum.cpp` | `n`, then n values; print all unique triplets summing to zero. |
| `arrays/sliding_window_maximum.cpp` | `n k`, then n values; print each window maximum. |
| `arrays/next_greater_element.cpp` | `n`, then n values; print the next strictly greater value to each right, or -1. |
| `arrays/largest_rectangle_histogram.cpp` | `n`, then non-negative bar heights; print the largest rectangle area. |

## Linked lists and trees

| File | Task / input |
|---|---|
| `data_structures/linked_list_cycle.cpp` | `n`, n node values, then cycle-entry index (0-indexed; -1 means no cycle); detect a cycle. |
| `trees/level_order_traversal.cpp` | `n`, then n-1 undirected tree edges; print BFS levels from vertex 1. |
| `trees/validate_bst_preorder.cpp` | `n`, then a preorder sequence; determine whether it can represent a BST with distinct keys. |

## Graphs

| File | Task / input |
|---|---|
| `graphs/dijkstra.cpp` | `n m source`, then m undirected weighted edges; print shortest distances. |
| `graphs/bfs_shortest_path.cpp` | `n m source target`, then m undirected edges; print the shortest path length in edges. |
| `graphs/topological_sort.cpp` | `n m`, then m directed edges; print a topological order or IMPOSSIBLE. |
| `graphs/disjoint_set_union.cpp` | `n q`, then q operations: `1 u v` union, `2 u v` connectivity query. |
| `graphs/kruskal_mst.cpp` | `n m`, then m weighted undirected edges; print MST weight or -1 if disconnected. |
| `graphs/bipartite_check.cpp` | `n m`, then m undirected edges; print YES or NO. |
| `graphs/flood_fill.cpp` | `n m`, grid values, then 1-indexed start row, column and replacement color; print updated grid. |
| `graphs/grid_shortest_path.cpp` | `n m`, a . / # grid, then 1-indexed start and target cells; print shortest distance or -1. |

## Dynamic programming

| File | Task / input |
|---|---|
| `dp/knapsack_01.cpp` | `n capacity`, n weights, then n values; print maximum achievable value. |
| `dp/coin_change_minimum.cpp` | `n amount`, then n positive denominations; print minimum coins or -1. |
| `dp/longest_increasing_subsequence.cpp` | `n`, then n values; print the strict LIS length. |
| `dp/longest_common_subsequence.cpp` | Two token strings; print their LCS length. |
| `dp/edit_distance.cpp` | Two token strings; print Levenshtein edit distance. |
| `dp/matrix_chain_multiplication.cpp` | `n`, then n+1 dimensions; print minimum scalar multiplications. |
| `math/fibonacci_fast_doubling.cpp` | n (0 <= n <= 9e18); print F(n) modulo 1,000,000,007. |

## Notes

- These are educational reference implementations, not claims that every file was submitted to or accepted by a particular judge.
- Use the constraints from the target problem to choose integer types and memory limits; for example, some product and matrix-chain tasks may require wider arithmetic than 64-bit.
- The implementations favor standard input/output and common contest techniques over problem-specific judge classes.
