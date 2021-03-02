	global	_ft_strdup
	section	.text
	extern	_ft_strlen
	extern	_ft_strcpy
	extern	_malloc

_ft_strdup:
	call	_ft_strlen
	push	rdi
	mov	rdi, rax
	call	_malloc
	mov	rdi, rax
	pop	rsi
	call	_ft_strcpy
	ret