global ft_strcmp

ft_strcmp:
    push    rbp
    mov     rbp, rsp

    mov rcx, -1
    .loop:
        inc rcx
        cmp byte [rdi + rcx], 0
        cmp byte [rsi + rcx], 0
        jz .end
        mov al, byte [rdi +rcx]
        mov bl, byte [rsi + rcx]
        cmp al, bl
        je .loop
        jmp .end

    .end:
    mov al, byte [rdi + rcx]
    mov bl, byte [rsi + rcx]
    sub al, bl
    movsx rax, al

    pop rbp
    ret