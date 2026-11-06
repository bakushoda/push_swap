/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/03 19:54:38 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	allocate_values(int ac, char **av, t_ctx *c)
{
	int	i;
	int	len;
	int	capacity;

	capacity = ac;
	i = 1;
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
			len++;
		capacity += len / 2;
		i++;
	}
	c->a.v = malloc(sizeof(int) * capacity);
	if (c->a.v != NULL)
		return (1);
	return (0);
}

static int	equal(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

static int	strategy_flag(char *s, t_strategy *strategy, int *seen)
{
	char	*flag_names[4];
	int		i;

	flag_names[0] = "--adaptive";
	flag_names[1] = "--simple";
	flag_names[2] = "--medium";
	flag_names[3] = "--complex";
	i = 0;
	while (i < 4)
	{
		if (equal(s, flag_names[i]) && !*seen)
		{
			*seen = 1;
			*strategy = (t_strategy)i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_flag(char *s, t_ctx *c, t_strategy *strategy, int *seen)
{
	if (!s[0])
		return (0);
	if (!s[1] || s[0] != '-' || s[1] != '-')
		return (-1);
	if (equal(s, "--bench"))
	{
		c->bench = 1;
		return (1);
	}
	return (strategy_flag(s, strategy, seen));
}
