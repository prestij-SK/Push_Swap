#include "push_swap.h"

static int	empty_string_error(char *str)
{
	if (!str) // I can make this function one line, but there is a risk to *NULL
	{
		write(WRITE_ERROR_DESCRIPTOR, "Empty_String_Error\n", 19);
		return (1);
	}
	else if (!(*str))
	{
		write(WRITE_ERROR_DESCRIPTOR, "Empty_String_Error\n", 19);
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
			
			write(WRITE_ERROR_DESCRIPTOR, "Big_String_Error\n", 17);
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
			write(WRITE_ERROR_DESCRIPTOR, "String_Symbol_Error\n", 20);
			return (1);
		}
		++str;
	}
	return (0);
}

int string_error(char **split)
{
	int		i;
	size_t	str_len;

	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		if (empty_string_error(split[i]))
			return (1);
		str_len = ft_strlen(split[i]);
		if (big_string_error(split[i], str_len))
			return (1);
		if (string_symbol_error(split[i], str_len))
			return (1);
		++i;
	}
	return (0);
}

int allocation_error(void *ptr)
{
	if (!ptr)
	{
		write(WRITE_ERROR_DESCRIPTOR, "Allocation_Error\n", 17);
		return (1);
	}
	return (0);
}

int big_number_error(long long num)
{
	if (num < MIN_INT || num > MAX_INT)
	{
		write(WRITE_ERROR_DESCRIPTOR, "Big_Number_Error\n", 17);
		return (1);
	}
	return (0);
}

int	duplicates_error(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				write(WRITE_ERROR_DESCRIPTOR, "Duplicates_Error\n", 17);
				return (1);
			}
			++j;
		}
		++i;
	}
    return (0);
}