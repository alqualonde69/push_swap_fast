/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:08:53 by shunt             #+#    #+#             */
/*   Updated: 2019/08/23 19:08:55 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	o1(int *t, int *i, t_ps *a, t_ps *b)
{
	t[0] = 2147483647;
	t[1] = 0;
	t[2] = 0;
	m_a(a, &i[3], &i[2]);
	i[0] = 0;
	i[1] = 0;
	i[4] = 1;
	while (b->nxt && b->nxt->c)
	{
		b = b->nxt;
		t[1] = 1;
		i[0] = 1;
		++i[4];
	}
}

static int	o2(t_ps *a, t_ps *b, int *i, int *t)
{
	if ((a->n > b->n && last_a(a) < b->n) || (a->n == i[2] && b->n > i[3]) ||
		(a->n == i[2] && b->n < i[2]))
	{
		i[0] < t[0] ? t[1] = i[0] : 0;
		i[0] < t[0] ? t[2] = 0 : 0;
		i[0] < t[0] ? t[0] = i[0] : 0;
		return (1);
	}
	++i[1];
	return (0);
}

static int	o3(t_ps *a, t_ps *b, int *i, int *t)
{
	if ((a->n > b->n && a->prv->n < b->n) || (a->n == i[2] && b->n < a->n) ||
		(a->prv->n == i[3] && b->n > i[3]))
	{
		if (i[0] + i[1] < t[0])
		{
			t[0] = i[0] + i[1];
			t[1] = i[0];
			t[2] = i[1];
		}
		i[1] = 0;
		return (1);
	}
	if (++i[1] + i[0] >= t[0])
	{
		i[1] = 0;
		return (1);
	}
	return (0);
}

void		opt3(t_ps *a, t_ps *b, int *t)
{
	t_ps	*ha;
	int		i[5];

	o1(t, i, a, b);
	ha = a;
	while (b && b->c)
	{
		if (o2(a, b, i, t))
			break ;
		a = a->nxt;
		while (a && a->c)
		{
			if (o3(a, b, i, t))
			{
				a = ha;
				break ;
			}
			a = a->nxt;
		}
		if (++i[0] >= t[0] || i[0] >= i[4])
			break ;
		b = b->prv;
	}
}
