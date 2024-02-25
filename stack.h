#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

# include "push_swap.h"

# define SIZE_MULTIPLIER 2

typedef struct MyStack
{
	int	*buffer;
	int	size;
	int	top;
}	StackInt;

/*
	stack.c functions

	* pop - takes off and returns the top element
	* is_full - check if there is space to add element
	* is_empty - check if stack is empty
	* delete_stack - deletes a stack by free() and makes fields to NULL
	* push - push data to the top of the stack
	* create_stack - creates a stack and fills with given arr, size
*/
int			pop(StackInt *this);
int			is_full(StackInt *this);
int			is_empty(StackInt *this);
void		delete_stack(StackInt *this);
void		push(StackInt *this, int data);
StackInt	*create_stack(int *arr, int size);

#endif