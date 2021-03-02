	global		_ft_write
	section	.text
	extern
_ft_write:
	mov	r8, rdx
	mov	rax, 0x2000004
	syscall
	jc	error
	mov	rax,r8
	ret
error:
	mov	rax, -1
	ret