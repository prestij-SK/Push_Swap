#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"
#include "my_stack.h"
#include "get_next_line.h"

# define READ_FILE_DESCRIPTOR 0
/*
	check_moves.c functions

	* checker - shows the results after given operations.
				KO - moves doesn't sort
				OK - moves are sorting
				ERROR - moves are wrong or other error
*/
void	check_moves(int *nums, int size);

#endif