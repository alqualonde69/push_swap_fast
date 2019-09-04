/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:07:31 by shunt             #+#    #+#             */
/*   Updated: 2019/08/23 19:07:32 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	o1(t_ps *a, t_ps *b, int *t, int *i)
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

static int	o2(t_ps *a, t_ps *b, int *t, int *i)
{
	if ((a->n > b->n && a->prv->n < b->n) || (a->n == i[2] && b->n < i[2]) ||
		(a->prv->n == i[3] && b->n > i[3]))
	{
		if ((i[0] >= i[1] && i[0] < t[0]) || (i[0] < i[1] && i[1] < t[0]))
		{
			t[0] = i[0] >= i[1] ? i[0] : i[1];
			t[1] = i[0];
			t[2] = i[1];
		}
		i[1] = 0;
		return (1);
	}
	if (++i[1] >= t[0])
	{
		i[1] = 0;
		return (1);
	}
	return (0);
}

static void	o3(t_ps *a, int *t, int *i)
{
	t[0] = 2147483647;
	t[1] = 0;
	t[2] = 0;
	m_a(a, &i[3], &i[2]);
	i[0] = 0;
	i[1] = 0;
}

void		opt1(t_ps *a, t_ps *b, int *t)
{
	t_ps	*ha;
	int		i[4];

	o3(a, t, i);
	ha = a;
	while (b && b->c)
	{
		if (o1(a, b, t, i))
			break ;
		a = a->nxt;
		while (a && a->c)
		{
			if (o2(a, b, t, i))
			{
				a = ha;
				break ;
			}
			a = a->nxt;
		}
		if (++i[0] >= t[0])
			break ;
		b = b->nxt;
	}
}
