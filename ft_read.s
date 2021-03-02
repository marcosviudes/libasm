	global		_ft_read
	section	.text
	extern
_ft_read:
	mov	r8, rdx
	mov	rax, 0x2000003
	syscall
	jc	error
	mov	rax,r8
	ret
error:
	mov	rax, -1
	ret