/*
 * Problem: Binary Search
 * Source:  Chapter 2 example / https://leetcode.com/problems/binary-search/
 * Approach: Repeatedly divide the search range in half, comparing the
 *           target against the middle element, discarding the half that
 *           cannot contain the target.
 * Time Complexity:
 *   Best case:    O(1)      — target is the middle element on first check
 *   Average case: O(log n)
 *   Worst case:   O(log n)  — target at an edge, or not present
 * Space Complexity: O(1) — iterative version, no extra memory
 *
 * REQUIRES the array to be sorted (ascending). That's the trade-off
 * against linear search: O(log n) instead of O(n), but only works
 * when the data structure guarantees sorted order.
 */

#include <stdio.h>

/*
 * Returns the index of `target` in sorted array `arr`, or -1 if not found.
 */
int binarySearch(const int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // avoids potential overflow of (left+right)/2

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;  // target must be in the right half
        } else {
            right = mid - 1; // target must be in the left half
        }
    }

    return -1; // search space exhausted, not found
}

int main(void) {
    // Must be sorted for binary search to work correctly.
    int arr[] = {5, 12, 18, 25, 29, 32, 37, 41, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    int targets[] = {29, 100, 5};
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    for (int t = 0; t < numTargets; t++) {
        int result = binarySearch(arr, n, targets[t]);
        if (result != -1) {
            printf("Value %d found at index %d\n", targets[t], result);
        } else {
            printf("Value %d not found in the array\n", targets[t]);
        }
    }

    return 0;
}
