/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/06 22:56:34 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_ctx *c)
{
	int	a;
	int	b;
	int	d;

	a = c->a.v[0];
	b = c->a.v[1];
	if (c->a.n == 2 && a > b)
		return (op(c, 0));
	if (c->a.n < 3)
		return ;
	d = c->a.v[2];
	if (a > b && b < d && a < d)
		op(c, 0);
	else if (a > b && b > d)
		(op(c, 0), op(c, 8));
	else if (a > b && b < d && a > d)
		op(c, 5);
	else if (a < b && b > d && a < d)
		(op(c, 0), op(c, 5));
	else if (a < b && b > d && a > d)
		op(c, 8);
}

void	sort_five(t_ctx *c)
{
	int	next;

	next = 0;
	while (c->a.n > 3)
	{
		move_to_top(c, &c->a, next, 1);
		op(c, 4);
		next++;
	}
	small_sort(c);
	while (c->b.n)
		op(c, 3);
}

void	simple_sort(t_ctx *c)
{
	int	min;
	int	i;

	while (c->a.n > 1)
	{
		min = c->a.v[0];
		i = 1;
		while (i < c->a.n)
		{
			if (c->a.v[i] < min)
				min = c->a.v[i];
			i++;
		}
		move_to_top(c, &c->a, min, 1);
		op(c, 4);
	}
	while (c->b.n)
		op(c, 3);
}
