#include "push_swap.h"

void	sa_sb_ss(StackInt *a, StackInt *b, char c)
{
	if (c == 'a')
	{
		if (!a)
			return ;
		swap_top(a);
		printf("sa\n"); // <---------- LIBFT
	}
	else if (c == 'b')
	{
		if (!b)
			return ;
		swap_top(b);
		printf("sb\n"); // <---------- LIBFT
	}
	else if (c == 's')
	{
		if (!a && !b)
			return ;
		swap_top(a);
		swap_top(b);
		printf("ss\n"); // <---------- LIBFT
	}
}

void	pa_pb(StackInt *a, StackInt *b, char c)
{
	if (c == 'a')
	{
		if (!b)
			return ;
		push(a, pop(b));
		printf("pa\n"); // <---------- LIBFT
	}
	else if (c == 'b')
	{
		if (!a)
			return ;
		push (b, pop(a));
		printf("pb\n"); // <---------- LIBFT
	}
}

void	ra_rb_rr(StackInt *a, StackInt *b, char c)
{
	if (c == 'a')
	{
		if (!a)
			return ;
		rotate_up(a);
		printf("ra\n"); // <---------- LIBFT
	}
	else if (c == 'b')
	{
		if (!b)
			return ;
		rotate_up(b);
		printf("rb\n"); // <---------- LIBFT
	}
	else if (c == 'r')
	{
		if (!a && !b)
			return ;
		rotate_up(a);
		rotate_up(b);
		printf("rr\n"); // <---------- LIBFT
	}
}

void	rra_rrb_rrr(StackInt *a, StackInt *b, char c)
{
	if (c == 'a')
	{
		if (!a)
			return ;
		rotate_down(a);
		printf("rra\n"); // <---------- LIBFT
	}
	else if (c == 'b')
	{
		if (!b)
			return ;
		rotate_down(b);
		printf("rrb\n"); // <---------- LIBFT
	}
	else if (c == 'r')
	{
		if (!a && !b)
			return ;
		rotate_down(a);
		rotate_down(b);
		printf("rrr\n"); // <---------- LIBFT
	}
}