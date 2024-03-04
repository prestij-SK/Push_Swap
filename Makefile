SRC = push_swap.c \
		error_handling.c \
		libft_funcs.c \
		my_stack.c \
		push_swap_operations.c \
		stack_monarch_sort.c \
		stack_selection_sort.c \
		stack_sort_moves.c \
		strings_to_ints.c \
		utils.c

OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

.PHONY: all re clean fclean