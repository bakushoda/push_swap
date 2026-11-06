/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/06 22:56:39 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(int n)
{
	int	x;

	x = 1;
	while (x * x < n)
		x++;
	return (x);
}

void	medium_sort(t_ctx *c)
{
	int	width;
	int	pushed;

	width = square_root(c->a.n) + 1;
	pushed = 0;
	while (c->a.n)
	{
		if (c->a.v[0] <= pushed)
			(op(c, 4), op(c, 6), pushed++);
		else if (c->a.v[0] < pushed + width)
			(op(c, 4), pushed++);
		else
			op(c, 5);
	}
	while (c->b.n)
	{
		move_to_top(c, &c->b, c->b.n - 1, 0);
		op(c, 3);
	}
}
