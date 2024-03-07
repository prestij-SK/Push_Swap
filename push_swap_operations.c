#include "push_swap.h"

int	sa(StackInt *a)
{
	if (is_empty(a))
		return (0);
	if (a->top == 0)
		return (0);
	swap_top(a);
	write(WRTIE_OUTPUT_DESCRIPTOR, "sa\n", 3);
	return (1);
}

int	sb(StackInt *b)
{
	if (is_empty(b))
		return (0);
	if (b->top == 0)
		return (0);
	swap_top(b);
	write(WRTIE_OUTPUT_DESCRIPTOR, "sb\n", 3);
	return (1);
}

int	ss(StackInt *a, StackInt *b)
{
	if (is_empty(a) && is_empty(b))
		return (0);
	if (a->top == 0 && b->top == 0)
		return (0);
	swap_top(a);
	swap_top(b);
	write(WRTIE_OUTPUT_DESCRIPTOR, "ss\n", 3);
	return (1);
}

int	pa(StackInt *a, StackInt *b)
{
	if (is_empty(b))
		return (0);
	push(a, pop(b));
	write(WRTIE_OUTPUT_DESCRIPTOR, "pa\n", 3);
	return (1);
}

int	pb(StackInt *a, StackInt *b)
{
	if (is_empty(a))
		return (0);
	push (b, pop(a));
	write(WRTIE_OUTPUT_DESCRIPTOR, "pb\n", 3);
	return (1);
}

int	ra(StackInt *a)
{
	if (is_empty(a))
		return (0);
	if (a->top == 0)
		return (0);
	rotate_up(a);
	write(WRTIE_OUTPUT_DESCRIPTOR, "ra\n", 3);
	return (1);
}

int	rb(StackInt *b)
{
	if (is_empty(b))
		return (0);
	if (b->top == 0)
		return (0);
	rotate_up(b);
	write(WRTIE_OUTPUT_DESCRIPTOR, "rb\n", 3);
	return (1);
}

int	rr(StackInt *a, StackInt *b)
{
	if (is_empty(a) && is_empty(b))
		return (0);
	if (a->top == 0 && b->top == 0)
		return (0);
	rotate_up(a);
	rotate_up(b);
	write(WRTIE_OUTPUT_DESCRIPTOR, "rr\n", 3);
	return (1);
}

int	rra(StackInt *a)
{
	if (is_empty(a))
		return (0);
	if (a->top == 0)
		return (0);
	rotate_down(a);
	write(WRTIE_OUTPUT_DESCRIPTOR, "rra\n", 4);
	return (1);
}

int	rrb(StackInt *b)
{
	if (is_empty(b))
		return (0);
	if (b->top == 0)
		return (0);
	rotate_down(b);
	write(WRTIE_OUTPUT_DESCRIPTOR, "rrb\n", 4);
	return (1);
}

int	rrr(StackInt *a, StackInt *b)
{
	if (is_empty(a) && is_empty(b))
		return (0);
	if (a->top == 0 && b->top == 0)
		return (0);
	rotate_down(a);
	rotate_down(b);
	write(WRTIE_OUTPUT_DESCRIPTOR, "rrr\n", 4);
	return (1);
}