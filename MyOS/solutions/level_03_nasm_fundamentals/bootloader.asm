[org 0x7c00]
[bits 16]
start:
    ; 1. Jump OVER our data to the code loop
    jmp main
; 2. Define our static data safely here
my_byte: db 1       ; 1 byte
my_word: dw 1       ; 2 bytes
my_dword: dd 1      ; 4 bytes
main:
    ; 3. Trap CPU here safely so it doesn't execute past this
    jmp $
; 4. Pad to 510 bytes and add boot signature
times 510 - ($ - $$) db 0
dw 0xaa55