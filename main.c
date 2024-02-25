#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nums;
	int	size;

	if (argc < 2)
		return (0);
	nums = get_nums_from_strings(argc, argv, &size);
	if (!nums)
		return (0);
	int i = 0;
	while (i < size)
	{
		printf("%d ", nums[i]);
		++i;
	}
	// start logic
	free(nums);
	return (0);
}