/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/06 22:56:29 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->n)
	{
		if (s->v[i - 1] > s->v[i])
			return (0);
		i++;
	}
	return (1);
}

static int	position(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (i < s->n && s->v[i] != value)
		i++;
	return (i);
}

void	move_to_top(t_ctx *c, t_stack *s, int value, int is_a)
{
	int	pos;

	pos = position(s, value);
	if (pos <= s->n / 2)
		while (s->v[0] != value)
			op(c, 5 + !is_a);
	else
		while (s->v[0] != value)
			op(c, 8 + !is_a);
}
