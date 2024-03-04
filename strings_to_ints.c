#include "push_swap.h"

static int	copy_split(char **dest, char **src)
{
	int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	return (i);
}

static char	**split_join(char **s1, char **s2)
{
	char	**split_new;
	int		s1_size;
	int		s2_size;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	s1_size = split_size(s1);
	s2_size = split_size(s2);
	split_new = (char **)malloc(sizeof(char *) * (s1_size + s2_size + 1));
	if (allocation_error(split_new))
		return (NULL);
	i = 0;
	i += copy_split(split_new + i, s1);
	i += copy_split(split_new + i, s2);
	split_new[i] = NULL;
	// We don't want to free insides of s1 and s2
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (split_new);
}

char	**parse_strings(int size, char **str_mat)
{
	char	**str_parsed;
	char	**temp_split;
	int		i;

	if (!str_mat)
		return (NULL);
	str_parsed = NULL;
	i = 1; // avoid program name
	while (i < size)
	{
		temp_split = ft_split(str_mat[i], ' ');
		if (allocation_error(temp_split) || string_error(temp_split))
		{
			ft_free_split(temp_split);
			ft_free_split(str_parsed);
			return (NULL);
		}
		str_parsed = split_join(str_parsed, temp_split);
		if (allocation_error(str_parsed))
		{
			ft_free_split(temp_split);
			ft_free_split(str_parsed);
			return (NULL);
		}
		++i;
	}
	return (str_parsed);
}

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