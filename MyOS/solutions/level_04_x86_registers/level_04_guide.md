# 🧠 Level 4 Study Guide: x86 16-Bit Registers & Flags

> **Level Goal**: Master the core 16-bit x86 CPU registers (`AX`, `BX`, `CX`, `DX`, `SI`, `DI`, `SP`, `BP`, `IP`), understand high/low byte splitting (`AH`/`AL`), and learn how CPU status flags (`ZF`, `CF`, `SF`, `IF`) drive decisions.

---

## 🏛️ 1. The 16-Bit Register Architecture

In 16-bit Real Mode, the CPU has several groups of hardware registers located directly on the processor silicon:

```
┌──────────────────────────────────────────────────────────────┐
│                  GENERAL PURPOSE REGISTERS                   │
│                                                              │
│  15                          8 7                           0 │
│ ┌─────────────────────────────┬─────────────────────────────┐│
│ │             AH              │             AL              ││ ◄── AX (Accumulator, 16-bit)
│ ├─────────────────────────────┼─────────────────────────────┤│
│ │             BH              │             BL              ││ ◄── BX (Base Register, 16-bit)
│ ├─────────────────────────────┼─────────────────────────────┤│
│ │             CH              │             CL              ││ ◄── CX (Counter Register, 16-bit)
│ ├─────────────────────────────┼─────────────────────────────┤│
│ │             DH              │             DL              ││ ◄── DX (Data Register, 16-bit)
│ └─────────────────────────────┴─────────────────────────────┘│
└──────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────┐
│                  POINTER & INDEX REGISTERS                   │
│                                                              │
│  15                                                        0 │
│ ┌───────────────────────────────────────────────────────────┐│
│ │                     SI (Source Index)                     ││ ◄── String Source Pointer
│ ├───────────────────────────────────────────────────────────┤│
│ │                  DI (Destination Index)                   ││ ◄── String Destination Pointer
│ ├───────────────────────────────────────────────────────────┤│
│ │                    BP (Base Pointer)                      ││ ◄── Stack Frame Base
│ ├───────────────────────────────────────────────────────────┤│
│ │                   SP (Stack Pointer)                      ││ ◄── Current Top of Stack
│ └───────────────────────────────────────────────────────────┘│
└──────────────────────────────────────────────────────────────┘
```

---

## 🔍 2. General-Purpose Registers & Byte Splitting

The four primary data registers (`AX`, `BX`, `CX`, `DX`) can be accessed as a single 16-bit word or as two independent 8-bit bytes (High `H` and Low `L`):

| Register | 16-bit Full Word | High 8-bit Byte | Low 8-bit Byte | Primary Hardware Roles |
| :--- | :--- | :--- | :--- | :--- |
| **Accumulator** | `AX` | `AH` | `AL` | Arithmetic, BIOS service numbers (`AH`), I/O |
| **Base** | `BX` | `BH` | `BL` | Base pointer for memory addressing, table base |
| **Counter** | `CX` | `CH` | `CL` | Loop counter (`loop`), bit shift counts (`CL`) |
| **Data** | `DX` | `DH` | `DL` | I/O port addresses, disk drive index, math overflow |

### 💡 Example of Byte Splitting in Action:
```nasm
mov ax, 0x1234      ; AX is now 0x1234 (AH = 0x12, AL = 0x34)
mov al, 0x99        ; AL is overwritten with 0x99
; What is the value of AX now? AX is 0x1299!
```

---

## 🎯 3. Index & Pointer Registers

Unlike `AX`–`DX`, index and pointer registers **cannot** be split into high/low bytes:

1. **`SI` (Source Index)**: Points to source data in memory for string operations (`lodsb`, `movsb`).
2. **`DI` (Destination Index)**: Points to destination buffer for string operations (`stosb`, `movsb`).
3. **`SP` (Stack Pointer)**: Stores the memory offset of the top of the stack. Modified automatically by `push` (decrements `SP`) and `pop` (increments `SP`).
4. **`BP` (Base Pointer)**: Used to establish fixed stack frames for passing function arguments and local variables.

---

## 🚩 4. The `FLAGS` Register (Condition Codes)

The `FLAGS` register contains single-bit flags updated automatically after arithmetic, logical, or comparison instructions:

```
 Bit:  15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
      ┌──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┐
      │  │  │  │  │OF│DF│IF│TF│SF│ZF│  │AF│  │PF│  │CF│
      └──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┘
```

### The Most Important Flags for OS Development:
* **`ZF` (Zero Flag)**: Set to `1` if the result of an operation is **Zero**. Used by `jz` / `je`.
* **`CF` (Carry Flag)**: Set to `1` if an unsigned arithmetic operation generated a carry out or borrow. BIOS functions use `CF = 1` to report hardware errors!
* **`SF` (Sign Flag)**: Set to `1` if the result is negative (MSB = 1). Used by `js` / `jl`.
* **`OF` (Overflow Flag)**: Set to `1` if a signed arithmetic overflow occurred.
* **`IF` (Interrupt Flag)**: 
  * `1` = CPU responds to maskable hardware interrupts (set by `sti`).
  * `0` = CPU ignores hardware interrupts (cleared by `cli`).
* **`DF` (Direction Flag)**:
  * `0` = String operations increment pointers forward (`cld` - clear direction flag).
  * `1` = String operations decrement pointers backward (`std` - set direction flag).

---

## 💻 5. Code Demonstration

```nasm
[org 0x7c00]
[bits 16]

    cld                 ; Clear direction flag (string operations go forward)
    xor ax, ax          ; AX = 0, ZF is set to 1!
    mov bx, 0x1000      ; BX = 0x1000
    add bx, 0x0500      ; BX = 0x1500 (ZF cleared to 0)

    mov ah, 0x0E        ; AH = BIOS teletype mode
    mov al, 'A'         ; AL = ASCII character 'A' (AX is now 0x0E41)
    int 0x10            ; Call BIOS video interrupt to print 'A'

    jmp $

times 510 - ($ - $$) db 0
dw 0xaa55
```

---

## ❓ Concept Check Quiz

1. **If register `BX` holds `0xCAFE`, what value is in register `BL`? What value is in `BH`?**
2. **Can you execute `mov spl, 0x10` to modify only the lower 8 bits of the Stack Pointer? Why or why not?**
3. **When a BIOS disk read function fails, which CPU flag is set to `1` to signal the error?**

---

## 🎯 Level 4 Hands-on Quest

1. Create directory `solutions/level_04_x86_registers/`.
2. Write a program that manipulates `AH`, `AL`, `BX`, and `CX`.
3. Use `add`, `sub`, or `cmp` to trigger the Zero Flag (`ZF`) and Carry Flag (`CF`).
4. Assemble and verify register states with QEMU or debug logs.
