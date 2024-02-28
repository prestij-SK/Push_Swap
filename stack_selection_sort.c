#include "push_swap.h"

static int	find_lowest(StackInt *s)
{
	int	index;
	int	i;

	if (is_empty(s))
		return (-1);
	index = s->top;
	i = 0;
	while (i < s->top)
	{
		if (s->stack[index] > s->stack[i])
		{
			index = i;
		}
		++i;
	}
	return (index);
}

static void	make_top(StackInt *a, StackInt *b, int index, int *count)
{
	if (is_empty(a))
		return ;
	if (index >= (a->top + 1) / 2)
	{
		index = a->top - index;
		while (index)
		{
			*count += ra_rb_rr(a, b, 'a');
			--index;
		}
	}
	else
	{
		while (index)
		{
			*count += rra_rrb_rrr(a, b, 'a');
			--index;
		}
		*count += rra_rrb_rrr(a, b, 'a');
	}
}

int	push_lowest_from_a(StackInt *a, StackInt *b)
{
	int	i;
	int	temp;
	int	count;

	if (is_empty(a))
		return (0);
	count = 0;
	i = find_lowest(a);
	if (i == -1)
		return (0);
	make_top(a, b, i, &count);
	count += pa_pb(a, b, 'b');
	return (count);
}

int	push_all_from_b(StackInt *a, StackInt *b)
{
	int	count;

	if (is_empty(b))
		return (0);
	count = 0;
	while (b->top + 1)
	{
		count += pa_pb(a, b, 'a');
	}
	return (count);
}

int	stack_selection_sort(StackInt *a, StackInt *b)
{
	int	count;

	if (is_empty(a))
		return (0);
	count = 0;
	while (!stack_is_sorted(a) && a->top > 2)
	{
		count += push_lowest_from_a(a, b);
	}
	sort_for_3(a, b, &count);
	count += push_all_from_b(a, b);
	return (count);
}