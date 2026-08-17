# 🚀 Level 1 Study Guide: The Boot Sector & BIOS Fundamentals

> **Level Goal**: Understand what happens when an x86 computer turns on, why the BIOS loads code to `0x7C00`, what makes a 512-byte sector "bootable", and how to write your first bare-metal assembly bootloader.

---

## ⚡ 1. The Hardware Boot Sequence (Power-On to Bootloader)

When you press the power button on an x86 computer, the CPU doesn't know about files, operating systems, or drivers. Here is the exact sequence of events:

```
+-----------------------------------------------------------------------+
| 1. Power Supply sends 'Power Good' signal to Motherboard              |
+-----------------------------------------------------------------------+
                                  │
                                  ▼
+-----------------------------------------------------------------------+
| 2. CPU resets registers and starts in 16-bit REAL MODE                |
|    Instruction Pointer (CS:IP) is set to 0xFFFF:0x0000 (0xFFFF0)      |
+-----------------------------------------------------------------------+
                                  │
                                  ▼
+-----------------------------------------------------------------------+
| 3. BIOS ROM executes POST (Power-On Self-Test)                        |
|    - Initializes RAM, keyboard, timer, basic hardware                 |
+-----------------------------------------------------------------------+
                                  │
                                  ▼
+-----------------------------------------------------------------------+
| 4. BIOS searches configured boot order (Floppy, HDD, USB, CD-ROM)     |
|    - Reads the very first 512-byte sector (LBA 0) into RAM            |
+-----------------------------------------------------------------------+
                                  │
                                  ▼
+-----------------------------------------------------------------------+
| 5. BIOS checks for the Magic Boot Signature at bytes 510 & 511        |
|    - Are the last two bytes 0x55, 0xAA (0xAA55)?                      |
|      - NO  -> Try next device / "No bootable device found"            |
|      - YES -> Copy sector to RAM at 0x0000:0x7C00 and JUMP to it!     |
+-----------------------------------------------------------------------+
                                  │
                                  ▼
+-----------------------------------------------------------------------+
| 6. YOUR CODE IS NOW IN CONTROL OF THE CPU AT 0x7C00!                  |
+-----------------------------------------------------------------------+
```

---

## 🧠 2. Core Concepts You Must Master

### Concept A: What is Real Mode?
* When the x86 CPU starts, it boots in **16-bit Real Mode** for backward compatibility with the original Intel 8086 processor (from 1978).
* In Real Mode:
  * Registers are 16 bits wide (`AX`, `BX`, `CX`, `DX`, `SP`, `BP`, `SI`, `DI`).
  * The CPU can only access up to **1 MB of RAM** (`0x00000` to `0xFFFFF`).
  * There is **no memory protection** (no paging, no ring 0 vs ring 3). A bug can overwrite BIOS memory or crash the CPU.

---

### Concept B: The Magic Address `0x7C00`
Why does BIOS load our bootloader at memory address `0x7C00` instead of `0x0000`?

* In Real Mode, the lowest memory addresses (`0x00000` – `0x004FF`) are reserved by BIOS for:
  * `0x00000 - 0x003FF`: **Interrupt Vector Table (IVT)** (256 interrupt pointers).
  * `0x00400 - 0x004FF`: **BIOS Data Area (BDA)** (hardware status, timer ticks).
* In the early IBM PC era (1981), computers had only **32 KB** of RAM (`0x0000` to `0x7FFF`).
* To leave maximum contiguous free RAM for the operating system to load into, the IBM engineers decided to place the 512-byte bootloader at the very end of the first 32 KB:
  $$\text{32 KB} = 32 \times 1024 = 32768 \text{ bytes} = \text{0x8000}$$
  $$\text{0x8000} - 512 \text{ bytes (0x200)} = \mathbf{0x7C00}$$
* Every x86 PC BIOS still preserves this standard today.

---

### Concept C: The 512-Byte Sector & Boot Signature (`0xAA55`)
A standard floppy or hard drive sector is exactly **512 bytes**.
* Bytes `0` through `509` (510 bytes): Your executable machine instructions and data.
* Byte `510`: `0x55`
* Byte `511`: `0xAA`

Because x86 is **Little-Endian** (least significant byte stored first in memory), in 16-bit word format this is written as `0xAA55`.

```text
Byte Offset:   000 ........................................ 509   510   511
Contents:    [ ... Your Bootloader Code / Zero Padding ... ]  [0x55] [0xAA]
Total Size:  <-------------------- Exactly 512 Bytes -------------------->
```

---

## 🛠️ 3. Deconstructing the Level 1 Bootloader Code

Here is what a minimal bootloader in NASM looks like:

```nasm
[org 0x7c00]        ; Directive: tell assembler code will be loaded at 0x7c00
[bits 16]           ; Directive: emit 16-bit Real Mode instructions

hang:
    jmp hang        ; Infinite loop to prevent CPU from running off into random memory

; Pad remaining bytes with zeros up to byte 510
times 510 - ($ - $$) db 0

; Magic Boot Signature (2 bytes: 0x55, 0xAA)
dw 0xaa55
```

### Line-by-Line Breakdown:
1. `[org 0x7c00]`: 
   * Tells NASM that all memory address calculations and label offsets must be calculated assuming the code begins at address `0x7C00`.
2. `[bits 16]`:
   * Tells NASM to generate 16-bit x86 machine code instructions.
3. `hang: jmp hang` (or `jmp $`):
   * An infinite loop. If you don't halt or loop the CPU, the instruction pointer (`IP`) will continue executing whatever arbitrary garbage exists in RAM after `0x7C00`, resulting in a CPU crash / reboot loop.
4. `times 510 - ($ - $$) db 0`:
   * `$` = The current memory address of the line being assembled.
   * `$$` = The start address of the current section (`0x7C00`).
   * `($ - $$)` = The exact number of bytes written so far.
   * `510 - ($ - $$)` = How many bytes of zeros are needed to reach exactly 510 bytes.
   * `db 0` = Define Byte with value `0`.
5. `dw 0xaa55`:
   * `dw` = Define Word (2 bytes / 16 bits).
   * Writes `0x55` then `0xAA` in little-endian order, filling bytes 510 and 511. Total file size = **512 bytes**.

---

## 💻 4. How to Assemble, Verify, and Run

### Step 1: Assemble with NASM
Convert your human-readable assembly text into pure raw binary machine code (flat binary, no OS file headers):
```bash
nasm -f bin bootloader.asm -o boot.bin
```

### Step 2: Verify Binary File Size and Magic Bytes
Check that `boot.bin` is **exactly 512 bytes**:
In PowerShell:
```powershell
(Get-Item boot.bin).Length   # Output MUST be 512
```

Inspect the last two bytes (should be `55 aa`):
In PowerShell:
```powershell
Format-Hex boot.bin | Select-Object -Last 2
```

### Step 3: Run in QEMU Emulator
Boot the raw binary as a virtual floppy drive or disk drive:
```bash
qemu-system-x86_64 -fda boot.bin
# or
qemu-system-i386 -drive format=raw,file=boot.bin
```
*(In QEMU, you will see SeaBIOS boot, detect the floppy/drive, and run your bootloader!)*

---

## 🎯 5. Your Active Quest for Level 1

Now it's your turn to write the code and verify it:

1. Create `solutions/level_01_boot_sector/bootloader.asm`.
2. Write the 512-byte bootloader code.
3. Assemble it to `solutions/level_01_boot_sector/boot.bin`.
4. Verify the 512-byte length and `0xAA55` signature.
5. Boot it in QEMU!

---

## ❓ Concept Check Quiz

Test your understanding:

1. **Why does the BIOS specifically look for `0x55` and `0xAA` at the end of the first sector?**
2. **What does the NASM expression `($ - $$)` calculate?**
3. **If you remove `[org 0x7c00]`, will an infinite loop `jmp hang` still execute correctly? Why or why not?**
