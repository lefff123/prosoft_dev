section .data
    repeat1 db "Enter your string: ", 0
    repeat2 db "Reversed string: ", 0

section .bss
    reverse resb 100

global _start

section .text
_start:
    ; вывод меню
    mov rax, 1
    mov rdi, 1
    mov rsi, repeat1
    mov rdx, 18
    syscall

    ; чтение выбора
    mov rdi, reverse

    read:
    mov rax, 0
    mov rsi, rdi
    mov rdx, 1
    syscall

    cmp byte[rdi], 10
    je end_read

    inc rdi
    mov rax, rdi
    sub rax, reverse
    cmp rax, 99
    jl read

end_read:
    mov byte[rdi], 0
    
    ; Вывод сообщения "Reversed string: "
    mov rax, 1
    mov rdi, 1
    mov rsi, repeat2
    mov rdx, 17
    syscall

    dec rdi

    output:
    mov rax, 1
    mov rdi, 1
    mov rsi, rdi
    mov rdx, 1
    syscall
    dec rdi

    cmp rdi, reverse
    jge output

    mov rax, 60
    mov rdi, 0
    syscall