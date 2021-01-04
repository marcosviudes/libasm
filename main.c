/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:14:04 by mviudes           #+#    #+#             */
/*   Updated: 2021/01/04 14:56:50 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int		ft_strlen(char	const *str);

void	print_strlen(char* string){
	printf("\t'%s' = %d (%d)\n", string, ft_strlen(string), (int)strlen(string));
}
int		main()
{
	char *string = "Hello World";

	printf("TEST FT_STRLEN\n");
	print_strlen("Hello world");
	print_strlen("");
	print_strlen("asdfghijklmnopqrstuvwxyz0123456789");
	print_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et");
	print_strlen("1");
	printf("\n");

	//check_strlen();
	return (0);
}

/*Lorem ipsum dolor sit amet, consectetur adipiscing elit, 
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
 Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris
 nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in 
 reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
  Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia 
  deserunt mollit anim id est laborum.*/