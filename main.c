/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:14:04 by mviudes           #+#    #+#             */
/*   Updated: 2021/04/22 20:49:52 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libasm.h"

int test_read()
{
	char *buff[40];
	int fd;
	char file[] = "read_test1.txt";
	errno = 0;
	memset(buff, '\0', sizeof(buff));

	printf("\tEXPECTED RET: %zd\n", read(1, buff, 40));
	printf("\tACTUAL RET: %zd\n", ft_read(1, buff, 40));
	printf("\n");
	printf("open file:\n");
	fd = open(file, O_RDONLY);
	printf("\tEXPECTED RET: %zd\n", read(fd, buff, 22));
	printf("\tERRNO: %d\n", errno);
	errno = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	printf("\tACTUAL RET: %zd\n", ft_read(fd, buff, 22));
	printf("\tERRNO: %d\n", errno);
	close(fd);
	errno = 0;
	printf("\n");
	printf("Errno Test:\n");
	printf("\tEXPECTED RET: %zd\n", read(-7, NULL, 40));
	printf("\tERRNO: %d\n", errno);
	errno = 0;
	printf("\tACTUAL RET: %zd\n", ft_read(-7, NULL, 40));
	printf("\tERRNO: %d\n", errno);
	printf("\n\n");
	return (0);
}

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

	errno = 0;
	write(1, "\t", 1);
	write(1, "write: ", 7);
	ret = write(fd, buff, strlen(buff));
	printf("(%i)", ret);
	printf("%i", errno);
	
	ft_write(1, "\t", 1);
	ft_write(1, "my_write: ", 9);
	ret = ft_write(fd, buff, strlen(buff));
	printf("(%i)", ret);
	printf("%i", errno);
	ft_write(1, "\n",1);	
}
void	print_read()//(int fd, char *buff)
{
	int		ret;
	char	*buff[40];

	ft_bzero(buff,sizeof(buff));
	errno = 0;
	printf("EXPECTED RET: %zd\n", read(1, buff, 40));
	printf("ACTUAL RET: %zd\n", ft_read(1, buff, 40));

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
	print_strcpy(string, "HOLA");
	print_strcpy("texto muy cristiano", string);
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
	print_strcmp(string, "texto");

	#ifndef DEBUG
		getchar();
		system("clear");
	#endif

	printf("TEST FT_STRDUP\n");
	print_strdup("texto");
	print_strdup(string);
	print_strdup("");

	#ifndef DEBUG
		getchar();
		system("clear");
	#endif

	write(1, "TEST FT_WRITE\n", 14);
	print_write(1,"prueba");
	print_write(1,"");
	print_write(69, "pnee");
	print_write(1, "hola");
	printf("\n");

	//print_write(, "hola");
	/*print_write(1,"hola");
	print_write(1,"prueba2");*/
	#ifndef DEBUG
		getchar();
		system("clear");
	#endif
	write(1, "TEST FT_READ\n", 14);
	test_read();
	return (0);
}

