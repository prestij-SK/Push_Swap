#include "my_stack.h"

StackInt	*create_stack(int *arr, int size)
{
	StackInt	*stack_new;
	int			i;

	if (!arr)
		return (NULL);
	stack_new = (StackInt *)malloc(sizeof(StackInt));
	if (!stack_new)
		return (NULL);
	stack_new->stack = (int *)malloc(sizeof(int) * size);
	if (!stack_new->stack)
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

StackInt	*create_stack_empty(int size)
{
	StackInt	*stack_new;

	if (size <= 0)
		size = 1;
	stack_new = (StackInt *)malloc(sizeof(StackInt));
	if (!stack_new)
		return (NULL);
	stack_new->stack = (int *)malloc(sizeof(int) * size);
	if (!stack_new->stack)
	{
		free(stack_new);
		return (NULL);
	}
	stack_new->size = size;
	stack_new->top = -1;
	return (stack_new);
}

void	delete_stack(StackInt *this)
{
	if (!this)
		return ;
	free(this->stack);
	this->stack = NULL;
	this->size = 0;
	this->top = -1;
	free(this);
	this = NULL;
}

int	is_full(StackInt *this)
{
	if (!this)
		return (0);
	if (this->top + 2 < 0)
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
		this->stack[this->top] = data;
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
		temp[i] = this->stack[i];
		++i;
	}
	temp[i] = data;
	free(this->stack);
	this->stack = temp;
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
	return (this->stack[this->top + 1]);
}

void	swap_top(StackInt *this)
{
	int	temp;

	if (!this)
		return ;
	if (this->top == 0)
		return ;
	temp = this->stack[this->top];
	this->stack[this->top] = this->stack[this->top - 1];
	this->stack[this->top - 1] = temp;
}

void	rotate_up(StackInt *this)
{
	int	temp;
	int	i;

	if (!this)
		return ;
	if (this->top == 0)
		return ;
	temp = this->stack[this->top];
	i = this->top;
	while (i >= 1)
	{
		this->stack[i] = this->stack[i - 1];
		--i;
	}
	this->stack[i] = temp;
}

void	rotate_down(StackInt *this)
{
	int	temp;
	int	i;

	if (!this)
		return ;
	if (this->top == 0)
		return ;
	temp = this->stack[0];
	i = 0;
	while (i < this->top)
	{
		this->stack[i] = this->stack[i + 1];
		++i;
	}
	this->stack[i] = temp;
}

int	stack_is_sorted(StackInt *s)
{
	int	i;

	if (is_empty(s))
		return (0);
	i = s->top;
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
		{
			return (0);
		}
		--i;
	}
	return (1);
}

void	display_stack(StackInt *this)
{
	int	i;

	if (!this)
		return ;
	i = this->top;
	while (i >= 0)
	{
		printf("[ %d ]\n", this->stack[i]); // <--------------- libft
		--i;
	}
	printf("--------\n"); // <--------------- libft
}