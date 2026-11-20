# Push_swap — Development Progress

## Project Overview

This project is being developed as part of the **42 School curriculum**.

The goal is to sort integers in Stack A using Stack B and a limited set of stack operations, while minimizing the number of operations.

**Current status:** Stack data structure and basic helper functions implemented. Sorting algorithms have not been started yet.

## Data Structure

We chose a **Doubly Linked List** to represent our stacks.

Each stack contains:

- `head`: Pointer to the first (top) node
- `tail`: Pointer to the last (bottom) node
- `size`: Number of nodes

Each node contains:

- `value`: Integer value
- `next`: Pointer to the next node
- `prev`: Pointer to the previous node

This structure allows efficient insertion and removal of nodes at the top of the stack.

## Implemented Functions

| Function | Purpose |
|---|---|
| `init_stack` | Initializes an empty stack |
| `create_node` | Allocates and initializes a new node |
| `add_back` | Adds a node to the end of a stack |
| `pop_front` | Removes and returns the top node |
| `add_front` | Adds a node to the top of a stack |

### File Organization

- `push_swap.h` — Data structures and function declarations
- `stack_init.c` — `init_stack`, `create_node`
- `stack_utils.c` — `add_back`, `pop_front`, `add_front`

File organization is planned to respect the 42 Norminette limit of five functions per `.c` file.

## Current Progress

- [x] Choose stack representation
- [x] Define `t_node` and `t_stack`
- [x] Implement stack initialization
- [x] Implement node creation
- [x] Implement basic node insertion and removal
- [ ] Test stack helper functions
- [ ] Implement stack operations (`sa`, `sb`, `pa`, `pb`, `ra`, etc.)
- [ ] Implement sorting algorithms
- [ ] Implement adaptive algorithm selection and benchmark output
- [ ] Complete integration tests and optimization

## Where We Stopped

**Last completed function:** `add_front()` in `stack_utils.c`.

**Next task:** Implement `pa` and `pb` using the existing `pop_front()` and `add_front()` helper functions.

These operations will transfer the top node from one stack to the other without allocating a new node.

## Notes

This README documents the current development checkpoint, not a finished implementation. Functions have been reviewed logically during development but have not yet been confirmed through compilation, Norminette, or automated tests.