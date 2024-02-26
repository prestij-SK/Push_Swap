#include "push_swap.h"

static int	stack_is_sorted(StackInt *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->top;
	while (i > 0)
	{
		if (s->buffer[i] > s->buffer[i + 1])
		{
			return (0);
		}
		--i;
	}
	return (1);
}

static void	sort_for_3(StackInt *a, StackInt *b, int *counter)
{
	if (!a || !b)
		return ;
	if (a->top == 0 || a->top == -1)
		return ;
	if (a->top == 1)
	{
		if (a->buffer[a->top] > a->buffer[a->top - 1])
		{
			sa_sb_ss(a, b, 'a');
			++(*counter);
			return ;
		}
	}
	if (a->buffer[a->top] > a->buffer[a->top - 1])
	{
		ss_sb_ss(a, b, 'a');
		++(*counter);
	}
}

int	sort_as_stack(int *nums, int size)
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
	{
		//
	}
	else if (size <= 5)
	{
		//
	}
	else
	{
		//
	}
	delete_stack(a);
	delete_stack(b);
	return (counter);
}