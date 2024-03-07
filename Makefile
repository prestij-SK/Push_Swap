SRC =	push_swap.c \
		error_handling.c \
		libft_funcs.c \
		my_stack.c \
		push_swap_operations.c \
		stack_monarch_sort.c \
		stack_selection_sort.c \
		stack_sort_moves.c \
		strings_to_ints.c \
		utils.c \

BONUS_SRC = checker.c \
			get_next_line.c \
			get_next_line_utils.c \
			check_moves.c \
			error_handling.c \
			libft_funcs.c \
			my_stack.c \
			push_swap_operations.c \
			strings_to_ints.c \
			utils.c \

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): push_swap.h my_stack.h Makefile
$(BONUS_OBJS): push_swap.h my_stack.h checker.h Makefile

bonus: $(BONUS_OBJS) $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

.PHONY: all clean fclean re sanitize bonus