# [3] Lab Task
> Mapping Process Runtime Topography

## [~] Objective

Evaluate the physical address boundaries, separating static allocations (`.bss`) from dynamic regions (Heap, Stack) and navigating runtime program contexts using specialized subcommands inside the GNU Debugger (`GDB`).

---

## [?] Laboratory Procedures

**Building Executable:**
```bash
gcc -g mapping.c -o testproc
gdb ./testproc
```

**Setting Breakpoints and Runtime:**
```bash
(gdb) break 17
Breakpoint 1 at 0x9fc: file mapping.c, line 18.
(gdb) run
Starting program: OS-Program/LectureThree/Lab3/testproc 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
~ mapping addresses ~
bss (global): 0xaaaaaaac0054
stack (local): 0xffffffffd4fc
heap (dynamic): 0xaaaaaaac1010

Breakpoint 1, main () at mapping.c:18
18	  printf("~ ready for GDB inspection ~\n");
```

**Mapping Static BSS Segment Bounds:**
```bash
(gdb) info files
Symbols from "OS-Program/LectureThree/Lab3/testproc".
Native process:
	Using the running image of child process 54204.
	While running this, GDB does not access memory from...
Local exec file:
	'OS-Program/LectureThree/Lab3/testproc', file type elf64-littleaarch64.
	Entry point: 0xaaaaaaaa0840
	0x0000aaaaaaaa02a8 - 0x0000aaaaaaaa02cc is .note.gnu.build-id
	0x0000aaaaaaaa02cc - 0x0000aaaaaaaa02e7 is .interp
	0x0000aaaaaaaa02e8 - 0x0000aaaaaaaa0304 is .gnu.hash
	0x0000aaaaaaaa0308 - 0x0000aaaaaaaa0470 is .dynsym
	0x0000aaaaaaaa0470 - 0x0000aaaaaaaa054e is .dynstr
	0x0000aaaaaaaa054e - 0x0000aaaaaaaa056c is .gnu.version
	0x0000aaaaaaaa0570 - 0x0000aaaaaaaa05c0 is .gnu.version_r
	0x0000aaaaaaaa05c0 - 0x0000aaaaaaaa0698 is .rela.dyn
	0x0000aaaaaaaa0698 - 0x0000aaaaaaaa0758 is .rela.plt
	0x0000aaaaaaaa0758 - 0x0000aaaaaaaa0774 is .init
```

**Extracting OS Kernel Address Tables:**
```bash
(gdb) info proc mappings
process 54204
Mapped address spaces:

Start Addr         End Addr           Size               Offset             Perms File 
0x0000aaaaaaaa0000 0x0000aaaaaaaa1000 0x1000             0x0                r-xp  OS-Program/LectureThree/Lab3/testproc 
0x0000aaaaaaabf000 0x0000aaaaaaac0000 0x1000             0xf000             r--p  OS-Program/LectureThree/Lab3/testproc 
0x0000aaaaaaac0000 0x0000aaaaaaac1000 0x1000             0x10000            rw-p  OS-Program/LectureThree/Lab3/testproc 
0x0000aaaaaaac1000 0x0000aaaaaac00000 0x13f000           0x0                rw-p  [heap] 
0x0000fffff7dd0000 0x0000fffff7f7f000 0x1af000           0x0                r-xp  /usr/lib/libc.so.6 
0x0000fffff7f7f000 0x0000fffff7f8d000 0xe000             0x1af000           ---p  /usr/lib/libc.so.6 
0x0000fffff7f8d000 0x0000fffff7f90000 0x3000             0x1bd000           r--p  /usr/lib/libc.so.6 
```

**Auditing Local Register States and Low-Level Cells:**
```bash
(gdb) print stack_local_var
$2 = 42
(gdb) print &stack_local_var
$3 = (int *) 0xffffffffd4fc
(gdb) x/4wx $sp
0xffffffffd4f0:	0x00000000	0x00000000	0x00000000	0x0000002a
```

**Examine the Heap Data Pool:**
```bash
(gdb) print heap_ptr
$4 = (int *) 0xaaaaaaac1010
(gdb) x/1wd heap_ptr
0xaaaaaaac1010:	99
```

> Note: perform workspace demobilization (`continue` & `quit`), after reviewing the output of the examine command.

---

## [~] Project Structure

```
Lab3/
│── mapping.c      │── ./testproc
└── README.md
```
