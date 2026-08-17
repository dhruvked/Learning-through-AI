# 🧩 Level 5 Study Guide: Real Mode Segmentation & Memory Addressing

> **Level Goal**: Master the `Segment:Offset` addressing model, learn the physical address formula, understand the 4 segment registers (`CS`, `DS`, `SS`, `ES`), and avoid the infamous segment aliasing bug at `0x7C00`.

---

## 🧮 1. The 16-Bit Register vs 20-Bit Bus Dilemma

In the original 8086 processor:
* Internal CPU registers were **16 bits** wide ($2^{16} = 65,536\text{ bytes} = 64\text{ KB}$).
* The external memory address bus was **20 bits** wide ($2^{20} = 1,048,576\text{ bytes} = 1\text{ MB}$).

How can a 16-bit register point to 1 MB of memory?

Intel invented **Memory Segmentation**: dividing memory into overlapping 64 KB segments, where two 16-bit numbers (**Segment** and **Offset**) combine to create a **20-bit Physical Address**.

---

## 📐 2. The Segment Translation Formula

To compute the physical address from a `Segment:Offset` pair, the CPU shifts the Segment left by 4 bits (multiplies by $16$ / `0x10`) and adds the Offset:

$$\mathbf{\text{Physical Address} = (\text{Segment} \times 16) + \text{Offset}}$$

In Hexadecimal notation, multiplying by 16 is equivalent to adding a `0` to the right of the segment:

```text
Example: Given Segment = 0x1234, Offset = 0x0567:

    Segment:      0 0 0 1   0 0 1 0   0 0 1 1   0 1 0 0  (0x1234)
    Shift << 4: 0 0 0 1   0 0 1 0   0 0 1 1   0 1 0 0   0 0 0 0  (0x12340)
  + Offset:                               0 0 0 0   0 1 0 1   0 1 1 0   0 1 1 1  (0x0567)
  ─────────────────────────────────────────────────────────────────────────────
    Physical:   0 0 0 1   0 0 1 0   1 0 0 0   1 0 0 1   0 1 1 1  (0x128A7)

Calculation: 0x12340 + 0x0567 = 0x128A7
```

---

## 🏛️ 3. The 4 Real Mode Segment Registers

| Segment Register | Name | Default Paired Register | Description / Purpose |
| :--- | :--- | :--- | :--- |
| **`CS`** | **Code Segment** | `IP` (Instruction Pointer) | Points to segment containing current executing code (`CS:IP`). |
| **`DS`** | **Data Segment** | General variables, `SI`, `BX` | Default segment for memory variables and data reads (`DS:Offset`). |
| **`SS`** | **Stack Segment** | `SP` and `BP` | Points to the 64 KB segment containing the stack (`SS:SP`). |
| **`ES`** | **Extra Segment** | `DI` | Used as destination for string ops (`ES:DI`) and disk load buffers. |

---

## ⚠️ 4. The `0x7C00` Segment Aliasing Trap

Because segments overlap every 16 bytes, **multiple different `Segment:Offset` pairs refer to the exact same physical address in RAM**:

$$\text{Segment } \mathbf{0x0000} : \text{Offset } \mathbf{0x7C00} \implies 0\text{x}0000 \times 16 + 0\text{x}7C00 = \mathbf{0\text{x}07C00}$$
$$\text{Segment } \mathbf{0x07C0} : \text{Offset } \mathbf{0x0000} \implies 0\text{x}07C0 \times 16 + 0\text{x}0000 = \mathbf{0\text{x}07C00}$$

### Why this creates subtle bugs:
* When your code uses `[org 0x7c00]`, NASM calculates all label offsets assuming an offset starting from `0x7C00`.
* Therefore, your **Data Segment (`DS`) MUST be set to `0x0000`**!
* If `DS` is left uninitialized or set to `0x07C0` by the BIOS, your variable lookups will compute:
  $$\text{Physical Address} = (0\text{x}07C0 \times 16) + (0\text{x}7C00 + \text{offset}) = 0\text{x}07C00 + 0\text{x}7C00 = \mathbf{0\text{x}0F800} \quad \text{❌ (Corrupted!)}$$

---

## 💻 5. Crucial Assembly Syntax Rules for Segments

### Rule 1: You cannot load a literal value directly into a segment register
```nasm
mov ds, 0x0000      ; ❌ ILLEGAL instruction on x86!

; ✅ Correct way: Move through a General Purpose Register (AX)
xor ax, ax          ; AX = 0
mov ds, ax          ; DS = 0
mov es, ax          ; ES = 0
mov ss, ax          ; SS = 0
```

### Rule 2: Segment Override Prefix
By default, `mov al, [bx]` accesses memory through `DS` (`DS:BX`). You can explicitly override the segment:
```nasm
mov al, [es:bx]     ; Reads byte at physical address (ES * 16 + BX)
mov al, [cs:my_str] ; Reads byte embedded inside the code segment (CS)
```

---

## ❓ Concept Check Quiz

1. **What is the 20-bit physical address of `0x2000:0x0450`?**
2. **What is the 20-bit physical address of `0x0000:0xB800`? What about `0xB800:0x0000`?**
3. **If you have `[org 0x7c00]` at the top of your file, what must `DS` be initialized to?**

---

## 🎯 Level 5 Hands-on Quest

1. Create directory `solutions/level_05_segmentation/`.
2. Write a bootloader that properly initializes `DS`, `ES`, and `SS` to `0x0000`.
3. Use a segment override prefix (e.g., `[es:bx]`) to read/write data in a different segment.
4. Calculate physical addresses manually and verify against the NASM listing file.
