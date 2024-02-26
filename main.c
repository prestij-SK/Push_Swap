#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nums;
	int	size;

	nums = NULL;
	if (argc < 2)
		return (0);
	nums = get_nums_from_strings(argc, argv, &size);
	if (!nums)
		return (0);
	// start logic
	int i;
	// while (i < size)
	// {
	// 	printf("%d ", nums[i]);
	// 	++i;
	// }
	
	StackInt *a;
	a = create_stack(nums, size);
	printf("\n---CREATED A---\n");
	i = a->top;
	while (i >= 0)
	{
		printf("%d ", a->buffer[i]);
		--i;
	}

	StackInt *b;
	printf("\n---CREATED B empty---\n");
	b = create_stack_empty(size);

	printf("\n---OPERATIONS---\n");
	pa_pb(a, b, 'b');
	pa_pb(a, b, 'b');

	printf("\n---PRINT A---\n");
	i = a->top;
	while (i >= 0)
	{
		printf("%d ", a->buffer[i]);
		--i;
	}
	printf("\n---PRINT B---\n");
	i = b->top;
	while (i >= 0)
	{
		printf("%d ", b->buffer[i]);
		--i;
	}

	// printf("\n---ROTATE_UP A---\n");
	// rotate_up(a);
	// rotate_up(a);

	// printf("\n---ROTATE_DOWN A---\n");
	rotate_down(a);
	// rotate_up(a);

	printf("\n---PRINT A---\n");
	i = a->top;
	while (i >= 0)
	{
		printf("%d ", a->buffer[i]);
		--i;
	}

	delete_stack(a);
	delete_stack(b);

	printf("\n\n\n%lld", ft_atoll("000123"));
	free(nums);
	return (0);
}