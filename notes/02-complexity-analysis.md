# Chapter 2 — Algorithm Analysis and Complexity

## Why analyze algorithms
- More than one algorithm usually solves the same problem — analysis lets us pick the best one *before* running code.
- Hardware-independent: focuses on growth rate, not seconds on a specific machine.

## Two resources measured
- **Time complexity** — how execution time grows with input size `n`.
- **Space complexity** — how memory usage grows with input size `n`.

## Classic example: Linear Search vs Binary Search (searching 1,000,000 sorted records)

| | Linear Search | Binary Search |
|---|---|---|
| Worst case | ~1,000,000 comparisons | ~20 comparisons |
| Notation | O(n) | O(log n) |
| Requires sorted data? | No | Yes |

## Time-Space trade-off
More memory (e.g. caching/memoization) can buy faster execution; less memory (recomputing) can cost execution time. The "best" algorithm balances both for the problem's actual constraints — there's rarely a single universally-best choice.

## Common time complexity classes (fastest → slowest growth)

| Notation | Name | Example |
|---|---|---|
| O(1) | Constant | Array index access `A[i]` |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search |
| O(n log n) | Linearithmic | Merge sort |
| O(n²) | Quadratic | Nested loops over same input |
| O(2ⁿ) | Exponential | Brute-force subset sum |

`O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ)`

## Best / Average / Worst case (using Linear Search as the example)

| Case | Meaning | Linear Search example | Complexity |
|---|---|---|---|
| Best | Most favorable input | Target is first element | O(1) |
| Average | Expected over all inputs | Target near the middle | O(n) |
| Worst | Least favorable input | Target is last / not present | O(n) |

**Worst-case dominates in practice** — it's the guarantee we design for.

## Asymptotic notations

- **Big-O, O(g(n))** — upper bound (worst case). `f(n) ≤ c·g(n)` for large n. Most commonly used.
- **Big-Omega, Ω(g(n))** — lower bound (best case). `f(n) ≥ c·g(n)`.
- **Big-Theta, Θ(g(n))** — tight bound (both). `c₁·g(n) ≤ f(n) ≤ c₂·g(n)`. Most precise, not always establishable.
  - Example: Merge sort is Θ(n log n) in *every* case (best, average, worst).

## Space complexity notes
- **Total space** = input space + auxiliary space (+ output, depending on convention).
- **Auxiliary space** (extra memory beyond input) is usually the more meaningful number to report.
- In-place algorithms (e.g. selection sort) → O(1) auxiliary space.
- Algorithms needing a temp buffer (e.g. merge sort) → O(n) auxiliary space.
- **Recursion adds to space cost** — each active call adds a stack frame; recursion depth ∝ n usually means O(n) auxiliary space (e.g. recursive factorial).

## Key takeaway
Differences between complexity classes look small for small `n`, but become dramatic as `n` grows — this is *why* asymptotic analysis matters more than "does it work on my test case."
