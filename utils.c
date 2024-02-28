#include "push_swap.h"

int	copy_split(char **dest, char **src)
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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		++i;
	}
	free(split[i]);
	split[i] = NULL;
	free(split);
	split = NULL;
}

int	split_size(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		++i;
	}
	return (i);
}

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

long long	ft_atoll(const char *str)
{
	size_t		i;
	long long	nbr;
	int			isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] && ft_is_space(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = 1;
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		++i;
	}
	if (isneg)
		return (-nbr);
	return (nbr);
}

int	stack_is_sorted(StackInt *s)
{
	int	i;

	if (!s)
		return (0);
	i = s->top;
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i + 1])
		{
			return (0);
		}
		--i;
	}
	return (1);
}

void	display_stack(StackInt *this)
{
	int	i;

	if (!this)
		return ;
	i = this->top;
	while (i >= 0)
	{
		printf("[ %d ]\n", this->stack[i]); // <--------------- libft
		--i;
	}
}