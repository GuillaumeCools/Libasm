global ft_read
extern  __errno_location

ft_read:
    push rbp
    mov rbp, rsp

    mov rax, 0
    syscall
    cmp rax, 0
    jl  .error
    jmp .end

    .error:
        mov r8, rax
        neg r8
        call __errno_location wrt ..plt
        mov [rax], r8
        mov rax, -1
    .end:

    pop rbp
    ret