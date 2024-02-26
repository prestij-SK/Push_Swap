#ifndef MY_STACK_H
# define MY_STACK_H

# include <stdlib.h>

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
	* swap_top - swap first and second elements of stack
	* is_full - check if there is space to add element
	* is_empty - check if stack is empty
	* rotate_up - shifts elements of the stack UP
	* rotate_down - shifts elements of the stack DOWN
	* delete_stack - deletes a stack by free() and makes fields to NULL
	* push - push data to the top of the stack
	* create_stack_empty - creates an empty stack and sets size
	* create_stack - creates a stack and fills with given arr, size
*/
int			pop(StackInt *this);
void		swap_top(StackInt *s);
int			is_full(StackInt *this);
int			is_empty(StackInt *this);
void		rotate_up(StackInt *this);
void		rotate_down(StackInt *this);
void		delete_stack(StackInt *this);
void		push(StackInt *this, int data);
StackInt	*create_stack_empty(int size);
StackInt	*create_stack(int *arr, int size);

#endif