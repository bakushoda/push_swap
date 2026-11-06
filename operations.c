/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/06 22:56:20 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	int	x;

	if (s->n < 2)
		return ;
	x = s->v[0];
	s->v[0] = s->v[1];
	s->v[1] = x;
}

static void	push(t_stack *to, t_stack *from)
{
	int	i;

	if (!from->n)
		return ;
	i = to->n;
	while (i > 0)
	{
		to->v[i] = to->v[i - 1];
		i--;
	}
	to->v[0] = from->v[0];
	to->n++;
	i = 0;
	while (i < from->n - 1)
	{
		from->v[i] = from->v[i + 1];
		i++;
	}
	from->n--;
}

static void	rotate(t_stack *s, int reverse)
{
	int	x;
	int	i;
	int	direction;

	if (s->n < 2)
		return ;
	i = 0;
	direction = 1;
	if (reverse)
	{
		i = s->n - 1;
		direction = -1;
	}
	x = s->v[i];
	while (i + direction >= 0 && i + direction < s->n)
	{
		s->v[i] = s->v[i + direction];
		i += direction;
	}
	s->v[i] = x;
}

static void	apply(t_ctx *c, int code)
{
	if (code == 0 || code == 2)
		swap(&c->a);
	if (code == 1 || code == 2)
		swap(&c->b);
	if (code == 3)
		push(&c->a, &c->b);
	if (code == 4)
		push(&c->b, &c->a);
	if (code == 5 || code == 7)
		rotate(&c->a, 0);
	if (code == 6 || code == 7)
		rotate(&c->b, 0);
	if (code == 8 || code == 10)
		rotate(&c->a, 1);
	if (code == 9 || code == 10)
		rotate(&c->b, 1);
}

void	op(t_ctx *c, int code)
{
	static char	*names[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int			len;

	apply(c, code);
	c->count[code]++;
	len = 3;
	if (code >= 8)
		len = 4;
	write(1, names[code], len);
}
