/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/06 22:56:58 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_number(long n, int fd)
{
	char	c;

	if (n >= 10)
		print_number(n / 10, fd);
	c = '0' + n % 10;
	write(fd, &c, 1);
}

static void	putstr(char *s)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	write(2, s, n);
}

static void	print_disorder(double value)
{
	long	n;

	n = (long)(value * 10000.0 + 0.5);
	print_number(n / 100, 2);
	write(2, ".", 1);
	if (n % 100 < 10)
		write(2, "0", 1);
	print_number(n % 100, 2);
	putstr("%\n");
}

long	total_operations(t_ctx *c)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total += c->op_counts[i];
		i++;
	}
	return (total);
}

void	print_bench(t_ctx *c)
{
	static char	*names[4] = {"adaptive", "simple O(n^2)",
		"medium O(n*sqrt(n))", "complex O(n*log(n))"};
	static char	*ops[11] = {"sa: ", "sb: ", "ss: ", "pa: ", "pb: ",
		"ra: ", "rb: ", "rr: ", "rra: ", "rrb: ", "rrr: "};
	int			i;

	putstr("disorder: ");
	print_disorder(c->disorder);
	putstr("strategy: ");
	putstr(names[c->selected_strategy]);
	putstr("\noperations: ");
	print_number(total_operations(c), 2);
	putstr("\n");
	i = 0;
	while (i < 11)
	{
		(putstr(ops[i]), print_number(c->op_counts[i], 2), putstr("\n"));
		i++;
	}
}
