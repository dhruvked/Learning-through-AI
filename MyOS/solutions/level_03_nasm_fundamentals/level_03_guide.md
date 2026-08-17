# ⚙️ Level 3 Study Guide: NASM Assembly Fundamentals & Directives

> **Level Goal**: Master the Netwide Assembler (NASM) syntax, understand data definitions (`db`, `dw`, `dd`), explore assembly directives (`org`, `bits`, `align`), understand how labels work, and learn to generate assembly listing files.

---

## 🏗️ 1. Assembler Directives vs CPU Instructions

In an assembly source file (`.asm`), there are two distinct categories of lines:

| Category | What it is | Example | Who executes it? |
| :--- | :--- | :--- | :--- |
| **CPU Instructions** | Translated directly into x86 machine code bytes | `mov ax, 0`, `jmp $` | The **CPU Hardware** at runtime |
| **Assembler Directives** | Commands given to the assembler itself (NASM) | `[org 0x7c00]`, `align 4` | The **Assembler (NASM)** at compile-time |

---

## 📦 2. Data Definition Directives

To store variables, strings, tables, and magic numbers in your binary image, NASM provides data definition keywords:

```nasm
; Directives for placing initialized data into the binary:
db 0x55                 ; Define Byte       (8 bits  / 1 byte)
dw 0xAA55               ; Define Word       (16 bits / 2 bytes)
dd 0x12345678           ; Define Doubleword (32 bits / 4 bytes)
dq 0x0123456789ABCDEF   ; Define Quadword   (64 bits / 8 bytes)

; Defining strings (ASCII bytes):
msg db "Hello, OS!", 0x0D, 0x0A, 0 ; String ending in CR (\r), LF (\n), and NULL terminator (0)
```

### Uninitialized Data Reservations (BSS):
If you need buffer space without putting zeros into the binary file itself:
* `resb 64`: Reserve 64 bytes
* `resw 10`: Reserve 10 words (20 bytes)
* `resd 4`: Reserve 4 doublewords (16 bytes)

---

## 🏷️ 3. How Labels Work in Assembly

A label in NASM is not a variable—it is **a name for a memory address**.

```nasm
[org 0x7c00]

start:                  ; start = 0x7C00
    mov ax, [my_data]   ; loads 16-bit word from address (0x7C00 + offset)
    jmp hang

my_data:                ; my_data = 0x7C00 + size of preceding instructions
    dw 0x1234

hang:
    jmp hang
```

### Global vs Local Labels
* **Global labels**: `my_function:`
* **Local labels**: `.loop:` (prefixed with a dot). A local label belongs to the preceding global label:

```nasm
print_string:
.loop:                  ; Full symbol name is print_string.loop
    lodsb
    test al, al
    jz .done
    ; ...
    jmp .loop
.done:
    ret
```

---

## 🧮 4. The Special Symbols: `$` and `$$`

NASM provides two built-in positional symbols:

1. `$` : Evaluates to the **current assembly address** of the line where it is written.
2. `$$` : Evaluates to the **start address of the current section** (in our bootloader with `[org 0x7c00]`, `$$ = 0x7C00`).

### The Classic Padding Formula:
```nasm
times 510 - ($ - $$) db 0
```
* `($ - $$)` calculates: *Current Address minus Start Address* = **Total number of bytes generated so far**.
* `510 - ($ - $$)` calculates: **How many filler bytes (0s) are needed** so that the boot signature starts exactly at offset 510.
* If your code exceeds 510 bytes, `510 - ($ - $$)` becomes negative, and NASM will throw an error (alerting you that your bootloader is too large to fit in 1 sector!).

---

## 📜 5. NASM Listing Files (`.lst`)

A **listing file** shows your source code side-by-side with the exact generated hex machine code and memory offsets. It is the best debugging tool for assembly.

### Generating a Listing File:
```bash
nasm -f bin bootloader.asm -o boot.bin -l boot.lst
```

### Example Listing Output:
```text
 1                                  [org 0x7c00]
 2                                  [bits 16]
 3                                  
 4 00000000 31C0                    xor ax, ax
 5 00000002 8ED8                    mov ds, ax
 6 00000004 EBFD                    hang: jmp hang
 7 00000006 00<rept>                times 510 - ($ - $$) db 0
 8 000001FE 55AA                    dw 0xaa55
```
* Notice column 2: `31C0` is the 2-byte opcode for `xor ax, ax`.
* Notice offset `000001FE` (which is $510$ in decimal): contains bytes `55 AA`.

---

## ❓ Concept Check Quiz

1. **What is the difference between `mov ax, my_var` and `mov ax, [my_var]` in NASM?**
2. **If your code takes up 42 bytes so far, what is the value of `510 - ($ - $$)`?**
3. **What flag do you pass to NASM to create a raw flat binary without any OS executable headers (like ELF or PE)?**

---

## 🎯 Level 3 Hands-on Quest

1. Create directory `solutions/level_03_nasm_fundamentals/`.
2. Write an assembly file defining different data sizes (`db`, `dw`, `dd`) and labels.
3. Assemble with `-l listing.lst` to inspect the generated opcodes and byte layouts.
4. Verify the output binary using PowerShell or a hex viewer.
