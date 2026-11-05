# Maximum MEX of Group Maximums

**Platform:** Unspecified practice problem  
**Language:** C++17  
**Status:** Derived from the problem statement; not an online-judge submission

## Problem

Given an array of n integers and a positive integer k, choose pairwise-disjoint groups. Every chosen group must contain at least k elements, and each array element can be used in at most one group. Maximize the MEX of the set of group maximums.

The implementation reads one instance: n, k, followed by the n array values.

## Observation

To obtain a MEX of at least m, the set of group maximums must contain every value 0, 1, ..., m-1.

For every x < m, one group must have maximum exactly x. Therefore:

1. The array must contain at least one occurrence of every value x in [0,m).
2. The groups whose maximums are 0, 1, ..., x contain at least k(x+1) elements in total. Every one of those elements is at most x.

Let P(x) be the number of array elements whose value is at most x, including negative values. The two necessary conditions are

- freq(x) > 0
- P(x) >= k(x+1)

They are also sufficient.

## Greedy construction argument

Process target maximums in increasing order. For the group whose maximum is x, reserve one unused occurrence of x, then take any other k-1 unused values that are at most x.

Earlier groups use exactly kx values, and all of them are at most x. Since P(x) >= k(x+1), at least k eligible unused values remain. An occurrence of x is still available because earlier groups only use values at most their own smaller maximums.

Thus each successful iteration extends a valid construction by one group. The first failed condition makes the next MEX value impossible.

## Complexity

Sorting takes O(n log n). The frequency construction and two-pointer prefix scan take O(n).

- **Time:** O(n log n)
- **Extra space:** O(n)

The multiplication in the prefix condition uses the 128-bit integer type to avoid overflow.

## Example

Input:

```text
8 2
-1 0 0 1 1 2 2 9
```

Output:

```text
3
```

One valid grouping is {-1,0}, {0,1}, and {1,2}, with maximums 0, 1, 2.
