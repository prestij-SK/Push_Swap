#include "push_swap.h"

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

int	ft_log2(unsigned int n)
{
    int	result;

	result = -1;
    while (n) {
        n >>= 1;
        result++;
    }
    return (result);
}

int	ft_sqrt(int n)
{
	int	start;
	int	mid;
	int	end;
	int	ans;

	if (n < 0)
		return (-1);
    if (n <= 1)
        return (n);
    start = 1;
	end = n;
    while (start <= end)
	{
        mid = (start + end) / 2;
        if (mid * mid == n)
            return (mid);
        if (mid * mid < n)
		{
            start = mid + 1;
            ans = mid;
        }
		else
            end = mid - 1;
    }
    return (ans);
}