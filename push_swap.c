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
		exit(EXIT_ERROR_STATUS);
	size = split_size(split_strings);
	nums = get_nums_from_strings(split_strings);
	ft_free_split(split_strings);
	if (!nums)
		exit(EXIT_ERROR_STATUS);
	if (duplicates_error(nums, size))
	{
		free(nums);
		exit(EXIT_ERROR_STATUS);
	}
	stack_sort_moves(nums, size);
	free(nums);
	return (0);
}