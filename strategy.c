/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/07/25 00:00:00 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	disorder(t_stack *s)
{
	long	inversions;
	long	pairs;
	int		i;
	int		j;

	inversions = 0;
	pairs = 0;
	i = -1;
	while (++i < s->n)
	{
		j = i;
		while (++j < s->n)
		{
			pairs++;
			if (s->v[i] > s->v[j])
				inversions++;
		}
	}
	if (!pairs)
		return (0);
	return ((double)inversions / (double)pairs);
}

int	make_ranks(t_stack *a)
{
	int	*ranks;
	int	i;
	int	j;

	ranks = malloc(sizeof(int) * a->n);
	if (!ranks)
		return (0);
	i = -1;
	while (++i < a->n)
	{
		ranks[i] = 0;
		j = -1;
		while (++j < a->n)
			if (a->v[j] < a->v[i])
				ranks[i]++;
	}
	i = -1;
	while (++i < a->n)
		a->v[i] = ranks[i];
	free(ranks);
	return (1);
}

static t_strategy	select_strategy(t_strategy strategy, double value)
{
	if (strategy != ADAPTIVE)
		return (strategy);
	if (value < 0.2)
		return (SIMPLE);
	if (value < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

int	run_sort(t_ctx *c, t_strategy strategy)
{
	c->disorder = disorder(&c->a);
	c->selected_strategy = select_strategy(strategy, c->disorder);
	if (is_sorted(&c->a))
		return (1);
	if (c->a.n <= 3)
		return (small_sort(c), 1);
	if (!make_ranks(&c->a))
		return (0);
	c->b.v = malloc(sizeof(int) * c->a.n);
	if (!c->b.v)
		return (0);
	if (c->a.n <= 5)
		sort_five(c);
	else if (c->selected_strategy == SIMPLE)
		simple_sort(c);
	else if (c->selected_strategy == MEDIUM)
		medium_sort(c);
	else
		complex_sort(c);
	return (1);
}
