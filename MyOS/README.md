# 🖥️ MyOS — Bare-Metal Operating System Track

> A 100-level roadmap from bare-metal x86 Assembly to a 32-bit multitasking Unix-like Operating System kernel in C.

---

## 🗺️ Quick Navigation

* 📜 **[Full 100-Level Syllabus](syllabus.md)**
* 📊 **[Progress & Quest Tracker](progress.md)**
* 📂 **[Solutions Directory](solutions/)**

---

## 📚 Tier 1 Study Guides (Boot & Assembly Fundamentals)

| Level | Topic | Study Guide | Solution Folder |
| :---: | :--- | :--- | :--- |
| **01** | The Boot Sector & BIOS Boot Sequence | [📖 Level 1 Guide](solutions/level_01_boot_sector/level_01_guide.md) | [`solutions/level_01_boot_sector/`](solutions/level_01_boot_sector/) |
| **02** | BIOS & Real Mode 1MB Memory Map | [📖 Level 2 Guide](solutions/level_02_bios_memory_map/level_02_guide.md) | [`solutions/level_02_bios_memory_map/`](solutions/level_02_bios_memory_map/) |
| **03** | NASM Assembly Directives & Binaries | [📖 Level 3 Guide](solutions/level_03_nasm_fundamentals/level_03_guide.md) | [`solutions/level_03_nasm_fundamentals/`](solutions/level_03_nasm_fundamentals/) |
| **04** | x86 16-Bit Registers & CPU Flags | [📖 Level 4 Guide](solutions/level_04_x86_registers/level_04_guide.md) | [`solutions/level_04_x86_registers/`](solutions/level_04_x86_registers/) |
| **05** | Real Mode Segmentation & Addressing | [📖 Level 5 Guide](solutions/level_05_segmentation/level_05_guide.md) | [`solutions/level_05_segmentation/`](solutions/level_05_segmentation/) |
| **06** | Addressing Modes & Data Movement | [📖 Level 6 Guide](solutions/level_06_addressing_modes/level_06_guide.md) | [`solutions/level_06_addressing_modes/`](solutions/level_06_addressing_modes/) |

---

## 🛠️ Toolchain Prerequisites

* **Assembler**: [NASM](https://www.nasm.us/) (`nasm -f bin bootloader.asm -o boot.bin`)
* **Emulator**: [QEMU](https://www.qemu.org/) (`qemu-system-x86_64 -fda boot.bin` or `qemu-system-i386`)
* **C Compiler** (Later Tiers): `i686-elf-gcc` / `gcc`
