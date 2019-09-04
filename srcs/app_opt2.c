/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_opt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:39:47 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:39:49 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_opt2(t_ps **a, t_ps **b, t_rl **rules, int *n)
{
	int		i;
	int		j;

	i = 0;
	j = n[1] <= n[2] ? n[1] : n[2];
	while (i < j)
	{
		applyrule2(a, b, "rrr");
		add_t_rl(rules, "rrr");
		++i;
	}
	while (i < n[2])
	{
		applyrule2(a, b, "rra");
		add_t_rl(rules, "rra");
		++i;
	}
	while (i < n[1])
	{
		applyrule2(a, b, "rrb");
		add_t_rl(rules, "rrb");
		++i;
	}
	applyrule(a, b, "pa");
	add_t_rl(rules, "pa");
}
