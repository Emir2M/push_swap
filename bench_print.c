/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 03:20:00 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 03:20:00 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_config *config)
{
	putstr_err("[bench] strategy:  ");
	if (config->strategy == SIMPLE)
		putstr_err("Simple / O(n^2)\n");
	else if (config->strategy == MEDIUM)
		putstr_err("Medium / O(n*sqrt(n))\n");
	else if (config->strategy == COMPLEX)
		putstr_err("Complex / O(n log n)\n");
	else if (config->disorder < 0.2)
		putstr_err("Adaptive / O(n^2)\n");
	else if (config->disorder < 0.5)
		putstr_err("Adaptive / O(n*sqrt(n))\n");
	else
		putstr_err("Adaptive / O(n log n)\n");
}

static void	print_ops(t_config *config)
{
	putstr_err("[bench] ");
	print_op_err("sa", config->op_count[OP_SA], 1);
	print_op_err("sb", config->op_count[OP_SB], 1);
	print_op_err("ss", config->op_count[OP_SS], 1);
	print_op_err("pa", config->op_count[OP_PA], 1);
	print_op_err("pb", config->op_count[OP_PB], 2);
	print_op_err("ra", config->op_count[OP_RA], 1);
	print_op_err("rb", config->op_count[OP_RB], 1);
	print_op_err("rr", config->op_count[OP_RR], 1);
	print_op_err("rra", config->op_count[OP_RRA], 1);
	print_op_err("rrb", config->op_count[OP_RRB], 1);
	print_op_err("rrr", config->op_count[OP_RRR], 0);
}

void	print_bench(t_config *config)
{
	int	pct;

	if (!config || !config->bench_mode)
		return ;
	pct = (int)(config->disorder * 10000);
	putstr_err("[bench] disorder:  ");
	putnbr_err(pct / 100);
	putstr_err(".");
	if (pct % 100 < 10)
		putstr_err("0");
	putnbr_err(pct % 100);
	putstr_err("%\n");
	print_strategy(config);
	putstr_err("[bench] total_ops: ");
	putnbr_err(config->total_operations);
	putstr_err("\n");
	print_ops(config);
}
