[org 0x7c00]
[bits 16]

    cli
    xor ax, ax
    mov ds, ax
    mov ss, ax
    mov sp, 0x7c00
    sti

hang:
    jmp hang

times 510 - ($-$$) db 0
dw 0xaa55