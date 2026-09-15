# Chapter 1 — Introduction to Data Structures and Algorithms

## Core idea
Every program = **Data** (held, organized) + **Algorithms** (operate on it).
> "Algorithms + Data Structures = Programs" — Niklaus Wirth, 1976

- **Data structure**: how data is organized, stored, accessed for a *given purpose*.
- **Algorithm**: finite, well-defined sequence of steps that turns input into output.
- They're interdependent — the right algorithm depends on the data structure it runs on (e.g. binary search only works efficiently on a **sorted array**, not a linked list or unsorted data).

## Classification of data structures (3 independent dimensions)

**1. Primitive vs Non-Primitive**
- Primitive: `int`, `float/double`, `char`, `bool`, pointer — built into the language, single value.
- Non-Primitive: Array, Linked List, Stack, Queue, Tree, Graph — built from primitives, hold collections.

**2. Linear vs Non-Linear**
- Linear: elements in strict sequence, one predecessor/one successor (except ends). → Array, Linked List, Stack, Queue.
- Non-Linear: an element can connect to multiple others (hierarchy/network). → Tree, Graph.

**3. Static vs Dynamic**
- Static: size fixed at declaration (e.g. fixed array of 100). Fast, but wastes memory or runs out.
- Dynamic: grows/shrinks at runtime (e.g. linked list). Flexible, but has memory-management overhead.

## Linear structures cheat sheet

| Structure | Access | Principle | Ops |
|---|---|---|---|
| Array | Direct (index) | — | fast read, costly insert/delete in middle |
| Stack | One end (top) | LIFO | push, pop, peek, isEmpty |
| Queue | Front/rear | FIFO | enqueue, dequeue, front |
| Linked List | Sequential via pointers | — | cheap insert/delete, no random access |

## Non-linear structures
- **Tree**: hierarchical, root → parent → child → leaf. One-to-many.
- **Graph**: vertices + edges, many-to-many, can have cycles and weights.

## Abstract Data Types (ADT)
An ADT defines **what** operations exist and how they behave — not **how** they're implemented.
Example: a Stack ADT (`push`, `pop`, `peek`, `isEmpty`, `size`, LIFO behavior) can be implemented with either an array or a linked list — callers don't need to know which.

Why it matters: abstraction, encapsulation, modularity, maintainability, reusability, flexibility.

## Algorithm representation (3 techniques)
1. **Natural language** — fastest to write, can be ambiguous.
2. **Pseudocode** — structured, language-independent, precise.
3. **Flowchart** — visual, makes branching/loops obvious, takes more space.

## Problem-solving process
Understand the Problem → Organize the Data → Select/Design an Algorithm → Implement → Evaluate Efficiency
