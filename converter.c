#include "push_swap.h"

static int	*get_nums_from_string(int argc, char **argv)
{
	long long	num;
	int			*nums;
	int			i;

	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (allocation_error(nums))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		num = atoll(argv[i]);
		if (big_number_error(num))
		{
			free(nums);
			return (NULL);
		}
		nums[i - 1] = num;
		++i;
	}
	return (nums);
}

int	*convert_string_matrix_to_nums(int argc, char **argv)
{
	int	*nums;

	if (argv_error(argv))
		return (NULL);
	if (string_error(argc, argv))
		return (NULL);
	nums = get_nums_from_string(argc, argv);
	return (nums);
}
