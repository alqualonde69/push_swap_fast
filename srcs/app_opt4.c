/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_opt4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:40:46 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:40:47 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	app_opt4(t_ps **a, t_ps **b, t_rl **rules, int *n)
{
	int		i;

	i = -1;
	while (++i < n[1])
	{
		applyrule(a, b, "rb");
		add_t_rl(rules, "rb");
	}
	i = -1;
	while (++i < n[2])
	{
		applyrule2(a, b, "rra");
		add_t_rl(rules, "rra");
	}
	applyrule(a, b, "pa");
	add_t_rl(rules, "pa");
}
