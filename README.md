<!-- PROJECT LOGO -->

<br />
<div align="center">
  <h1>push_swap</h1>

  <p align="center">
    A C program to sort a stack of numbers with minimal operations.  
    <br />
  </p>
</div>

<!-- TABLE OF CONTENTS -->

## Contents

* [About the Project](#about-the-project)
* [My Implementation](#my-implementation)
* [Project Structure](#project-structure)
* [Usage](#usage)

## About the Project

This project implements the classic **push\_swap** problem:
Given a list of integers, it must be sorted using only a limited set of stack operations. The goal is to minimize the number of operations.
The project is written in C and uses a linked list structure with normalized indices for efficient comparisons.

## My Implementation

Stacks are stored as singly linked lists (`t_list`) from libft, with each node holding an integer and an index. Small inputs (2–5 numbers) are sorted with simple fixed rules. For larger inputs I use **radix sort**: I look at the numbers bit by bit, starting from the lowest bit. If the current bit is 0 the number goes to stack B, if it is 1 it stays in stack A. After one round all numbers are put back into stack A, and I move to the next bit. When all bits are checked, the stack is sorted.
**Example:** If the indices are `[2, 5, 3]` → in binary `[010, 101, 011]`:

* Round 1 (bit 0): `[2, 3]` go to B, `[5]` stays in A.
* Round 2 (bit 1): reorder again by the second bit.
* Round 3 (bit 2): reorder by the third bit → final order is sorted.

Radix is not the most efficient method, but it was good enough to achieve solid and reliable results to pass this project.

## Project Structure

```
push_swap/
├─ src/               # Source files and header
├─ libft/             # 42 libft (list functions etc.)
├─ Makefile
└─ .gitignore
```

## Usage

```sh
# Build
make        # build push_swap binary
make re     # rebuild everything
make clean  # remove object files
make fclean # remove objects + binary

# Run with multiple arguments (MULTI mode)
./push_swap 4 67 3 87 23

# Run with a single string argument (SINGLE mode)
./push_swap "4 67 3 87 23"

# Example
$ ./push_swap 2 1 3
sa
```
