#ifndef LIBASM_H
# define LIBASM_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>

void	ft_bzero(char *buffer, int size);
int		ft_strlen(char	const *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

void	print_strlen(char* string);
void	print_strcpy(char* dest, char *src);
void	print_strcmp(char *string1, char *string2);
#endif