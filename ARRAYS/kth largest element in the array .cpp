/*

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

*/
/*
1. Idea (Quick Select)
// Instead of sorting the full array (O(n log n)), we:
// Pick a pivot element.
// Partition the array so:
// Elements greater than pivot are on one side.
// Elements smaller than pivot are on the other side.
// Check pivot position:
// If pivot is at index k-1 → Answer found.
// If pivot index > k-1 → Search left side.
// Else → Search right side.
*/

// 2. Using a Min Heap of size k:

// Keep only k largest elements.

// Top of heap = kth largest.

// Time complexity → O(n log k)

// | Approach     | Time       | When to Use         |
// | ------------ | ---------- | ------------------- |
// | Quick Select | O(n) avg   | Best overall        |
// | Min Heap     | O(n log k) | When k is small     |
// | Sorting      | O(n log n) | Simplest but slower |


