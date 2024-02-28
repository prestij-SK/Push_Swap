#include "push_swap.h"

void	sort_for_5(StackInt *a, StackInt *b, int *count)
{
	if (is_empty(a))
		return ;
	// display_stack(a); // DELETE
	*count += push_lowest_from_a(a, b);
	if (stack_is_sorted(a))
	{
		*count += push_all_from_b(a, b);
		return ;
	}
	*count += push_lowest_from_a(a, b);
	sort_for_3(a, b, count);
	*count += push_all_from_b(a, b);
	// display_stack(a); // DELETE
	// display_stack(b); // DELETE
}

void	sort_for_3(StackInt *a, StackInt *b, int *count)
{
	if (is_empty(a))
		return ;
	if (a->top == 0 || a->top == -1)
		return ;
	if (a->top == 2)
	{
		if ((a->stack[a->top] > a->stack[a->top - 1]) &&
			 a->stack[a->top] > a->stack[a->top - 2])
		{
			*count += ra_rb_rr(a, b, 'a');
		}
		else if (a->stack[a->top - 1] > a->stack[a->top - 2])
		{
			*count += rra_rrb_rrr(a, b, 'a');
		}
	}
	if (a->stack[a->top] > a->stack[a->top - 1])
		*count += sa_sb_ss(a, b, 'a');
}

int	stack_sort_moves(int *nums, int size)
{
	StackInt	*a;
	StackInt	*b;
	int			count;

	if (!nums)
		return (0);
	a = create_stack(nums, size);
	b = create_stack_empty(size);
	count = 0;
	// display_stack(a); // DELETE
	if (!stack_is_sorted(a))
	{
		if (size <= 3)
			sort_for_3(a, b, &count);
		else if (size <= 5)
			sort_for_5(a, b, &count);
		else
		{
			//
		}
	}
	printf("\nmoves: %d\n", count); // DELETE
	printf("\nA empty?: %d\n", is_empty(a)); // DELETE
	printf("\nB empty?: %d\n", is_empty(b)); // DELETE
	display_stack(a); // DELETE
	delete_stack(a);
	delete_stack(b);
	return (count);
}