%include "print_integers.asm"



section .bss
	digitSpace resb 100
	digitSpacePos resb 8

section .text
	global _start

_start:
	mov rax, 2021
	printRAX digitSpacePos, digitSpace
	RAXLoop digitSpacePos
	RAXLoop2 digitSpacePos, digitSpace
	exit
	
