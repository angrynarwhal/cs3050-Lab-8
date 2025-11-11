
# Lab: Multiprocessing vs Multithreading in C

## Assignment

CS 3050: Systems Programming Lab — Multiprocessing vs Multithreading in C

### Objectives:
- Understand the difference between multiprocessing and multithreading.
- Use fork() to create processes.
- Use pthread to create threads.
- Measure and compare performance.

### Tasks:
1. multiprocessing.c: Create N child processes with fork(), compute and print a sum.
2. multithreading.c: Create N threads with pthread, compute and print a sum.
3. Compare performance using gettimeofday or clock_gettime.
4. Reflect on resource use, risks, and use cases.

### Deliverables:
- multiprocessing.c
- multithreading.c
- performance.txt
- reflection.txt

## Deliverable Guidance

This lab explores the difference between **process-based** and **thread-based** parallelism using C.

### Compilation Instructions

#### Using `pthread` (POSIX Threads)

The `pthread` library is used for multithreading in C on Unix-based systems like Linux and macOS.

#### How to Compile with `pthread`

You **must link** against the pthread library when compiling.

##### Recommended:

```bash
gcc -pthread multithreading.c -o multithreading
```

##### Alternative (not preferred):

```bash
gcc multithreading.c -o multithreading -lpthread
```

Both commands compile your program, but `-pthread` is preferred because it also defines macros that ensure compatibility.

---

### Include the pthread Header

In your C source file:

```c
#include <pthread.h>
```

---

### Windows Notes

This lab is intended for **Unix-based systems**. If you're on Windows:

- Use **WSL (Windows Subsystem for Linux)**, or
- Access a **Linux VM**, or
- Use **macOS** or a university lab machine.

---

### Sample Run

```bash
# Compile
gcc -pthread multithreading.c -o multithreading

# Run with 4 threads
./multithreading 4
```

---

### Files to Submit

- `multiprocessing.c`
- `multithreading.c`
- `performance.txt`
- `reflection.txt`
