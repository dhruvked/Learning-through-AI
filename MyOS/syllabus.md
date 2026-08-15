# 📜 MyOS — Level 1 to 100 Syllabus

> A complete progression path from writing your first boot sector in x86 Assembly to building a functional Unix-like OS kernel in C.

---

## 🟢 Tier 1: Boot & x86 Assembly Fundamentals (Levels 1 – 20)

- **Level 1–3**: The Boot Sector — how BIOS works, the 0x7C00 load address, the 0x55AA boot signature, writing a minimal bootloader in NASM.
- **Level 4–6**: x86 Registers — General-purpose registers (`AX`, `BX`, `CX`, `DX`), segment registers, `SP`, `IP`, Real Mode addressing.
- **Level 7–9**: BIOS Interrupts & Printing — Using `int 0x10` to print characters and strings to the screen without an OS.
- **Level 10–12**: Assembly Control Flow — Conditional jumps (`je`, `jne`, `jl`, `jg`), loops (`loop`), the `CMP` instruction, labels.
- **Level 13–15**: The Stack in Assembly — `push`, `pop`, `call`, `ret`, how the stack works in Real Mode.
- **Level 16–18**: Disk Reading (BIOS int 0x13) — Reading additional sectors from disk into memory to load a larger kernel.
- **Level 19–20**: Tier 1 Capstone — A complete bootloader that prints a welcome message and reads a second stage from disk.

---

## 🔵 Tier 2: Protected Mode & C Kernel Bootstrap (Levels 21 – 40)

- **Level 21–23**: The Global Descriptor Table (GDT) — What it is, why it exists, writing a GDT in NASM.
- **Level 24–26**: Switching from Real Mode → Protected Mode — The exact CPU instruction sequence, `CR0` register, the far jump.
- **Level 27–29**: Linking Assembly with C — Cross-compiler setup (`i686-elf-gcc`), linker scripts, calling C from assembly.
- **Level 30–32**: VGA Text Mode Driver in C — Writing characters to `0xB8000`, building a `kprintf()` function.
- **Level 33–35**: Interrupt Descriptor Table (IDT) — What interrupts are, setting up an IDT in C, writing interrupt service routines (ISRs).
- **Level 36–38**: Exception Handling — CPU exceptions (divide by zero, page fault, general protection fault), panic screen.
- **Level 39–40**: PIC & Keyboard Driver — Programmable Interrupt Controller (8259 PIC), IRQ remapping, reading keyboard scancodes.

---

## 🟡 Tier 3: Memory Management (Levels 41 – 60)

- **Level 41–44**: Physical Memory Detection — Using BIOS `e820` to get a memory map, parsing the memory layout.
- **Level 45–48**: Paging & Virtual Memory — Page directories, page tables, 4KB pages, enabling the `CR3` register.
- **Level 49–52**: Kernel Heap Allocator — `kmalloc()` and `kfree()` from scratch using a free-list allocator.
- **Level 53–56**: Virtual Memory Manager — Mapping virtual addresses to physical frames, kernel vs. user space split at `0xC0000000`.
- **Level 57–60**: Tier 3 Capstone — A fully working memory subsystem: physical frame allocator + virtual memory mapper + kernel heap.

---

## 🔴 Tier 4: Processes, Scheduling & File Systems (Levels 61 – 80)

- **Level 61–64**: Processes & Context Switching — Process Control Block (PCB), saving and restoring CPU state (`EIP`, `ESP`, registers).
- **Level 65–68**: Scheduler — Round-robin scheduler, timer IRQ (PIT — Programmable Interval Timer), preemptive multitasking.
- **Level 69–72**: System Calls — The `int 0x80` syscall interface, privilege levels (Ring 0 vs Ring 3), user mode.
- **Level 73–76**: ATA Disk Driver — Reading/writing disk sectors via ATA PIO mode (polling), sector-level I/O.
- **Level 77–80**: File System (FAT12) — Parsing the FAT12 file system, reading files from disk, `open()` and `read()` syscalls.

---

## 👑 Tier 5: User Space, Shell & Advanced Features (Levels 81 – 100)

- **Level 81–85**: ELF Loader — Parsing ELF binaries, loading user-space programs from disk into memory, jumping to user space.
- **Level 86–90**: User-Space C Library (libc) — A minimal `libc` for user programs: `printf`, `malloc`, `exit`, `read`, `write` over syscalls.
- **Level 91–94**: Shell — A basic command-line shell: parsing input, `fork()` + `exec()` model, running programs.
- **Level 95–97**: Signals & IPC — Signal delivery, pipes, basic inter-process communication.
- **Level 98–100**: Final Capstone — A bootable OS image that: boots, runs a shell, can execute user programs, reads/writes files.
