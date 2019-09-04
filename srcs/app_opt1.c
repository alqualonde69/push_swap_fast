/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_opt1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:38:35 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:38:36 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_opt1(t_ps **a, t_ps **b, t_rl **rules, int *n)
{
	int		i;
	int		j;

	i = 0;
	j = n[1] <= n[2] ? n[1] : n[2];
	while (i < j)
	{
		applyrule(a, b, "rr");
		add_t_rl(rules, "rr");
		++i;
	}
	while (i < n[2])
	{
		applyrule(a, b, "ra");
		add_t_rl(rules, "ra");
		++i;
	}
	while (i < n[1])
	{
		applyrule(a, b, "rb");
		add_t_rl(rules, "rb");
		++i;
	}
	applyrule(a, b, "pa");
	add_t_rl(rules, "pa");
}
