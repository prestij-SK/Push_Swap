#include "push_swap.h"

int	sort_for_5(StackInt *a, StackInt *b)
{
	int	count;

	if (is_empty(a))
		return (0);
	// display_stack(a); // DELETE
	if (stack_is_sorted(a))
		return (0);
	count = 0;
	count += push_lowest_from_a_selection(a, b);
	if (stack_is_sorted(a))
	{
		count += push_top_from_b_selection(a, b);
		return (count);
	}
	count += push_lowest_from_a_selection(a, b);
	count += sort_for_3(a, b);
	count += push_top_from_b_selection(a, b);
	count += push_top_from_b_selection(a, b);
	// display_stack(a); // DELETE
	// display_stack(b); // DELETE
	return (count);
}

int	sort_for_3(StackInt *a, StackInt *b)
{
	int	count;

	if (is_empty(a))
		return (0);
	if (a->top == 0 || a->top == -1)
		return (0);
	count = 0;
	if (a->top == 2)
	{
		if ((a->stack[a->top] > a->stack[a->top - 1]) &&
			 a->stack[a->top] > a->stack[a->top - 2])
		{
			count += ra(a);
		}
		else if (a->stack[a->top - 1] > a->stack[a->top - 2])
		{
			count += rra(a);
		}
	}
	if (a->stack[a->top] > a->stack[a->top - 1])
		count += sa(a);
	return (count);
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
			count += sort_for_3(a, b);
		else if (size <= 5)
			count += sort_for_5(a, b);
		else
			count += stack_monarch_sort(a, b);
			// count += stack_selection_sort(a, b);
	}
	// printf("\nmoves: %d\n", count); // DELETE
	// printf("\nA empty?: %d\n", is_empty(a)); // DELETE
	// printf("\nB empty?: %d\n", is_empty(b)); // DELETE
	// display_stack(a); // DELETE
	delete_stack(a);
	delete_stack(b);
	return (count);
}