/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mn_ra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:04:31 by shunt             #+#    #+#             */
/*   Updated: 2019/08/23 19:04:32 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min(t_ps *a)
{
	int		mn;

	mn = a->n;
	while (a)
	{
		a->n < mn ? mn = a->n : 0;
		a = a->nxt;
	}
	return (mn);
}

int		is_mn_ra(t_ps *a, int *t)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	*t = min(a);
	while (a->n != *t)
	{
		a = a->nxt;
		++i;
	}
	while (a->nxt && a->nxt->c)
		a = a->nxt;
	while (a->n != *t)
	{
		a = a->prv;
		++j;
	}
	return (i <= j ? 1 : 0);
}
