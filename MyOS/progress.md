# 📊 Progress Log — MyOS

- **Current Level**: Level 4
- **Current Tier**: Tier 1 (🌱 Boot & Assembly Fundamentals)
- **Status**: Level 4 - x86 16-Bit Registers & Flags (Ready to Start)
- **Total XP**: 300 XP
- **Badges Earned**: 
  - 🏆 **Boot Sector Pioneer** (Built 512-byte x86 bootloader with 0xAA55 signature)
  - 🗺️ **Memory Map Master** (Safely mapped IVT, BDA, and configured `SS:SP` at `0x7C00`)
  - ⚙️ **NASM Architect** (Mastered data definitions `db`/`dw`/`dd`, jump-over-data pattern, listing `.lst` analysis)

---

## 🎯 Active Quest

- **Guide**: [Level 4 Concept Study Guide](solutions/level_04_x86_registers/level_04_guide.md)
- **Task**: Master general-purpose registers (`AX`, `BX`, `CX`, `DX`), byte splitting (`AH`/`AL`, etc.), pointer/index registers (`SI`, `DI`, `SP`, `BP`), and CPU condition flags (`ZF`, `CF`, `SF`, `IF`). Write a bootloader demonstrating register arithmetic and flags.
- **File**: `MyOS/solutions/level_04_x86_registers/bootloader.asm`

---

## 📜 History & Assessment Log

| Date | Level | Assessment | Result | Notes |
|------|-------|------------|--------|-------|
| 2026-08-15 | Lvl 1 | Boot Sector & 0xAA55 Signature | ✅ Passed (+100 XP) | Wrote 512B bootloader, verified `EB FE` opcode and `55 AA` magic bytes. |
| 2026-08-20 | Lvl 2 | BIOS Memory Map & Stack Setup | ✅ Passed (+100 XP) | Mastered IVT, BDA, segment arithmetic, configured safe stack at `0x7C00`. |
| 2026-08-21 | Lvl 3 | NASM Fundamentals & Directives | ✅ Passed (+100 XP) | Mastered `db`/`dw`/`dd`, `$` vs `$$` padding formula, `.lst` analysis, jump-over-data. |
| 2026-08-21 | Lvl 4 | x86 Registers & Flags System | 🟡 Active Quest | Learning 16-bit register map and flag status conditions. |
