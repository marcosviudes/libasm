;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strcpy.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2021/01/22 13:51:26 by mviudes           #+#    #+#              #
;#    Updated: 2021/02/02 12:15:19 by mviudes          ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

global		_ft_strcpy

section .text

_ft_strcpy:
	mov rcx, 0
_while:
	mov	dl, BYTE [rsi + rcx]
	mov	BYTE[rdi + rcx], dl
	inc	rcx 
	cmp dl,0
	jne	_while
	jmp exit
exit:
	mov	rax, rdi
	ret
