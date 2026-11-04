/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/07/25 00:00:00 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_ctx *c)
{
	int	bit;
	int	size;
	int	i;

	bit = 0;
	while (((c->a.n - 1) >> bit) != 0)
	{
		size = c->a.n;
		i = -1;
		while (++i < size)
		{
			if ((c->a.v[0] >> bit) & 1)
				op(c, 5);
			else
				op(c, 4);
		}
		while (c->b.n)
			op(c, 3);
		bit++;
	}
}
