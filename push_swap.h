#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h> // DELETE

# define INT_DIGITS 10
# define INT_DIGITS_WITH_SIGN 11
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*
	libft_funcs.c
*/
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);

/*
	utils.c functions

	* ft_atoll - turns stringo into long long.
*/
long long	atoll(const char *str);

/*
	converter.c functions

	* convert_string_matrix_to_nums - get nums of matrix of strings
*/
int	*convert_string_matrix_to_nums(int argc, char **argv);

/*
	error_handling.c functions

	* argv_error - error if argv is NULL
	* allocation_error - error if malloc() failed
	* big_string_error - error if string is too big for INT
	* big_number_error - error if number result is bigger/lower MAX_INT/MIN_INT
	* symbols_error - error if symbols are not digits
*/
int	argv_error(char **argv);
int	allocation_error(void *ptr);
int	big_string_error(char *str);
int	big_number_error(long long num);
int	symbols_error(int argc, char **argv);

#endif