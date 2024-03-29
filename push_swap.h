#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

#include "my_stack.h"

# define INT_DIGITS 10
# define INT_DIGITS_WITH_SIGN 11
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define EXIT_ERROR_STATUS 1
# define WRITE_ERROR_DESCRIPTOR 2
# define WRTIE_OUTPUT_DESCRIPTOR 1

/*
	Libft functions
*/
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_free_split(char **mat);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
	error_handling.c functions

	* string_error - error if the string does not match the rules.
	* allocation_error - error if malloc() failed.
	* big_number_error - error if number result is bigger/lower MAX_INT/MIN_INT.
	* duplicates_error - error if there are any duplicates in the array.
*/
int	string_error(char **split);
int	allocation_error(void *ptr);
int	big_number_error(long long num);
int	duplicates_error(int *arr, int size);

/*
	push_swap_operations.c

	sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one or no elements.

	sb (swap b): Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one or no elements.

	ss : sa and sb at the same time.

	pa (push a): Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.

	pb (push b): Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.

	ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.

	rb (rotate b): Shift up all elements of stack b by 1.
		The first element becomes the last one.

	rr : ra and rb at the same time.

	rra (reverse rotate a): Shift down all elements of stack a by 1.
		The last element becomes the first one.

	rrb (reverse rotate b): Shift down all elements of stack b by 1.
		The last element becomes the first one.

	rrr : rra and rrb at the same time.

*/
int	sa(StackInt *a);
int	sb(StackInt *b);
int	ss(StackInt *a, StackInt *b);
int	ra(StackInt *a);
int	rb(StackInt *b);
int	rr(StackInt *a, StackInt *b);
int	rra(StackInt *a);
int	rrb(StackInt *b);
int	rrr(StackInt *a, StackInt *b);
int	pa(StackInt *a, StackInt *b);
int	pb(StackInt *a, StackInt *b);

/*
	strings_to_ints.c functions

	* get_nums_from_strings - get nums of matrix from strings.
	* parse_strings - returns the result of parsing all strings in the matrix of strings.
*/
int		*get_nums_from_strings(char **str_mat);
char	**parse_strings(int size, char **str_mat);

/*
	utils.c functions

	* ft_sqrt - returns root of number.
	* ft_is_space - check if given character is space.
	* ft_log2 - returns log base 2 for given number.
	* split_size - returns the size of split matrix.
	* free_split - free matrix which was created by split().
	* ft_atoll - turns string into long long.
*/
int			ft_sqrt(int n);
int			ft_is_space(char c);
int			ft_log2(unsigned int n);
int			split_size(char **split);
long long	ft_atoll(const char *str);

/*
	stack_selection_sort.c functions

	* push_all_from_b_selection - push all from stack B to A. Returns number of moves.
	* push_lowest_from_A_selection - pushs one lowest element from stack A to B. Returns number of moves.
	* stack_selection_sort - sorts stack A with use of B by logic of Selection sort. Returns number of moves.
*/
int	push_top_from_b_selection(StackInt *a, StackInt *b);
int	push_lowest_from_a_selection(StackInt *a, StackInt *b);
int	stack_selection_sort(StackInt *a, StackInt *b);

/*
	stack_sort_moves.c functions

	* stack_sort_moves - sorts numbers as if they were in stack using given operations and returns number of moves done.
	* sort_for_3 - simple sort for 3 numbers
	* sort_for_5 - simple sort for 5 numbers. Has Selection sort logic.
*/
int	stack_sort_moves(int *nums, int size);
int	sort_for_3(StackInt *a);
int	sort_for_5(StackInt *a, StackInt *b);

/*
	stack_monarch_sort.c functions

	* stack_monarch_sort - sorts the stack with the logic of 'butterfly sort'. Returns number of moves.
*/
int	stack_monarch_sort(StackInt *a, StackInt *b);

#endif