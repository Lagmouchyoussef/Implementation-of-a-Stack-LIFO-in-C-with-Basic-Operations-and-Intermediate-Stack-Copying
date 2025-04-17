# Implementation of a Stack (LIFO) in C with Intermediate Stack Copying

The main objective of this lab is to explore a new type of linear data structure that follows the LIFO (Last In First Out) algorithm. In this task, we must implement stacks using linked lists.

## Problem

The proposed structure is as follows:

```c
typedef struct Pile {
    int data;
    struct Pile *suiv;
} pile;
```

Write a program that includes the following functions:

### Part A — Stack Operations

- A function `Bool_is_empty(stack *top)` that returns 1 if the stack is empty, and 0 otherwise.
- A function `stack* Push(stack *top, int val)` that creates a new node and inserts it. This operation is called "pushing" in stacks.
- A function `int Pop(stack **top)` that removes the last node added and returns its `data`.
- A function `void Display(stack *top)` that displays the contents of the stack.

### Part B — Copying a Stack

In this part, we will take an initial stack and then copy its content to a final stack using an intermediate stack.

The diagram below shows the details of this operation:

```
       TOP
STACK 1     --->   STEP 1   --->   INTERMEDIATE STACK  --->   STEP 2   --->   STACK 2

  12                                        6                                        12
  14                                       12                                        14
  16                                       20                                        16
  20                                       16                                        20
   6                                       14                                         6
                                           12
```

- Write a function `stack* Copy(stack *top)` that will copy the contents of stack 1 (passed as a parameter) to stack 2 using an intermediate stack.

### Part C — Testing

- Test all these functions in the `main()` program.
