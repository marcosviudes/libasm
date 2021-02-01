#####################################
### CONFIG
#####################################
.DELETE_ON_ERROR:

NAME		= libasm.a
TEST_NAME	= test
AR  		= ar
ARFLAGS		= rc
CC  		= gcc
CFLAGS		:= #-Wall -Wextra -Werror -Wpedantic -O3
NASM		= nasm
NFLAGS		:= -f macho64
DFLAGS		:= -g
RM  		:= rm -rf

SRC_PATH	= src/
SRCS		= ft_strlen.s \
				ft_strcpy.s
OBJS		= $(SRCS:.s=.o)
MAIN		= main.c

#####################################
### RULES
#####################################

%.o : %.s
	$(NASM) $(NFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
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
debug:
	@$(CC) $(DFLAGS) $(NAME) $(MAIN) -o $(TEST_NAME) -D DEBUG=1
re: fclean all

.PHONY:	all clean fclean re debug
