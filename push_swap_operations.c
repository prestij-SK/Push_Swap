#include "push_swap.h"

// int	sa_sb_ss(StackInt *a, StackInt *b, char c)
// {
// 	if (c != 'a' && c != 'b' && c != 's')
// 		return (0);
// 	if (c == 'a')
// 	{
// 		if (is_empty(a))
// 			return (0);
// 		swap_top(a);
// 		printf("sa\n"); // <---------- LIBFT
// 	}
// 	else if (c == 'b')
// 	{
// 		if (is_empty(b))
// 			return (0);
// 		swap_top(b);
// 		printf("sb\n"); // <---------- LIBFT
// 	}
// 	else if (c == 's')
// 	{
// 		if (is_empty(a) && is_empty(b))
// 			return (0);
// 		swap_top(a);
// 		swap_top(b);
// 		printf("ss\n"); // <---------- LIBFT
// 	}
// 	return (1);
// }

// int	pa_pb(StackInt *a, StackInt *b, char c)
// {
// 	if (c != 'a' && c != 'b')
// 		return (0);
// 	if (c == 'a')
// 	{
// 		if (is_empty(b))
// 			return (0);
// 		push(a, pop(b));
// 		printf("pa\n"); // <---------- LIBFT
// 	}
// 	else if (c == 'b')
// 	{
// 		if (is_empty(a))
// 			return (0);
// 		push (b, pop(a));
// 		printf("pb\n"); // <---------- LIBFT
// 	}
// 	return (1);
// }

// int	ra_rb_rr(StackInt *a, StackInt *b, char c)
// {
// 	if (c != 'a' && c != 'b' && c != 'r')
// 		return (0);
// 	if (c == 'a')
// 	{
// 		if (is_empty(a))
// 			return (0);
// 		rotate_up(a);
// 		printf("ra\n"); // <---------- LIBFT
// 	}
// 	else if (c == 'b')
// 	{
// 		if (is_empty(b))
// 			return (0);
// 		rotate_up(b);
// 		printf("rb\n"); // <---------- LIBFT
// 	}
// 	else if (c == 'r')
// 	{
// 		if (is_empty(a) && is_empty(b))
// 			return (0);
// 		rotate_up(a);
// 		rotate_up(b);
// 		printf("rr\n"); // <---------- LIBFT
// 	}
// 	return (1);
// }

// int	rra_rrb_rrr(StackInt *a, StackInt *b, char c)
// {
// 	if (c != 'a' && c != 'b' && c != 'r')
// 		return (0);
// 	if (c == 'a')
// 	{
// 		if (is_empty(a))
// 			return (0);
// 		rotate_down(a);
// 		printf("rra\n"); // <---------- LIBFT
// 	}
// 	else if (c == 'b')
// 	{
// 		if (is_empty(b))
// 			return (0);
// 		rotate_down(b);
// 		printf("rrb\n"); // <---------- LIBFT
// 	}
// 	else if (c == 'r')
// 	{
// 		if (is_empty(a) && is_empty(b))
// 			return (0);
// 		rotate_down(a);
// 		rotate_down(b);
// 		printf("rrr\n"); // <---------- LIBFT
// 	}
// 	return (1);
// }

int	sa(StackInt *a)
{
	if (is_empty(a))
		return (0);
	if (a->top == 0)
		return (0);
	swap_top(a);
	printf("sa\n"); // <---------- LIBFT
	return (1);
}

int	sb(StackInt *b)
{
	if (is_empty(b))
		return (0);
	if (b->top == 0)
		return (0);
	swap_top(b);
	printf("sb\n"); // <---------- LIBFT
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
	printf("ss\n"); // <---------- LIBFT
	return (1);
}

int	pa(StackInt *a, StackInt *b)
{
	if (is_empty(b))
		return (0);
	push(a, pop(b));
	printf("pa\n"); // <---------- LIBFT
	return (1);
}

int	pb(StackInt *a, StackInt *b)
{
	if (is_empty(a))
		return (0);
	push (b, pop(a));
	printf("pb\n"); // <---------- LIBFT
	return (1);
}

int	ra(StackInt *a)
{
	if (is_empty(a))
		return (0);
	if (a->top == 0)
		return (0);
	rotate_up(a);
	printf("ra\n"); // <---------- LIBFT
	return (1);
}

int	rb(StackInt *b)
{
	if (is_empty(b))
		return (0);
	if (b->top == 0)
		return (0);
	rotate_up(b);
	printf("rb\n"); // <---------- LIBFT
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
	printf("rr\n"); // <---------- LIBFT
	return (1);
}

int	rra(StackInt *a)
{
	if (is_empty(a))
		return (0);
	if (a->top == 0)
		return (0);
	rotate_down(a);
	printf("rra\n"); // <---------- LIBFT
	return (1);
}

int	rrb(StackInt *b)
{
	if (is_empty(b))
		return (0);
	if (b->top == 0)
		return (0);
	rotate_down(b);
	printf("rrb\n"); // <---------- LIBFT
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
	printf("rrr\n"); // <---------- LIBFT
	return (1);
}