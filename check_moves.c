#include "checker.h"

static int	do_move(StackInt *a, StackInt *b, char *move)
{
	if (!ft_strncmp("sa", move, 2))
		swap_top(a);
	else if (!ft_strncmp("sb", move, 2))
		swap_top(b);
	else if (!ft_strncmp("ss", move, 2))
	{
		swap_top(a);
		swap_top(b);
	}
	else if (!ft_strncmp("pa", move, 2))
		push(a, pop(b));
	else if (!ft_strncmp("pb", move, 2))
		push(b, pop(a));
	else if (!ft_strncmp("rra", move, 3))
		rotate_down(a);
	else if (!ft_strncmp("rrb", move, 3))
		rotate_down(b);
	else if (!ft_strncmp("rrr", move, 3))
	{
		rotate_down(a);
		rotate_down(b);
	}
	else if (!ft_strncmp("ra", move, 2))
		rotate_up(a);
	else if (!ft_strncmp("rb", move, 2))
		rotate_up(b);
	else if (!ft_strncmp("rr", move, 2))
	{
		rotate_up(a);
		rotate_up(b);
	}
	else
		return (0);
	return (1);
}

void	check_moves(int *nums, int size)
{
	char		*move;
	StackInt	*a;
	StackInt	*b;

	a = create_stack(nums, size);
	b = create_stack_empty(size);
	move = get_next_line(READ_FILE_DESCRIPTOR);
	while (move)
	{
		if (!do_move(a, b, move))
		{
			write(WRITE_ERROR_DESCRIPTOR, "Error\n", 6);
			get_next_line(-1); // -1 to free static variable in function
			delete_stack(a);
			delete_stack(b);
			free(move);
			return ;
		}
		free(move);
		move = get_next_line(0);
	}
	if (stack_is_sorted(a) && is_empty(b))
		write(WRTIE_OUTPUT_DESCRIPTOR, "OK\n", 3);
	else
		write(WRTIE_OUTPUT_DESCRIPTOR, "KO\n", 3);
	delete_stack(a);
	delete_stack(b);
}