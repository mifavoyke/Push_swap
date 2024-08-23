NAME = push_swap
DIR_SRC = ./source
DIR_PRINTF = ./ft_printf
PRINTF = $(DIR_PRINTF)/libftprintf.a
DIR_LIBFT = ./libft
LIBFT = $(DIR_LIBFT)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I $(DIR_SRC) -I $(DIR_PRINTF)/Include -I $(DIR_LIBFT)
RM = rm -rf

SRC =	$(DIR_SRC)/find_pivot.c \
		$(DIR_SRC)/operations_push.c \
		$(DIR_SRC)/operations_reverse.c \
		$(DIR_SRC)/operations_rotate.c \
		$(DIR_SRC)/operations_swap.c \
		$(DIR_SRC)/push_pop.c \
		$(DIR_SRC)/push_swap.c \
		$(DIR_SRC)/sort_large.c \
		$(DIR_SRC)/rotate_to_max.c \
		$(DIR_SRC)/sort_small.c \
		$(DIR_SRC)/cases.c \
		$(DIR_SRC)/stack_utils.c \
		$(DIR_SRC)/handle_errors.c \
		$(DIR_SRC)/main_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	make all -C $(DIR_LIBFT)

$(PRINTF):
	make all -C $(DIR_PRINTF)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(DIR_LIBFT)
	make clean -C $(DIR_PRINTF)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re