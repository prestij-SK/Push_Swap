#include "stack.h"

StackInt	*create_stack(int *arr, int size)
{
	StackInt	*stack_new;
	int			i;

	if (!arr)
		return (NULL);
	stack_new = (StackInt *)malloc(sizeof(StackInt));
	if (!stack_new)
		return (NULL);
	stack_new->buffer = (int *)malloc(sizeof(int) * size);
	if (!stack_new->buffer)
	{
		free(stack_new);
		return (NULL);
	}
	stack_new->size = size;
	stack_new->top = -1;
	i = size;
	while (i > 0)
	{
		push(stack_new, arr[i - 1]);
		--i;
	}
	return (stack_new);
}

void	delete_stack(StackInt *this)
{
	if (!this)
		return ;
	free(this->buffer);
	this->buffer = NULL;
	this->size = 0;
	this->top = -1;
	free(this);
	this = NULL;
}

int	is_full(StackInt *this)
{
	if (!this)
		return (0);
	if (this->top + 1 == MAX_INT)
		return (1);
	return (0);
}

int	is_empty(StackInt *this)
{
	if (!this)
		return (1);
	if (this->top == -1)
		return (1);
	return (0);
}

static int	has_space(StackInt *this, int data)
{
	if (!this)
		return (0);
	if (this->top + 1 < this->size)
	{
		++(this->top);
		this->buffer[this->top] = data;
		return (1);
	}
	return (0);
}

void	push(StackInt *this, int data)
{
	int	*temp;
	int	i;

	if (!this)
		return ;
	if (is_full(this))
		return ;
	if (has_space(this, data))
		return ;
	temp = (int *)malloc(sizeof(int) * (this->size * SIZE_MULTIPLIER));
	if (!temp)
		return ;
	i = 0;
	while (i < this->size)
	{
		temp[i] = this->buffer[i];
		++i;
	}
	temp[i] = data;
	free(this->buffer);
	this->buffer = temp;
	this->size = this->size * SIZE_MULTIPLIER;
	++(this->top);
}

int	pop(StackInt *this)
{
	if (!this)
		return (0);
	if (is_empty(this))
		return (-1);
	--(this->top);
	return (this->buffer[this->top + 1]);
}