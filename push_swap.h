#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h> // DELETE

#include "my_stack.h"

# define INT_DIGITS 10
# define INT_DIGITS_WITH_SIGN 11
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*
	Libft functions
*/
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

/*
	utils.c functions

	* ft_atoll - turns stringo into long long.
*/
long long	atoll(const char *str);

/*
	converter.c functions

	* get_nums_from_strings - get nums of matrix from strings
*/
int	*get_nums_from_strings(int argc, char **argv, int *size);

/*
	error_handling.c functions

	* argv_error - error if argv is NULL
	* allocation_error - error if malloc() failed
	* big_number_error - error if number result is bigger/lower MAX_INT/MIN_INT
	* string_error - error if the string does not match the rules
*/
int	argv_error(char **argv);
int	allocation_error(void *ptr);
int	big_number_error(long long num);
int	string_error(int argc, char **argv);

/*
	push_swap_operations.c

	* pa_pb - push for a/b as taks wants
	* sa_sb_ss - swap_top for a/b/both as task wants
*/
void	pa_pb(StackInt *a, StackInt *b, char c);
void	sa_sb_ss(StackInt *a, StackInt *b, char c);
void	ra_rb_rr(StackInt *a, StackInt *b, char c);
void	rra_rrb_rrr(StackInt *a, StackInt *b, char c);

#endif