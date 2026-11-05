# Common competitive-programming patterns

## Fenwick Tree (Binary Indexed Tree)

A Fenwick tree is a compact data structure for fast cumulative operations.
It is especially useful when we need:

- point updates
- prefix sum queries
- range sum queries

### Core idea

The tree stores partial sums in a way that makes each operation run in O(log n).
Instead of maintaining a full segment tree, we keep a compact array where each index
stores the sum of a range determined by its lowest set bit.

### Operations

- `add(i, delta)`: add `delta` to position `i`
- `prefix_sum(i)`: sum of values in `[1..i]`
- `range_sum(l, r)`: sum of values in `[l..r]`

### Complexity

- point update: O(log n)
- prefix sum query: O(log n)
- range sum query: O(log n)
- memory: O(n)

### Typical uses

- frequency arrays
- prefix-sum problems
- counting inversions
- range-add / point-query style tasks
- offline optimization with repeated updates

### Example

The reference implementation in `data_structures/fenwick_tree.cpp` demonstrates how to:

1. build the tree from an array,
2. update a point,
3. query prefix sums,
4. compute range sums.

This pattern is a standard building block in many competitive-programming solutions.
