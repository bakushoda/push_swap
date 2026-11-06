/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshoda <bshoda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by bshoda            #+#    #+#             */
/*   Updated: 2026/11/06 21:15:43 by bshoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_stack
{
	int	*v;
	int	n;
}	t_stack;

typedef struct s_ctx
{
	t_stack		a;
	t_stack		b;
	long		count[11];
	int			bench;
	double		disorder;
	t_strategy	selected_strategy;
}	t_ctx;

int		parse_args(int ac, char **av, t_ctx *c, t_strategy *strategy);
int		allocate_values(int ac, char **av, t_ctx *c);
int		parse_flag(char *s, t_ctx *c, t_strategy *strategy, int *seen);
int		is_sorted(t_stack *s);
int		make_ranks(t_stack *a);
int		run_sort(t_ctx *c, t_strategy strategy);
void	small_sort(t_ctx *c);
void	sort_five(t_ctx *c);
void	move_to_top(t_ctx *c, t_stack *s, int value, int is_a);
void	simple_sort(t_ctx *c);
void	medium_sort(t_ctx *c);
void	complex_sort(t_ctx *c);
void	op(t_ctx *c, int code);
void	print_number(long n, int fd);
long	total_operations(t_ctx *c);
void	print_bench(t_ctx *c);

#endif
