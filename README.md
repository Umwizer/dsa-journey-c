# dsa-journey-c

My personal Data Structures & Algorithms practice repo  implemented in C

Every solution is written by hand in C (no external DSA libraries) so that implementing the structure — not just calling it — is the point.

## How this repo is organized

| Folder | Topic | Status |
|---|---|---|
| `01-arrays-strings/` | Arrays, searching, string problems | 🟡 In progress |
| `02-linked-lists/` | Singly/doubly linked lists | ⬜ Not started |
| `03-stacks-queues/` | Stack & Queue ADTs | ⬜ Not started |
| `04-sorting/` | Bubble, selection, merge, quicksort | ⬜ Not started |
| `05-trees-graphs/` | Binary trees, BST, BFS/DFS | ⬜ Not started |
| `06-hashing/` | Hash tables, two pointers, sliding window | ⬜ Not started |
| `codewars/` | Codewars kata solutions (C) | ⬜ Not started |
| `leetcode/` | LeetCode solutions, mirrors LeetCode's own topic tags | ⬜ Not started |
| `notes/` | My own summaries of each course chapter | 🟡 In progress |

## File header convention

Every `.c` solution file starts with a comment block like this, so the repo doubles as a portfolio of *reasoning*, not just code:

```c
/*
 * Problem: Binary Search
 * Source:  https://leetcode.com/problems/binary-search/
 * Approach: Divide sorted range in half each step, compare against target.
 * Time Complexity:  O(log n)  — halves the search space every iteration
 * Space Complexity: O(1)      — iterative, no extra memory
 */
```

## How to compile and run any file

```bash
gcc -Wall -Wextra -std=c11 -o solution 01-arrays-strings/binary_search.c
./solution
```

`-Wall -Wextra` catches most beginner C mistakes (uninitialized variables, implicit casts, etc.) before they become runtime bugs — worth keeping on for every file in this repo.

## Progress log

- [x] Chapter 1 notes summarized
- [x] Chapter 2 notes summarized
- [x] Linear search implemented + analyzed
- [x] Binary search implemented + analyzed
- [ ] Singly linked list from scratch
- [ ] Stack (array-based) from scratch
- [ ] Queue (array-based) from scratch
- [ ] Bubble sort / merge sort / quicksort implemented + benchmarked
- [ ] First 20 LeetCode Easy problems solved in C
- [ ] First binary tree implementation

## Resources I'm using

- *Data Structures Using C* — Reema Thareja (primary textbook alongside course notes)
- [LeetCode Explore Cards](https://leetcode.com/explore/) — structured topic tracks
- [Codewars](https://www.codewars.com/) — C kata for language fluency
- [GeeksforGeeks — Data Structures in C](https://www.geeksforgeeks.org/dsa/c-data-structures/) — reference lookups
- [freeCodeCamp — Data Structures Full Course (C/C++)](https://www.youtube.com/watch?v=B31LgI4Y4DQ) — video walkthroughs

---
*Author: Ruth Umwizerwa*
