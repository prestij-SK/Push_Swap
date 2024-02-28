#include "push_swap.h"

static void	selection_left_to_right(StackInt *left, StackInt *right, int amount)
{
	if (!left)
		return ;
	if (amount == 0)
		return ;
	
}

static void	sort_for_5(StackInt *a, StackInt *b, int *counter)
{

}

static void	sort_for_3(StackInt *a, StackInt *b, int *counter)
{
	if (!a)
		return ;
	if (a->top == 0 || a->top == -1)
		return ;
	if (a->top == 2)
	{
		if ((a->stack[a->top] > a->stack[a->top - 1]) &&
			 a->stack[a->top] > a->stack[a->top - 2])
		{
			ra_rb_rr(a, b, 'a');
			++(*counter);
		}
		else if (a->stack[a->top - 1] > a->stack[a->top - 2])
		{
			rra_rrb_rrr(a, b, 'a');
			++(*counter);
		}
	}
	if (a->stack[a->top] > a->stack[a->top - 1])
	{
		sa_sb_ss(a, b, 'a');
		++(*counter);
	}
}

int	stack_sort_moves(int *nums, int size)
{
	StackInt	*a;
	StackInt	*b;
	int			counter;

	if (!nums)
		return (0);
	a = create_stack(nums, size);
	b = create_stack_empty(size);
	counter = 0;
	if (size <= 3)
		sort_for_3(a, b, &counter);
	else if (size <= 5)
	{
		//
	}
	else
	{
		//
	}

	printf("moves: %d\n", counter); // DELETE
	display_stack(a); // DELETE

	delete_stack(a);
	delete_stack(b);
	return (counter);
}