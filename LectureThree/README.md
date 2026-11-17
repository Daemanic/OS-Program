# Lecture Three [Educational]
> Data Types and OS Memory Management

Understanding how the primitive data types in C map onto real memory, and how the operating system gives every running process its own virtual address space, divided into segments with different purposes.

---

## [~] Learning Objectives

* Primary data types in C (char, int, long, float, double, pointers) and usage of `sizeof()` function.
* Data type sizes across system architectures (e.g. `32-bit` and `64-bit`), and memory allocation.
* The five segments of a process's memory layout: `text`, `data`, `bss`, `heap`, `stack`.
* Disassembling compiled application subroutines into machine opcodes.

---

## [~] Labs in This Lecture

| Lab | Focus |
|---|---|
| [Lab1](./Lab1) | A practical approach to understanding system internals. |
| [Lab2](./Lab2) | Text and Initial data segments via Hardware Disassembly. |
