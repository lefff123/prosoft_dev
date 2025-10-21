section .data
    helo db 'Hello world!'
    scss dw 'success!'
    boom dw 'were screwed'


section .text
    global _start

    _start:
    mov rax,1
    mov rdi,1
    mov rsi, helo
    mov rdx, 12
    syscall


    cmp rax, 12
    ;подготавливаемся к выводу отчета
    mov rax,1
    mov rdi, 1

    jne bad

    good:
        mov rsi, scss
        mov rdx, 8
        mov rdi, 0 
        syscall
        jmp exit

    bad:
        mov rsi, boom
        mov rdx, 12
        mov rdi,1
        syscall

    exit:
        mov rax, 60
        syscall