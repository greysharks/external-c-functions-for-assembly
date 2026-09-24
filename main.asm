extern lossless_multiplication
extern exit

section .data
	var_a DD 0xFFFFFFFF
	var_b DD 0xFFFFFFFF

section .text

global main
main:
	PUSH var_b
	PUSH var_a
	CALL lossless_multiplication

	MOV ebx, eax
	MOV eax, [ebx]
	MOV edx, [ebx + 0x4]

	PUSH 1
	CALL exit
