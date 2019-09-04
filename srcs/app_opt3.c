/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_opt3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:40:07 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:40:10 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_opt3(t_ps **a, t_ps **b, t_rl **rules, int *n)
{
	int		i;

	i = -1;
	while (++i < n[1])
	{
		applyrule2(a, b, "rrb");
		add_t_rl(rules, "rrb");
	}
	i = -1;
	while (++i < n[2])
	{
		applyrule(a, b, "ra");
		add_t_rl(rules, "ra");
	}
	applyrule(a, b, "pa");
	add_t_rl(rules, "pa");
}
