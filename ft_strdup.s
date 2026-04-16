global ft_strdup
extern malloc
extern __errno_location

ft_strdup:
    push rbp
    mov rbp, rsp

    mov rcx, 0
    .ft_strlen:
        cmp byte [rdi + rcx], 0
        je .malloc
        inc rcx
        jmp .ft_strlen

    .malloc:
        push rdi                            ; Sauvegarde la valeur de rdi (le premier argument)
        push rcx                            ; Sauvegarde de rcx (compteur)
        sub rsp, 8                          ; Realignement de la stack
        mov rdi, rcx                        ; Envoie du compteur dans rdi car malloc prend la taille dans rdi
        inc rdi                             ; Ajout de 1 pour le \0
        call malloc wrt ..plt               ; Prend la taille de rdi et retourne rax
        add rsp, 8                          ; Car on a utilise sub rsp, 8
        pop rcx                             ; Reset de la valeur de rcx
        pop rdi                             ; Reset de la valeur de rdi
        cmp rax, 0
        je .error
        mov r12, rax                        ; Sauvegarde du pointeur de malloc dans r12 (variable de 64bit)

    .ft_strcpy:
        mov rcx, 0
        .loop:
            cmp byte [rdi + rcx], 0
            je .end_of_strcpy
            mov al, byte [rdi + rcx]
            mov byte [r12 + rcx], al
            inc rcx
            jmp .loop

    .error:
        sub rsp, 8                          ; Realignement de la stack
        call __errno_location wrt ..plt
        add rsp, 8                          ; Car on a utilise sub rsp, 8
        mov dword [rax], 12                 ; Avec dword on precise la taille envoye dans rax (4 octets -> un int)
        mov rax, 0
        jmp .end


    .end_of_strcpy:
        mov byte [r12 + rcx], 0
        mov rax, r12

    .end:

    pop rbp
    ret