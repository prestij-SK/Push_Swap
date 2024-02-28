#include "push_swap.h"

int	*get_nums_from_strings(char **str_mat)
{
	long long	num;
	int			str_mat_size;
	int			*nums;
	int			i;

	if (!str_mat)
		return (NULL);
	str_mat_size = split_size(str_mat);
	nums = (int *)malloc(sizeof(int) * (str_mat_size));
	if (allocation_error(nums))
		return (NULL);
	i = 0;
	while (i < str_mat_size)
	{
		num = ft_atoll(str_mat[i]);
		if (big_number_error(num))
		{
			free(nums);
			return (NULL);
		}
		nums[i] = num;
		++i;
	}
	return (nums);
}