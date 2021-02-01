;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strlen.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2021/01/04 13:49:55 by mviudes           #+#    #+#              #
;#    Updated: 2021/01/04 13:51:57 by mviudes          ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

	global	_ft_strlen
	section	.text

_ft_strlen:
	mov	rax, 0
_while:
	inc	rax
	cmp	BYTE[rdi + rax],0
	jne	_while
	ret
