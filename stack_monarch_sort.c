#include "push_swap.h"

static void	array_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	if (!arr)
		return ;
	i = 0;
    while (i < size - 1)
	{
        j = 0;
        while (j < size - i - 1)
		{
            if (arr[j] > arr[j + 1])
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

static int	*sorted_array_from_stack(StackInt *s)
{
	int	*arr;
	int	i;

	if (is_empty(s))
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (s->top + 1));
	if (allocation_error(arr))
		return (NULL);
	i = 0;
	while (i < s->top + 1)
	{
		arr[i] = s->stack[i];
		++i;
	}
	array_bubble_sort(arr, s->top + 1);
	return (arr);
}

static int	push_lowest_from_a_monarch(StackInt *a, StackInt *b, int *arr, int index, int interval)
{
	int	count;

	if (is_empty(a))
		return (0);
	count = 0;
	while (1)
	{
		if (a->stack[a->top] <= arr[index])
		{
			count += pb(a, b);
			count += rb(b);
			return (count);
		}
		else if (a->stack[a->top] <= arr[index + interval])
		{
			count += pb(a, b);
			return (count);
		}
		else
		{
			count += ra(a);
		}
	}
	return (count);
}

static int	find_highest(StackInt *s)
{
	int	index;
	int	i;

	if (is_empty(s))
		return (-1);
	index = s->top;
	i = 0;
	while (i < s->top)
	{
		if (s->stack[index] < s->stack[i])
		{
			index = i;
		}
		++i;
	}
	return (index);
}

static int	make_top_for_b(StackInt *b, int index)
{
	int	count;

	if (is_empty(b))
		return (0);
	count = 0;
	if (index == b->top)
		return (0);
	if (index >= (b->top + 1) / 2)
	{
		index = b->top - index;
		while (index)
		{
			count += rb(b);
			--index;
		}
	}
	else
	{
		while (index)
		{
			count += rrb(b);
			--index;
		}
		count += rrb(b);
	}
	return (count);
}

static int	push_highest_from_b_monarch(StackInt *a, StackInt *b)
{
	int	i;
	int	count;

	if (is_empty(b))
		return (0);
	count = 0;
	i = find_highest(b);
	if (i == -1)
		return (0);
	count += make_top_for_b(b, i);
	count += pa(a, b);
	return (count);
}

static int	monarch_sort_start(StackInt *a, StackInt *b, int *arr, int size, int interval)
{
	int	count;
	int	i;

	if (is_empty(a))
		return (0);
	count = 0;
	i = 0;
	while (!is_empty(a))
	{
		if (interval + i >= size)
			--interval;
		count += push_lowest_from_a_monarch(a, b, arr, i, interval);
		// interval = ft_sqrt(size) + ft_log2(size); this can optimized, but very little
		++i;
	}
	while (!is_empty(b))
	{
		count += push_highest_from_b_monarch(a, b);
	}
	return (count);
}

int	stack_monarch_sort(StackInt *a, StackInt *b)
{
	int	count;
	int	*sorted_arr;
	int	sorted_arr_size;
	int	interval;

	if (is_empty(a))
		return (0);
	sorted_arr = sorted_array_from_stack(a);
	if (!sorted_arr)
		return (0);
	sorted_arr_size = a->top + 1;
	interval = ft_sqrt(sorted_arr_size) + ft_log2(sorted_arr_size);
	count = 0;
	count += monarch_sort_start(a, b, sorted_arr, sorted_arr_size, interval);
	free(sorted_arr);
	return (count);
}