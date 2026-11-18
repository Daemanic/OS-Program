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
Starting program: OS-Program/LectureThree/Lab2/testdemo 
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

```bash
(gdb) info files
Symbols from "OS-Program/LectureThree/Lab2/testdemo".
Native process:
	Using the running image of child process 33460.
	While running this, GDB does not access memory from...
Local exec file:
	`/home/abslute/Projects/OS-Program/LectureThree/Lab2/testdemo', file type elf64-littleaarch64.
	Entry point: 0xaaaaaaaa0700
	0x0000aaaaaaaa02a8 - 0x0000aaaaaaaa02cc is .note.gnu.build-id
	0x0000aaaaaaaa02cc - 0x0000aaaaaaaa02e7 is .interp
	0x0000aaaaaaaa02e8 - 0x0000aaaaaaaa0304 is .gnu.hash
	0x0000aaaaaaaa0308 - 0x0000aaaaaaaa0410 is .dynsym
	0x0000aaaaaaaa0410 - 0x0000aaaaaaaa04a9 is .dynstr
	0x0000aaaaaaaa04aa - 0x0000aaaaaaaa04c0 is .gnu.version
	0x0000aaaaaaaa04c0 - 0x0000aaaaaaaa04f0 is .gnu.version_r
	0x0000aaaaaaaa04f0 - 0x0000aaaaaaaa05c8 is .rela.dyn
	0x0000aaaaaaaa05c8 - 0x0000aaaaaaaa0640 is .rela.plt
	0x0000aaaaaaaa0640 - 0x0000aaaaaaaa065c is .init
	0x0000aaaaaaaa0660 - 0x0000aaaaaaaa06d0 is .plt
	0x0000aaaaaaaa0700 - 0x0000aaaaaaaa08b8 is .text
	0x0000aaaaaaaa08b8 - 0x0000aaaaaaaa08d0 is .fini
	0x0000aaaaaaaa08d0 - 0x0000aaaaaaaa09a1 is .rodata
	0x0000aaaaaaaa09a4 - 0x0000aaaaaaaa09e8 is .eh_frame_hdr
	0x0000aaaaaaaa09e8 - 0x0000aaaaaaaa0ab4 is .eh_frame
	0x0000aaaaaaaa0ab8 - 0x0000aaaaaaaa0aee is .sframe
	0x0000aaaaaaaa0af0 - 0x0000aaaaaaaa0b10 is .note.ABI-tag
	0x0000aaaaaaabfdc8 - 0x0000aaaaaaabfdd0 is .init_array
	0x0000aaaaaaabfdd0 - 0x0000aaaaaaabfdd8 is .fini_array
	0x0000aaaaaaabfdd8 - 0x0000aaaaaaabffb8 is .dynamic
	0x0000aaaaaaabffb8 - 0x0000aaaaaaabffe8 is .got
	0x0000aaaaaaabffe8 - 0x0000aaaaaaac0028 is .got.plt
	0x0000aaaaaaac0028 - 0x0000aaaaaaac0048 is .data
	0x0000aaaaaaac0048 - 0x0000aaaaaaac0050 is .bss
	0x0000fffff7fbe200 - 0x0000fffff7fbe224 is .note.gnu.build-id in /lib/ld-linux-aarch64.so.1
	0x0000fffff7fbe228 - 0x0000fffff7fbe400 is .gnu.hash in /lib/ld-linux-aarch64.so.1
	0x0000fffff7fbe400 - 0x0000fffff7fbe7c0 is .dynsym in /lib/ld-linux-aarch64.so.1
	0x0000fffff7fbe7c0 - 0x0000fffff7fbea6a is .dynstr in /lib/ld-linux-aarch64.so.1
```

```bash
(gdb) print &data_global_var
$1 = (int *) 0xaaaaaaac0038 <data_global_var>
(gdb) x/wx &data_global_var
0xaaaaaaac0038 <data_global_var>:	0x12345678
(gdb) print text_string_literal
$2 = 0xaaaaaaaa08d8 " Text_Segment"
(gdb) x/s text_string_literal
0xaaaaaaaa08d8:	" Text_Segment"
(gdb) print &text_string_literal
$3 = (const char **) 0xaaaaaaac0040 <text_string_literal>
(gdb) continue
Continuing.
~ ready for segment inspection ~
[Inferior 1 (process 33917) exited normally]
```

