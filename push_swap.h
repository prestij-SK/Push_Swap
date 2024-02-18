#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h> // DELETE

/*
	utils.c functions

	* ft_atoll - turns stringo into long long.
*/
long long	ft_atoll(const char *str);

/*
	input_check.c functions

	* is_valid_input - checks if arguments are valid numbers
*/
int	is_valid_input(const int argc, const char **argv);

#endif