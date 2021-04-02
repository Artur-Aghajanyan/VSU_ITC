SYS_WRITE equ 1
STD_OUT equ 1
SYS_READ equ 0
STD_IN equ 0

section .bss
    digitSpace resb 200
    digitSpacePos resb 20

%macro print 2
    mov rax, SYS_WRITE
    mov rdi, STD_OUT
    mov rsi, %1
    mov rdx, %2
    syscall
%endmacro

%macro get 2
    mov rax, SYS_READ
    mov rdi, STD_IN
    mov rsi, %1 
    mov rdx, %2
    syscall
%endmacro

%macro printNum 1

   mov rax, %1
   call _printRAX

_printRAX:
   mov rcx, digitSpace
   mov rbx, 10
   mov [rcx], rbx
   inc rcx
   mov [digitSpacePos], rcx

_printRAXLoop:
   mov rdx, 0
   mov rbx, 10
   div rbx
   push rax
   add rdx, 48

   mov rcx, [digitSpacePos]
   mov [rcx], dl
   inc rcx
   mov [digitSpacePos], rcx
   
   pop rax
   cmp rax, 0
   jne _printRAXLoop

_printRAXLoop2:
   mov rcx, [digitSpacePos]
    print rcx,1   

   mov rcx, [digitSpacePos]
   dec rcx
   mov [digitSpacePos], rcx

   cmp rcx, digitSpace
   jge _printRAXLoop2
%endmacro

%macro sum 2
    mov al, [%1]
    sub al, '0'

    mov bl, [%2]
    sub bl, '0'

    add al, bl
   ; add al, '0'


    mov [res],al
    printNum [res]
;    print res,1
%endmacro
