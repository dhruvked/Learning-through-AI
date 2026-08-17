# 🗺️ Level 2 Study Guide: BIOS & Real Mode Memory Map

> **Level Goal**: Master the 1 MB Real Mode memory layout, understand reserved hardware regions (IVT, BDA, Video RAM, ROM), and learn where it is safe to place your OS stack, buffers, and kernel stages.

---

## 🧭 1. The 1 Megabyte Real Mode Address Space

When the x86 CPU starts in Real Mode, it has a **20-bit physical address bus** ($2^{20} = 1,048,576\text{ bytes} = 1\text{ MB}$).

Every byte of physical RAM from `0x00000` to `0xFFFFF` has a defined role established by IBM PC architecture standards:

```text
Physical Address       Size       Purpose / Description
─────────────────────────────────────────────────────────────────────────────
0x00000 ─ 0x003FF      1 KB       Interrupt Vector Table (IVT) - 256 ISR pointers
0x00400 ─ 0x004FF      256 B      BIOS Data Area (BDA) - Keyboard, timers, video state
0x00500 ─ 0x07BFF     ~30 KB      Guaranteed Free Conventional RAM (Safe for Stack/Data)
0x07C00 ─ 0x07DFF      512 B      YOUR BOOTLOADER (Loaded here by BIOS)
0x07E00 ─ 0x7FFFF     ~480 KB     Free Conventional RAM (Where we load our Kernel!)
0x80000 ─ 0x9FFFF     128 KB      Extended BIOS Data Area (EBDA) & Upper Low Memory
0xA0000 ─ 0xAFFFF      64 KB      VGA Graphics Framebuffer (Mode 13h, etc.)
0xB0000 ─ 0xB7FFF      32 KB      Monochrome Text Video Memory
0xB8000 ─ 0xBFFFF      32 KB      Color Text Video Memory (VGA 80x25 text mode)
0xC0000 ─ 0xC7FFF      32 KB      Video Adapter BIOS ROM
0xC8000 ─ 0xEFFFF     160 KB      Expansion Device ROMs (NICs, SCSI controllers)
0xF0000 ─ 0xFFFFF      64 KB      Motherboard System BIOS ROM (Reset vector @ 0xFFFF0)
```

---

## 🔬 2. Deep Dive: The Critical Reserved Regions

### 1. The Interrupt Vector Table (IVT) — `0x00000` to `0x003FF`
* Stores 256 entries for software and hardware interrupts (`int 0x00` through `int 0xFF`).
* Each entry is a **4-byte far pointer** (`Segment:Offset` = 2 bytes offset, 2 bytes segment):
  $$\text{Table Size} = 256 \times 4\text{ bytes} = 1024\text{ bytes} = 1\text{ KB}$$
* **Rule**: If you overwrite `0x00000 – 0x003FF` without disabling interrupts (`cli`), any BIOS interrupt or hardware timer tick will jump to corrupted memory and instantly crash the CPU.

---

### 2. The BIOS Data Area (BDA) — `0x00400` to `0x004FF`
* 256 bytes where BIOS maintains live hardware state:
  * `0x0410`: Hardware equipment word.
  * `0x0417`: Keyboard shift/ctrl/alt key flags.
  * `0x0449`: Current video mode number.
  * `0x0450`: Cursor row & column positions.
  * `0x046C`: Timer ticks counter (increments 18.2 times per second).

---

### 3. Video Memory (VRAM) — `0xA0000` to `0xBFFFF`
* This RAM is **not physical motherboard RAM**; it is mapped directly into the Video Graphics Card (Memory-Mapped I/O).
* `0xB8000`: Color Text Mode buffer ($80 \text{ columns} \times 25 \text{ rows}$).
  * Writing ASCII characters and color attribute bytes to `0xB8000` immediately draws pixels on the monitor without calling any BIOS functions!

---

### 4. Free Usable Memory Regions
When building your OS bootloader and early kernel stages:
* **Region 1**: `0x00500` to `0x07BFF` (~30 KB)
  * Excellent place to initialize your **Stack Pointer (`SP`)** growing downwards from `0x7C00` towards `0x0500`.
* **Region 2**: `0x07E00` to `0x7FFFF` (~480 KB)
  * The primary zone to load your **Stage 2 Bootloader** or **C Kernel Binary** from disk sectors.

---

## 📐 3. Memory Layout Diagram for Tier 1

```
0x00000  ┌──────────────────────────────────────────────┐
         │ Interrupt Vector Table (IVT) - 1 KB          │  ⚠️ Reserved
0x00400  ├──────────────────────────────────────────────┤
         │ BIOS Data Area (BDA) - 256 B                 │  ⚠️ Reserved
0x00500  ├──────────────────────────────────────────────┤
         │                                              │
         │  ◄─── Stack grows downward from 0x7C00       │  🟢 Safe for Stack
         │                                              │
0x07C00  ├──────────────────────────────────────────────┤
         │  ★ Bootloader (512 Bytes)                    │  🚀 Active Code
0x07E00  ├──────────────────────────────────────────────┤
         │                                              │
         │  Loaded Kernel & Second Stage                │  🟢 Safe for Kernel
         │                                              │
0x80000  ├──────────────────────────────────────────────┤
         │ Extended BIOS Data Area (EBDA)               │  ⚠️ Reserved
0xA0000  ├──────────────────────────────────────────────┤
         │ Video Display RAM (VGA 0xB8000)              │  📺 Screen Buffer
0xC0000  ├──────────────────────────────────────────────┤
         │ BIOS ROM / Hardware ROMs                     │  🔒 Read-Only
0xFFFFF  └──────────────────────────────────────────────┘
```

---

## 💻 4. Code Pattern: Setting a Safe Stack in Real Mode

In x86 assembly, the stack grows **downwards** (from high addresses to lower addresses when you `push`).

Because our bootloader starts at `0x7C00`, setting the stack top to `0x7C00` ensures our stack grows downward through the safe free memory range `0x00500 – 0x07BFF` without colliding with our code:

```nasm
[org 0x7c00]
[bits 16]

    cli             ; 1. Disable interrupts while reconfiguring stack registers
    xor ax, ax      ; 2. Clear AX (AX = 0)
    mov ds, ax      ; 3. Set Data Segment to 0x0000
    mov ss, ax      ; 4. Set Stack Segment to 0x0000
    mov sp, 0x7c00  ; 5. Set Stack Pointer to 0x7c00 (grows downwards into safe RAM)
    sti             ; 6. Re-enable interrupts

    ; Now memory and stack are safely configured!
    jmp $

times 510 - ($ - $$) db 0
dw 0xaa55
```

---

## ❓ Concept Check Quiz

1. **If our bootloader is at `0x7C00` and `SP` is set to `0x7C00`, what physical memory address receives the data when you execute `push ax`?**
2. **Why must you NEVER let your stack or data overwrite `0x00000 – 0x003FF` in Real Mode while interrupts are enabled?**
3. **At what physical memory address does color text mode VGA video RAM start?**

---

## 🎯 Level 2 Hands-on Quest

1. Create directory `solutions/level_02_bios_memory_map/`.
2. Inspect the Real Mode memory map and write a bootloader that properly configures `SS = 0x0000` and `SP = 0x7C00`.
3. Assemble with `nasm` and verify execution in `qemu`.
