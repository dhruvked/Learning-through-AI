# 🎯 Level 6 Study Guide: x86 Addressing Modes & Data Movement

> **Level Goal**: Master the 7 addressing modes of 16-bit Real Mode, understand valid base/index register combinations, learn size qualifiers (`byte` / `word`), and explore essential data movement instructions (`mov`, `lea`, `xchg`).

---

## 🔍 1. The 7 Real Mode Addressing Modes

In assembly, an **addressing mode** specifies how the CPU calculates the memory location (or operand) for an instruction:

| Addressing Mode | NASM Syntax Example | What it does |
| :--- | :--- | :--- |
| **1. Immediate** | `mov ax, 0x1234` | The operand value is embedded directly inside the instruction bytes. |
| **2. Register** | `mov ax, bx` | Data is copied directly from one CPU register to another. Fastest mode. |
| **3. Direct Memory** | `mov ax, [my_var]` | Reads memory at the fixed offset of `my_var` using `DS`. |
| **4. Register Indirect** | `mov al, [bx]` | Reads memory at the offset stored inside register `BX`. |
| **5. Base + Displacement** | `mov al, [bx + 4]` | Adds a constant offset ($+4$) to `BX` to compute the memory address. |
| **6. Base + Index** | `mov al, [bx + si]` | Adds two registers (`BX` base + `SI` index) to compute address. |
| **7. Base + Index + Disp** | `mov al, [bx + si + 8]` | Adds base (`BX`), index (`SI`), and constant offset ($+8$). |

---

## ⚠️ 2. The 16-Bit Real Mode Register Restriction

In modern 32-bit and 64-bit mode, almost any register can be placed inside memory brackets `[...]`.

However, in **16-bit Real Mode**, the x86 CPU hardware ONLY permits four specific registers inside brackets:

$$\text{Valid 16-bit Base/Index Registers}: \mathbf{BX}, \mathbf{BP}, \mathbf{SI}, \mathbf{DI}$$

```nasm
; ✅ VALID 16-bit memory references:
mov al, [bx]
mov al, [bp]
mov al, [si]
mov al, [di]
mov al, [bx + si]
mov al, [bx + di]
mov al, [bp + si]
mov al, [bp + di]

; ❌ ILLEGAL in 16-bit Real Mode (will fail to assemble!):
mov al, [ax]        ; Error: invalid effective address
mov al, [cx]        ; Error: invalid effective address
mov al, [dx]        ; Error: invalid effective address
mov al, [sp]        ; Error: invalid effective address
mov al, [si + di]   ; Error: cannot combine two index registers together!
```

---

## 📏 3. Operand Size Disambiguation (`byte` vs `word`)

When copying an immediate constant into memory via a pointer, NASM cannot know how many bytes to write unless you specify the size qualifier:

```nasm
mov [bx], 0         ; ❌ ERROR: operation size not specified!

; ✅ Explicitly declare the operand size:
mov byte [bx], 0    ; Writes 1 byte  (8 bits:  0x00)
mov word [bx], 0    ; Writes 2 bytes (16 bits: 0x00, 0x00)
```

---

## 🔄 4. Key Data Movement Instructions

### 1. `mov` (Move / Copy Data)
* **Golden Rule**: You cannot move memory-to-memory in a single x86 instruction:
  ```nasm
  mov [dest], [src]   ; ❌ ILLEGAL on x86!

  ; ✅ Must use a temporary register:
  mov al, [src]
  mov [dest], al
  ```

### 2. `lea` (Load Effective Address)
* `lea` calculates the memory address without reading the data stored at that address!
* Often used for fast arithmetic:
  ```nasm
  lea bx, [my_string]      ; Loads memory address of my_string into BX
  lea ax, [bx + si + 4]    ; Calculates (BX + SI + 4) and stores result in AX
  ```

### 3. `xchg` (Atomic Exchange)
* Swaps the contents of two registers, or a register and a memory location:
  ```nasm
  xchg ax, bx              ; AX and BX swap their values instantly!
  ```

---

## 💻 5. Practical Code Example: Array Traversal

Here is how addressing modes and index registers are used to walk through a string or table in Real Mode:

```nasm
[org 0x7c00]
[bits 16]

    xor ax, ax
    mov ds, ax          ; DS = 0

    mov bx, greeting    ; BX holds base address of string
    mov si, 0           ; SI holds current index (offset = 0)

.loop:
    mov al, [bx + si]   ; Base + Index addressing!
    test al, al         ; Check if AL == 0 (null terminator)
    jz .done            ; If 0, finished string

    mov ah, 0x0E        ; BIOS teletype print
    int 0x10

    inc si              ; Increment index
    jmp .loop

.done:
    jmp $

greeting:
    db "MyOS Kernel Booting...", 0x0D, 0x0A, 0

times 510 - ($ - $$) db 0
dw 0xaa55
```

---

## ❓ Concept Check Quiz

1. **Why is `mov al, [cx]` illegal in 16-bit Real Mode assembly?**
2. **What is the difference between `mov ax, [my_table]` and `lea ax, [my_table]`?**
3. **If `BX = 0x1000`, `SI = 0x0004`, and `DS = 0x0000`, what physical memory address does `mov al, [bx + si]` read?**

---

## 🎯 Level 6 Hands-on Quest

1. Create directory `solutions/level_06_addressing_modes/`.
2. Write an assembly program that iterates over an array of characters using `[bx + si]` addressing.
3. Print each character to the screen using BIOS `int 0x10`.
4. Assemble with NASM, test in QEMU, and verify string output.
