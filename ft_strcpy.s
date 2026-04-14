global ft_strcpy

ft_strcpy:
    push rbp
    mov rbp, rsp

    mov rcx, 0
    .loop:
        cmp byte [rsi + rcx], 0
        je .end
        mov al, byte [rsi + rcx]
        mov byte [rdi + rcx], al
        inc rcx
        jmp .loop

    .end:
        mov byte [rdi + rcx], 0
        mov rax, rdi

    pop rbp
    ret