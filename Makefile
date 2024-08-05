NAME = push_swap
DIR = ./source
RM = rm -rf
DIR_PRINTF = ../ft_printf
PRINTF = $(DIR_PRINTF)/libftprintf.a
DIR_LIBFT = ../libft
LIBFT = $(DIR_LIBFT)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(DIR) -I $(DIR_PRINTF)/Include -I $(DIR_LIBFT)

SRC =	$(DIR)/find_pivot.c \
		$(DIR)/operations_push.c \
		$(DIR)/operations_reverse.c \
		$(DIR)/operations_rotate.c \
		$(DIR)/operations_swap.c \
		$(DIR)/push_pop.c \
		$(DIR)/push_swap.c \
		$(DIR)/sort_large.c \
		$(DIR)/rotate_to_max.c \
		$(DIR)/sort_small.c \
		$(DIR)/cases.c \
		$(DIR)/stack_utils.c \
		$(DIR)/handle_errors.c \
		$(DIR)/ft_strtol_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(DIR)/%.o: $(DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re