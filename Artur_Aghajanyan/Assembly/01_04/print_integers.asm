%macro exit 0
	mov rax, 60
	mov rdi, 0
	syscall
%endmacro

%macro printRAX 2
	mov rcx, %2
	mov rbx, 10
	mov [rcx], rbx
	inc rcx
	mov [%1], rcx
%endmacro


%macro RAXLoop 1

 %%printRAXLoop:
	mov rdx, 0
	mov rbx, 10
	div rbx
	push rax
	add rdx, 48

	mov rcx, [%1]
	mov [rcx], dl
	inc rcx
	mov [%1], rcx
	
	pop rax
	cmp rax, 0
	jne %%printRAXLoop
%endmacro

%macro RAXLoop2 2
 %%printRAXLoop2:
	mov rcx, [%1]
	
	mov rax, 1
	mov rdi, 1
	mov rsi, rcx
	mov rdx, 1
	syscall

	mov rcx, [%1]
	dec rcx
	mov [%1], rcx

	cmp rcx, %2
	jge %%printRAXLoop2
%endmacro
