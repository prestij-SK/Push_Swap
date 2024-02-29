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

static int	hit_or_miss(int num, int *arr, int size, int interval, int index)
{
	int	count;

	if (!arr)
		return (0);
	count = 0;
	// if (num <= arr[])
	return (0);
}

static int	push_lowest_from_A_by_array(StackInt *a, StackInt *b, int *arr, int size)
{
	int	count;
	int	interval;
	int	i;

	if (is_empty(a))
		return (0);
	count = 0;
	interval = ft_sqrt(a->top + 1);
	i = a->top;
	while (a->top + 1)
	{

	}
	return (0);
}

int	stack_monarch_sort(StackInt *a, StackInt *b)
{
	int	count;
	int	*sorted_arr;
	int	sorted_arr_size;

	if (is_empty(a))
		return (0);
	sorted_arr = sorted_array_from_stack(a);
	if (!sorted_arr)
		return (0);
	count = 0;
	// int i = 0;
	// while (i < a->top + 1)
	// {
	// 	printf("%d ", sorted_arr[i]);
	// 	++i;
	// }
	count += push_lowest_from_A_by_array(a, b, sorted_arr, sorted_arr_size);
	count += sort_for_3(a, b);
	// push highest from B
	free(sorted_arr);
	return (count);
}