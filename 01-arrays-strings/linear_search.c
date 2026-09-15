/*
 * Problem: Linear Search
 * Source:  Chapter 2 example (also LeetCode-style warm-up)
 * Approach: Examine each element sequentially from index 0 until the
 *           target is found or the end of the array is reached.
 * Time Complexity:
 *   Best case:    O(1)  — target is the first element
 *   Average case: O(n)  — target is around the middle
 *   Worst case:   O(n)  — target is the last element, or not present
 * Space Complexity: O(1) — no extra memory beyond a few variables
 *
 * Works on UNSORTED data, unlike binary search.
 */

#include <stdio.h>

/*
 * Returns the index of `target` in `arr`, or -1 if not found.
 */
int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // found — return position immediately
        }
    }
    return -1; // not found after checking every element
}

int main(void) {
    int arr[] = {12, 7, 29, 18, 5, 41};
    int n = sizeof(arr) / sizeof(arr[0]);

    int targets[] = {29, 100, 12};
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    for (int t = 0; t < numTargets; t++) {
        int result = linearSearch(arr, n, targets[t]);
        if (result != -1) {
            printf("Value %d found at index %d\n", targets[t], result);
        } else {
            printf("Value %d not found in the array\n", targets[t]);
        }
    }

    return 0;
}
