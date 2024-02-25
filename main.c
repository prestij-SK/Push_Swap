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
	int i;
	// while (i < size)
	// {
	// 	printf("%d ", nums[i]);
	// 	++i;
	// }
	// start logic
	StackInt *ptr;
	ptr = create_stack(nums, size);
	printf("\n---CREATED---\n");
	i = 0;
	while (i < ptr->top + 1)
	{
		printf("%d ", ptr->buffer[i]);
		++i;
	}

	printf("\n---PUSHED---\n");
	push(ptr, 14);
	i = 0;
	while (i < ptr->top + 1)
	{
		printf("%d ", ptr->buffer[i]);
		++i;
	}

	printf("\n---POPED---\n");
	printf("pop: %d\n", pop(ptr));
	printf("pop: %d\n", pop(ptr));
	printf("pop: %d\n", pop(ptr));
	i = 0;
	while (i < ptr->top + 1)
	{
		printf("%d ", ptr->buffer[i]);
		++i;
	}
	delete_stack(ptr);
	free(nums);
	return (0);
}