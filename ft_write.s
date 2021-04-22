	global		_ft_write
	section	.text
	extern ___error
_ft_write:
	mov	r8, rdx
	mov	rax, 0x2000004
	syscall
	jc	error
	mov	rax,r8
	ret
error:

	push rax
	call ___error
	mov rdx, rax
	pop rax
	mov [rdx], rax
	mov rax, -1
	ret