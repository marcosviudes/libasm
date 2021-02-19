	global		_ft_strcmp
	section	.text

_ft_strcmp:
	mov rcx, 0
	
_while:
	mov	al, BYTE[rdi + rcx]
	mov	dl, BYTE[rsi + rcx]
	cmp	dl, 0
	je	_ret
	cmp al, 0
	je	_ret
	cmp	al, dl
	jne	_ret
	inc	rcx
	jmp	_while
_ret:
	movzx	rdx, dl
	movzx	rax, al
	sub	rax, rdx
	ret