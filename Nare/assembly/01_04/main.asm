%include "macro.asm"

section .data
    text1 db "Enter first number - "
    len1 equ $- text1
    text2 db "Enter second number - "
    len2 equ $- text2      
    text3 db "num1 + num2 = " 
    len3 equ $- text3
              
    text4 db 10
   
                                
section .bss
  
    num1 resb 2
    num2 resb 2
    res resb 1
    
section .text
global _start
_start:
    print text1, len1
    get num1, 2
    print text2, len2
    get num2, 2
    print text3, len3
    sum num1, num2
    print text4,1

    mov rax, 60
    mov rdi,0
    syscall
