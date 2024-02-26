#include "push_swap.h"

static void	split_free(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		++i;
	}
	free(mat[i]);
	free(mat);
}

static char	**special_case(int *argc, char **argv)
{
	char		**str_mat;
	int			str_mat_size;

	str_mat = ft_split(argv[1], ' ');
	if (!str_mat)
		return (NULL);
	str_mat_size = 0;
	while (str_mat[str_mat_size])
		++str_mat_size;
	*argc = str_mat_size;
	return (str_mat);
}

static int	*get_nums(int size, char **mat)
{
	long long	num;
	int			*nums;
	int			i;

	nums = (int *)malloc(sizeof(int) * (size));
	if (allocation_error(nums))
		return (NULL);
	i = 0;
	while (i < size)
	{
		num = ft_atoll(mat[i]);
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

int	*get_nums_from_strings(int argc, char **argv, int *size)
{
	int		*nums;
	char	**str_mat;

	if (argv_error(argv))
		return (NULL);
	if (argc == 2) // This is for task, I would delete this to be honest.
	{
		str_mat = special_case(&argc, argv);
		if (string_error(argc, str_mat))
			return (NULL);
		nums = get_nums(argc, str_mat);
		*size = argc;
		split_free(str_mat);
	}
	else
	{
		if (string_error(argc - 1, argv + 1))
			return (NULL);
		nums = get_nums(argc - 1, argv + 1);
		*size = argc - 1;
	}
	return (nums);
}