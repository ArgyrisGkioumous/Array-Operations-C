# Data Structures: Array Operations & Search Benchmarks

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS-lightgrey.svg)]()

A modular C application implementing dynamic array operations, pointer arithmetic, sorting, merging, and empirical search complexity analysis. Developed for the **Data Structures** course at the **University of West Attica (UNIWA)**.

---

## Overview

This project focuses on dynamic memory management and pointer-based element traversal without relying on bracket notation (`[]`). It includes an interactive CLI menu to perform searches, array sorting, merging, file I/O operations, and algorithmic benchmarking.

### Key Features
- **Dynamic Array Allocation**: Allocates memory at runtime based on user-defined size $N$.
- **Pseudo-Random Generation**: Populates arrays with random integer values strictly bounded in $[30, 500]$.
- **Pointer Arithmetic Traversal**: All access and manipulation are executed using direct memory offset references (e.g., `*(arr + i)`).
- **Search & Sort Pipeline**:
  - **Sequential / Linear Search**: Unsorted memory lookup.
  - **Sorting Algorithm**: Efficient array ordering on a dynamic copy.
  - **Binary Search**: Fast lookup implemented over sorted array copies.
- **Sorted Array Merging**: Spawns a temporary sorted pseudo-random array of size $N$ and merges it with the existing sorted array into a unified $2N$ array.
- **File Persistence**: Load and save raw array states directly to/from disk.
- **Search Performance Benchmark (Bonus Feature)**: Programmatically measures total element read accesses required to find every element in the array, comparing Linear vs. Binary search efficiency.

---

## Technical Constraints & Principles

- **No Bracket Operator (`[]`)**: Strictly enforces pointer notation (`*(arr + i)`) across all subroutines.
- **Zero Global Variables**: Enforces functional purity by explicitly passing parameters and pointers.
- **Memory Safety**: Clean deallocation of all dynamic buffers (including temporary merging arrays).

---

## Repository Structure

```text
.
├── src/
│   ├── main.c              # Interactive console menu and memory allocation
│   ├── array_ops.c         # Search, sort, merge, and benchmarking subroutines
│   └── file_io.c           # Dynamic array file read/write operations
├── include/
│   ├── array_ops.h         # Function signatures and data types
│   └── file_io.h           # File I/O interfaces
├── Makefile                # Build automation script
├── LICENSE                 # MIT License
└── README.md               # Documentation
