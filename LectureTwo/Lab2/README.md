# [1] Lab Task
> Standard Library and POSIX extensions in C program

## [~] Objective
Understanding how compiler transforms human-readable C code into machine instructions using multiple functions like `printf()`, `getpid()`, `time()` from the standard library.

---

| Contains | Location |
|---|---|
| Declarations, prototypes, macros | `/usr/included/` |
| Precompiled object code (archive) | `/usr/lib/` |
| Precompiled position-independent code | `/lib/` |

---

## [?] Standard Library Files
**Physical Location:**
```bash
ls /usr/include/
ls /usr/include/stdio.h /usr/include/unistd.h
grep "printf" /usr/include/stdio.h | head -2
grep "getpid" /usr/include/unistd.h | head -2
```

**Static Linking:**
```bash
gcc -static procinfo.c -o infostatic
ls -lh infostatic
```

**Dynamic Linking:**
```bash
gcc procinfo.c -o infodynamic
ls -lh infodynamic
```

---

## [~] Project Structure

```
Lab1/
│── infodynamic     ← dynamic linking
│── infostatic      ← static linking
│── procinfo.c      ← multiple functions usage from standard library
└── README.md
```
