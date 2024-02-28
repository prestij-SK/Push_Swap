#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**split_strings;
	int		*nums;
	int		size;

	nums = NULL;
	if (argc < 2)
		return (0);
	split_strings = parse_strings(argc, argv);
	if (!split_strings)
		return (0);
	size = split_size(split_strings);
	nums = get_nums_from_strings(split_strings);
	free_split(split_strings);
	if (!nums)
		return (0);
	stack_sort_moves(nums, size);
	free(nums);










	
	// int i;
	// // while (i < size)
	// // {
	// // 	printf("%d ", nums[i]);
	// // 	++i;
	// // }
	
	// StackInt *a;
	// a = create_stack(nums, size);
	// printf("\n---CREATED A---\n");
	// i = a->top;
	// while (i >= 0)
	// {
	// 	printf("%d\n", a->buffer[i]);
	// 	--i;
	// }

	// StackInt *b;
	// printf("\n---CREATED B empty---\n");
	// b = create_stack_empty(size);

	// printf("\n---OPERATIONS---\n");
	// pa_pb(a, b, 'b');
	// pa_pb(a, b, 'b');

	// printf("\n---PRINT A---\n");
	// i = a->top;
	// while (i >= 0)
	// {
	// 	printf("%d\n", a->buffer[i]);
	// 	--i;
	// }
	// printf("\n---PRINT B---\n");
	// i = b->top;
	// while (i >= 0)
	// {
	// 	printf("%d\n", b->buffer[i]);
	// 	--i;
	// }

	// // printf("\n---ROTATE_UP A---\n");
	// // rotate_up(a);
	// // rotate_up(a);

	// // printf("\n---ROTATE_DOWN A---\n");
	// // rotate_down(a);
	// rotate_up(a);

	// printf("\n---PRINT A---\n");
	// i = a->top;
	// while (i >= 0)
	// {
	// 	printf("%d\n", a->buffer[i]);
	// 	--i;
	// }

	// delete_stack(a);
	// delete_stack(b);

	return (0);
	
}