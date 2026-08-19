# 📊 Progress Log — MyOS

- **Current Level**: Level 2
- **Current Tier**: Tier 1 (🌱 Boot & Assembly Fundamentals)
- **Status**: Level 2 - BIOS & Real Mode Memory Map (In Progress)
- **Total XP**: 100 XP
- **Badges Earned**: 🏆 Boot Sector Pioneer (Built 512-byte x86 bootloader with 0xAA55 signature)

---

## 🎯 Active Quest

- **Guide**: [Level 2 Concept Study Guide](solutions/level_02_bios_memory_map/level_02_guide.md)
- **Task**: Inspect the 1MB Real Mode memory layout. Write a bootloader that properly initializes segment registers (`DS = 0`, `ES = 0`), sets up a safe stack (`SS = 0`, `SP = 0x7C00`), and halts cleanly with interrupts disabled (`cli` / `hlt`).
- **File**: `MyOS/solutions/level_02_bios_memory_map/bootloader.asm`

---

## 📜 History & Assessment Log

| Date | Level | Assessment | Result | Notes |
|------|-------|------------|--------|-------|
| 2026-08-15 | Lvl 1 | Boot Sector & 0xAA55 Signature | ✅ Passed (+100 XP) | Wrote 512B bootloader, verified `EB FE` opcode and `55 AA` magic bytes. |
| 2026-08-19 | Lvl 2 | BIOS Memory Map & Stack Setup | 🟡 In Progress | Understanding IVT, BDA, and safe stack placement. |
