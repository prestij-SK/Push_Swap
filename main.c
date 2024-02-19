#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nums;

	if (argc < 2)
		return (0);
	nums = convert_string_matrix_to_nums(argc, argv);
	if (!nums)
		return (0);
	int i = 0;
	while (i < argc - 1)
	{
		printf("%d ", nums[i]);
		++i;
	}
	// start logic
	return (0);
}