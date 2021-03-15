/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:14:04 by mviudes           #+#    #+#             */
/*   Updated: 2021/03/04 14:00:08 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libasm.h"

void ft_bzero(char *buffer, int size)
{
	while (size--)
		*buffer++ = 0;
}

void	print_strlen(char* string){
	printf("\t'%s' = ", string);
	printf("%d (%d)\n", ft_strlen(string), (int)strlen(string));
}

void	print_strcpy(char* dest, char *src){
	char ret[1024];
	char *_dest = strdup(dest);
	char *_src = strdup(src);
	
	printf("\tcopy src: '%s', to dest: '%s'\n", src, dest);
	strcpy(_dest, _src);
	printf("\t\t%s     '%s'\n","strcpy ret:", _dest);
	free(_dest);
	free(_src);
	_dest = strdup(dest);
	_src = strdup(src);
	ft_strcpy(_dest, _src);
	printf("\t\t%s '%s'","ft_strcpy ret: ",_dest);
	printf("\n\n");
	free(_dest);
	free(_src);
}

void	print_strcmp(char *string1, char *string2)
{
	int a;
	int b;

	printf("\ts1: '%s' s2: '%s'", string1, string2);
	a = strcmp(string1, string2);
	b = ft_strcmp(string1, string2);
	printf(" ret: %i (%i)", a, b);
	printf("\n");
}

void	print_strdup(char *string)
{	
	char	*ret;

	ret = strdup(string);
	printf("\t\tstrdup ret:	'%s'\n", string);
	free(ret);
	ret = ft_strdup(string);
	printf("\t\tft_strdup ret:	'%s'\n", string);
	free(ret);
}

void	print_write(int fd, char *buff)
{
	int		ret;

	printf("\t");
	ret = write(fd, buff, strlen(buff));
	printf("(%i)", ret);
	write(1,"\n\t",2);
	ret = ft_write(fd, buff, strlen(buff));
	printf("(%i)", ret);
}
int		main()
{

	char *string = "Hello World";
	char *empty = "";
	char buff[150] = {0};
	
	printf("TEST FT_STRLEN\n");
	print_strlen(string);
	print_strlen(empty);
	print_strlen("asdfghijklmnopqrstuvwxyz0123456789");
	print_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et");
	print_strlen("1");
	printf("\tErrno: %d", errno);
	printf("\n");

	#ifndef DEBUG
		getchar();
		system("clear");
	#endif
	
	printf("TEST FT_STRCPY\n");
	print_strcpy(string, "pene");
	print_strcpy("me cago en la puta", string);
	print_strcpy(empty, string);
	print_strcpy(string, empty);
//	print_strcpy(buff, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et");

	#ifndef DEBUG
		getchar();
		system("clear");
	#endif

	printf("TEST FT_STRCMP\n");
	print_strcmp(string, empty);
	print_strcmp(empty, string);
	print_strcmp("iguales", "");
	print_strcmp("", "iguales");
	print_strcmp(string, "asdfghijklmnopqrstuvwxyz0123456789");
	print_strcmp(buff,string);
	print_strcmp(string, "pene");

	#ifndef DEBUG
		getchar();
		system("clear");
	#endif

	printf("TEST FT_STRDUP\n");
	print_strdup("pene");
	print_strdup(string);
	print_strdup("");

	#ifndef DEBUG
		getchar();
		system("clear");
	#endif

	printf("TEST FT_WRITE");
	print_write(1,"");
	
	#ifndef DEBUG
		getchar();
		system("clear");
	#endif
	return (0);
}

/*Lorem ipsum dolor sit amet, consectetur adipiscing elit, 
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
 Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris
 nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in 
 reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
  Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia 
  deserunt mollit anim id est laborum.*/
