#include "push_swap.h"

int	argv_error(char **argv)
{
	if (!argv)
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}

int	symbols_error(int argc, char **argv)
{
	int		i;
	int		j;

	if (!argv)
		return (1);
	i = 1; // to avoid executable file name
	while (i < argc)
	{
		j = 0;
		if (ft_strlen(argv[i]) == 0)
		{
			printf("Error\n"); // <---------- LIBFT
				return (1);
		}
		if ((argv[i][0] == '+' || argv[i][0] == '-') && (ft_strlen(argv[i]) > 1))
			++j;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error\n"); // <---------- LIBFT
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int	allocation_error(void *ptr)
{
	if (!ptr)
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}

int	big_string_error(char *str)
{
	if (ft_strlen(str) > INT_DIGITS)
	{
		if (ft_strlen(str) > INT_DIGITS_WITH_SIGN || (str[0] != '-' || str[0] != '+'))
		{
			printf("Error\n"); // <---------- LIBFT
			return (1);
		}
	}
	return (0);
}

int	big_number_error(long long num)
{
	if (num < MIN_INT || num > MAX_INT)
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}