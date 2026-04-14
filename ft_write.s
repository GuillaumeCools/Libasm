global ft_write
extern  __errno_location ; pour include une fonction de l'exterieur

ft_write:
    push rbp
    mov rbp, rsp

    mov rax, 1  ; On envoie 1 a rax car c'est le numero du syscall pour write sur Linux
    syscall
    cmp rax, 0
    jl  .error  ; jump si rax > 0
    jmp .end

    .error:
        mov r8, rax
        neg r8
        call __errno_location wrt ..plt ; a approfondir
        mov [rax], r8
        mov rax, -1
    .end:

    pop rbp
    ret