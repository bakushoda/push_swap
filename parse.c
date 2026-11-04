/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/07/25 00:00:00 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static long	read_digits(char **s, int *digits)
{
	long	n;

	n = 0;
	*digits = 0;
	while (**s >= '0' && **s <= '9')
	{
		n = n * 10 + *(*s)++ - '0';
		(*digits)++;
		if (n > 2147483648L)
			break ;
	}
	return (n);
}

static int	read_int(char **s, int *value)
{
	long	n;
	int		sign;
	int		digits;

	while (is_space(**s))
		(*s)++;
	sign = 1;
	if (**s == '-' || **s == '+')
		if (*(*s)++ == '-')
			sign = -1;
	n = read_digits(s, &digits);
	if (!digits || (!is_space(**s) && **s))
		return (0);
	n *= sign;
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	*value = (int)n;
	return (1);
}

static int	add_values(char *s, int *values, int *n)
{
	int	i;
	int	value;

	while (*s)
	{
		if (!read_int(&s, &value))
			return (0);
		i = 0;
		while (i < *n)
			if (values[i++] == value)
				return (0);
		values[(*n)++] = value;
		while (is_space(*s))
			s++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_ctx *c, t_strategy *strategy)
{
	int	i;
	int	seen;
	int	flag;

	if (!allocate_values(ac, av, c))
		return (0);
	*strategy = ADAPTIVE;
	seen = 0;
	i = 0;
	while (++i < ac)
	{
		flag = parse_flag(av[i], c, strategy, &seen);
		if (!flag || (flag < 0 && !add_values(av[i], c->a.v, &c->a.n)))
			return (0);
	}
	return (1);
}
