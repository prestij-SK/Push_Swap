#include "push_swap.h"

int argv_error(char **argv)
{
	if (!argv)
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}

static int	empty_string_error(char *str)
{
	if (!str) // I can make this function one line, but there is a risk to *NULL
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	else if (!(*str))
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}

static int	big_string_error(char *str, size_t str_len)
{
	if (str_len > INT_DIGITS)
	{
		if (str_len != INT_DIGITS_WITH_SIGN || (*str != '-' && *str != '+'))
		{
			printf("Error\n"); // <---------- LIBFT
			return (1);
		}
	}
	return (0);
}

static int	string_symbol_error(char *str, size_t str_len)
{
	if ((*str == '+' || *str == '-') && (str_len > 1))
			++str;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
		{
			printf("Error\n"); // <---------- LIBFT
			return (1);
		}
		++str;
	}
	return (0);
}

int string_error(int argc, char **argv)
{
	int		i;
	int		j;
	size_t	str_len;

	if (!argv)
		return (1);
	i = 1; // to avoid executable file name
	while (i < argc)
	{
		if (empty_string_error(argv[i]))
			return (1);
		str_len = ft_strlen(argv[i]);
		if (big_string_error(argv[i], str_len))
			return (1);
		if (string_symbol_error(argv[i], str_len))
			return (1);
		++i;
	}
	return (0);
}

int allocation_error(void *ptr)
{
	if (!ptr)
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}

int big_number_error(long long num)
{
	if (num < MIN_INT || num > MAX_INT)
	{
		printf("Error\n"); // <---------- LIBFT
		return (1);
	}
	return (0);
}