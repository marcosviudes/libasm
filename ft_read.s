;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_read.s                                          :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: mviudes <marvin@42.fr>                     +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2021/04/22 20:41:42 by mviudes           #+#    #+#              #
;#    Updated: 2021/04/22 20:41:45 by mviudes          ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #


	global		_ft_read
	section	.text
	extern ___error
_ft_read:
;	mov	r8, rdx
	mov	rax, 0x2000003
	syscall
	jc	error
;	mov	rax,r8
	ret
error:
	push rax
	call ___error
	mov rdx, rax
	pop rax
	mov [rdx], rax
	mov	rax, -1
	ret
