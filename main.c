/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/04 23:04:38 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_ctx *c)
{
	int	i;

	c->a.v = NULL;
	c->a.n = 0;
	c->b.v = NULL;
	c->b.n = 0;
	c->bench = 0;
	c->disorder = 0;
	i = 0;
	while (i < 11)
	{
    	c->count[i] = 0;
    	i++;
	}
}

int	main(int ac, char **av)
{
	t_ctx		c;
	t_strategy	strategy;

	init(&c);
	if (!parse_args(ac, av, &c, &strategy) || !run_sort(&c, strategy))
	{
		write(2, "Error\n", 6);
		free(c.a.v);
		free(c.b.v);
		return (1);
	}
	if (c.bench)
		print_bench(&c);
	free(c.a.v);
	free(c.b.v);
	return (0);
}
