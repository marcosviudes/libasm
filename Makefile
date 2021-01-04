#####################################
### CONFIG
#####################################
.DELETE_ON_ERROR:

NAME		= libasm.a
TEST_NAME	= test
AR			= ar rc
CC 			= gcc
CFLAGS		:= #-Wall -Wextra -Werror -Wpedantic -O3
NASM		= nasm
NFLAGS		:= -f macho64
DFLAGS		:= -g
RM			:= rm -rf

SRC_PATH	= src/
SRCS		= ft_strlen.s
OBJS		= $(SRCS:.s=.o)
MAIN		= main.c

#####################################
### RULES
#####################################

$(NAME):
	@$(NASM) $(NFLAGS) $(SRCS)
	@$(AR) $(NAME) $(OBJS)
	@echo "objs and $(NAME) created"
all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "Delete all obj"
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(TEST_NAME)
	@echo "Delete: $(NAME) and $(TEST_NAME)"

test: re
	@$(CC) $(CFLAGS) $(NAME) $(MAIN) -o $(TEST_NAME)
	@echo "Test compiled"
run:	test
	@echo "Running test\n"
	@clear echo "\n"
	@./test

re: fclean all

.PHONY:	all clean fclean re debug