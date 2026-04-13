global ft_strlen    ; Pour qu'il puisse etre visible de partout

ft_strlen:
    push    rbp
    mov     rbp, rsp

    mov rcx, 0
    .loop:
        cmp byte [rdi + rcx], 0
        je .end
        inc rcx
        jmp .loop
        
    .end:
    mov rax, rcx

    pop rbp
    ret