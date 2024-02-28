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
	converter.c functions

	* get_nums_from_strings - get nums of matrix from strings
*/
int	*get_nums_from_strings(char **str_mat);

/*
	error_handling.c functions

	* string_error - error if the string does not match the rules
	* allocation_error - error if malloc() failed
	* big_number_error - error if number result is bigger/lower MAX_INT/MIN_INT
*/
int	string_error(char **split);
int	allocation_error(void *ptr);
int	big_number_error(long long num);

/*
	push_swap_operations.c

	* pa_pb - push for a/b as taks wants
	* sa_sb_ss - swap_top for a/b/both as task wants
*/
void	pa_pb(StackInt *a, StackInt *b, char c);
void	sa_sb_ss(StackInt *a, StackInt *b, char c);
void	ra_rb_rr(StackInt *a, StackInt *b, char c);
void	rra_rrb_rrr(StackInt *a, StackInt *b, char c);

/*
	string_parse.c functions

	* parse_strings - returns the result of parsing all strings in the matrix of strings
*/
char	**parse_strings(int size, char **str_mat);

/*
	utils.c functions

	* ft_is_space - check if given character is space
	* split_size - returns the size of split matrix
	* free_split - free matrix which was created by split()
	* ft_atoll - turns stringo into long long
	* stack_is_sorted - returns true if stack is sorted
	* display_stack - display stack elements
	* copy_split - copies from src split to dest split and returns the count of copies
*/
int			ft_is_space(char c);
int			split_size(char **split);
void		free_split(char **split);
long long	ft_atoll(const char *str);
int			stack_is_sorted(StackInt *s);
void		display_stack(StackInt *this);
int			copy_split(char **dest, char **src);

/*
	stack_sort_moves.c functions

	* stack_sort_moves - sorts numbers as if they were in stack using given operations and returns number of moves done
*/
int	stack_sort_moves(int *nums, int size);

#endif