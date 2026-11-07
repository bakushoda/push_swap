/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/07 17:10:41 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static long	read_digits(char *text, int *digit_count)
{
	long	number;

	number = 0;
	*digit_count = 0;
	while (text[*digit_count] >= '0' && text[*digit_count] <= '9')
	{
		number = number * 10 + text[*digit_count] - '0';
		(*digit_count)++;
		if (number > 2147483648L)
			break ;
	}
	return (number);
}

static char	*read_int(char *text, int *value)
{
	long	number;
	int		sign;
	int		digit_count;

	while (is_space(*text))
		text++;
	sign = 1;
	if (*text == '-' || *text == '+')
	{
		if (*text == '-')
			sign = -1;
		text++;
	}
	number = read_digits(text, &digit_count) * sign;
	text += digit_count;
	if (!digit_count || (*text && !is_space(*text)))
		return (NULL);
	if (number < INT_MIN || number > INT_MAX)
		return (NULL);
	*value = (int)number;
	return (text);
}

static int	add_values(char *s, int *values, int *n)
{
	int	i;
	int	value;

	while (*s)
	{
		s = read_int(s, &value);
		if (!s)
			return (0);
		i = 0;
		while (i < *n)
		{
			if (values[i] == value)
				return (0);
			i++;
		}
		values[*n] = value;
		(*n)++;
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
	i = 1;
	while (i < ac)
	{
		flag = parse_flag(av[i], c, strategy, &seen);
		if (!flag || (flag == -1 && !add_values(av[i], c->a.v, &c->a.n)))
			return (0);
		i++;
	}
	return (1);
}
