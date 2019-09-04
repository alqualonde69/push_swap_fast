/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:20:43 by shunt             #+#    #+#             */
/*   Updated: 2019/08/27 17:20:45 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sequence(t_ps *a, int *p)
{
	int 	i;
	int		j;
	int 	t;
	t_ps	*tmp;

	i = 0;
	j = 1;
	p[0] = 0;
	while (a->nxt && a->nxt->c)
		a = a->nxt;
	while (a->prv && a->prv->c)
	{
		tmp = a;
		t = a->n;
		j = 1;
		while (tmp->prv && tmp->n > tmp->prv->n)
		{
			tmp = tmp->prv;
			++j;
		}
		tmp->prv && tmp->prv->n > t ? ++j : 0;
		tmp->prv && tmp->prv->n > t ? tmp = tmp->prv : 0;
		while (tmp->prv && tmp->n > tmp->prv->n && tmp->prv->n > t)
		{
			tmp = tmp->prv;
			++j;
		}
		j > p[0] ? p[1] = i + j : 0;
		j > p[0] ? p[0] = j : 0;
		a = a->prv;
		++i;
	}
}
