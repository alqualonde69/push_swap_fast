/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:28:32 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:28:34 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_rule(char *rule)
{
	if (!(ft_strcmp(rule, "sa")))
		return (0);
	if (!(ft_strcmp(rule, "sb")))
		return (0);
	if (!(ft_strcmp(rule, "ss")))
		return (0);
	if (!(ft_strcmp(rule, "pa")))
		return (0);
	if (!(ft_strcmp(rule, "pb")))
		return (0);
	if (!(ft_strcmp(rule, "ra")))
		return (0);
	if (!(ft_strcmp(rule, "rb")))
		return (0);
	if (!(ft_strcmp(rule, "rr")))
		return (0);
	if (!(ft_strcmp(rule, "rra")))
		return (0);
	if (!(ft_strcmp(rule, "rrb")))
		return (0);
	if (!(ft_strcmp(rule, "rrr")))
		return (0);
	return (1);
}
