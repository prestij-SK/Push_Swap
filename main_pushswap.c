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
	if (duplicates_error(nums, size))
	{
		free(nums);
		return (0);
	}
	stack_sort_moves(nums, size);
	free(nums);
	return (0);
}