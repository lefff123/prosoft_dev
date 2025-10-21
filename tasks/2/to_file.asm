section .data
    filename db 'test.txt',0
    string db 'Hello world!'
    scss db 'success!'
    boom db 'were screwed'


section .bss
    fd resq 1

section .text
    global _start

    _start:
    ; создаем файл

    mov rax ,2
    mov rdi, filename
    mov rsi, 0o1102
    mov rdx, 0o644
    
    syscall

    mov [fd], rax

    ;записываем строку
    mov rax, 1
    mov rdi, [fd]
    mov rsi, string
    mov rdx, 12
    syscall


    cmp rax, 12 ; проверяем вывод в файл
    jne bad

    ;закрываем файл
    mov rax, 3
    mov rdi, [fd]
    syscall

    ;выводим строку

    mov rax,1
    mov rdi,1
    mov rsi, string
    mov rdx, 12
    syscall


    
    ;подготавливаемся к выводу отчета
    mov rax,1
    mov rsi, scss
    mov rdx, 8
    syscall
    mov rdi, 0 

    jmp exit

    bad:
        mov rsi, boom
        mov rdx, 11
        syscall
        mov rdi, 1

    exit:
        mov rax, 60
        syscall