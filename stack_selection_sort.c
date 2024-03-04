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

static int	make_top_for_a(StackInt *a, int index)
{
	int	count;

	if (is_empty(a))
		return (0);
	count = 0;
	if (index == a->top)
		return (0);
	if (index >= (a->top + 1) / 2)
	{
		index = a->top - index;
		while (index)
		{
			count += ra(a);
			--index;
		}
	}
	else
	{
		while (index)
		{
			count += rra(a);
			--index;
		}
		count += rra(a);
	}
	return (count);
}

int	push_lowest_from_a_selection(StackInt *a, StackInt *b)
{
	int	i;
	int	count;

	if (is_empty(a))
		return (0);
	count = 0;
	i = find_lowest(a);
	if (i == -1)
		return (0);
	count += make_top_for_a(a, i);
	count += pb(a, b);
	return (count);
}

int	push_top_from_b_selection(StackInt *a, StackInt *b)
{
	int	count;

	if (is_empty(b))
		return (0);
	count = 0;
	count += pa(a, b);
	return (count);
}

int	stack_selection_sort(StackInt *a, StackInt *b)
{
	int	count;

	if (is_empty(a))
		return (0);
	count = 0;
	while (!stack_is_sorted(a) && a->top > 4)
	{
		count += push_lowest_from_a_selection(a, b);
	}
	count += sort_for_5(a, b);
	while (!is_empty(b))
	{
		count += push_top_from_b_selection(a, b);
	}
	
	return (count);
}