section .data
    helo db "It is an assembly calc!", 10
         db "Put 1 if you want to sum, put 2 if you want to subtract", 10  
         db "If you want to exit put 0", 10, 0
    repeat1 db "put the first integer: ", 0
    repeat2 db "put the second integer: ", 0
    err db "error", 10, 0
    newline db 10

section .bss
    number1 resq 1
    number2 resq 1
    sign resb 1
    buffer resb 32
    output resb 32

global _start

section .text
_start:
menu_loop:
    mov qword [number1], 0
    mov qword [number2], 0
    
    ;вывод меню
    mov rax, 1
    mov rdi, 1
    mov rsi, helo
    mov rdx, 107
    syscall

    ; чтение выбора
    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 32
    syscall

    call atoi

    cmp rax, 0
    je exit
    cmp rax, 1 
    je sum
    cmp rax, 2
    je subtract
    jmp menu_loop

sum:
    call enter_nums
    mov rax, [number1]
    add rax, [number2]
    call to_str
    
    ; вывод результата
    mov rax, 1
    mov rsi, rdi
    mov rdi, 1
 
    mov rdx, output + 32
    sub rdx, rdi        ; вычисляем длину
    syscall
    
    ; Новая строка
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall
    
    jmp menu_loop

subtract:
    call enter_nums
    mov rax, [number1]
    sub rax, [number2]
    call to_str
    
    ; вывод результата
    mov rax, 1
    mov rsi, rdi
    mov rdi, 1
    mov rdx, output + 32
    sub rdx, rdi
    syscall
    
    ; новая строка
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall
    
    jmp menu_loop

exit:
    mov rax, 60
    xor rdi, rdi
    syscall

enter_nums:
  
    mov rax, 1
    mov rdi, 1
    mov rsi, repeat1
    mov rdx, 22
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 32
    syscall

    call atoi
    mov qword [number1], rax

   
    mov rax, 1
    mov rdi, 1
    mov rsi, repeat2
    mov rdx, 23
    syscall

    
    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 32
    syscall

    call atoi
    mov qword [number2], rax
    ret

to_str:
    mov rdi, output
    add rdi, 31
    mov byte [rdi], 0   
    mov rsi, rax      
    mov rbx, 10
    
    test rsi, rsi
    jns positive

    neg rsi
    mov byte [sign], '-'
    jmp conv
    

    positive:
        mov byte [sign], '+'

    conv:
        test rsi, rsi
        je dn
        
        ; ПОДГОТОВКА ДЕЛЕНИЯ
        mov rax, rsi        ; делимое в rax
        xor rdx, rdx        
        div rbx             ; rax частное, rdx остаток
        
        mov rsi, rax        ; обновляем число
        
        add dl, '0'         
        dec rdi
        mov byte [rdi], dl
        
        jmp conv

    dn: 
        dec rdi
        mov al, [sign]
        mov byte[rdi], al
        ret

atoi:
    mov rdi, buffer
    xor rax, rax        
    xor rcx, rcx       
   
    convert:
        mov cl, byte [rdi]  
        
        ; проверка конца строки
        test cl, cl
        je done
        cmp cl, 10          ; новая строка
        je done
        cmp cl, 13          ; возврат каретки
        je done
        
        ; Проверка что это цифра
        cmp cl, '0'
        jl error
        cmp cl, '9'
        jg error
        
        
        sub cl, '0'
        
        ; уножение на 10 и добавление цифры
        imul rax, 10
        add rax, rcx
        
        inc rdi
        jmp convert

    error:
        
        mov rax, 1
        mov rdi, 1
        mov rsi, err
        mov rdx, 6
        syscall
        mov rax, 60
        syscall

    done:
        ret
