#####################################
### CONFIG
#####################################
.DELETE_ON_ERROR:

NAME		:= libasm.a
CC 			:= gcc
NASM		= nasm
CFLAGS		:= -Wall -Wextra -Werror -Wpedantic -O3
DFLAGS		:= -g
RM			:= rm -rf
MAIN		= main.c
SRCS_FILE	= ft_strlen.s
#SRCS_FILE	:= check_args.c \


#####################################
### RULES
#####################################

$(NAME):
	$(NASM) $(SRCS_FILE) -o $(NAME)
all: $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY:	all clean fclean re debug