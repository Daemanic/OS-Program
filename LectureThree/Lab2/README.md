# [2] Lab Task
> Auditing via Hardware Disassembly

## [~] Objective

Evaluate the structural composition and isolation boundaries separating the Text segment (`.rodata`, `.text`) from the Initial Data segment (`.data`) on system architectures and disassembling compiled application subroutines into machine opcodes to track hardware instruction pointers.

---

```bash
gcc -g demo.c -o testdemo
gdb ./testdemo
```

```bash
(gdb) break 17
Breakpoint 1 at 0x8a0: file demo.c, line 18.
(gdb) run
Starting program: /home/abslute/Projects/OS-Program/LectureThree/Lab2/testdemo 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
~ addresses: ~
data (global initialized): 0xaaaaaaac0038
text string (rodata): 0xaaaaaaaa08d8
text code (function): 0xaaaaaaaa0824
~ executing text segment block ~

Breakpoint 1, main () at demo.c:18
18	  printf("~ ready for segment inspection ~\n");
(gdb) 
```

---
```
```
