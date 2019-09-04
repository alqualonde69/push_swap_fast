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

//void	sequence2(t_ps *a, int **s, int j, int *k)
//{
//	while (a && a->c)
//	{
//		if (j == -1 || (j > -1 && a->n > s[0][j]))
//		{
//			s[0][++j] = a->n;
//			sequence2(a->nxt, s, j, k);
//			--j;
//		}
//		a = a->nxt;
//	}
//	if (j + 1 > *k)
//	{
//		*k = j + 1;
//		j = -1;
//		while (++j < *k)
//			s[1][j] = s[0][j];
//	}
//}

int		sequence3(t_ps *a, int **s, int *k)
{
	t_ps	*tmp;
	t_ps	*ts;
	int 	b[8];

	b[4] = 0;
	b[0] = 0;
	ts = a;
	while (a && a->nxt && a->nxt->c)
	{
		b[6] = 1;
		b[7] = 0;
		tmp = a->nxt;
		b[3] = a->n;
		while (tmp && tmp->c)
		{
			if (tmp->n > b[3])
			{
				++b[6];
				b[3] = tmp->n;
			}
			tmp = tmp->nxt;
		}
		if (b[4] > 0)
		{
			b[5] = -1;
			tmp = ts;
			while (++b[5] < b[4])
			{
				if (tmp->n > b[3])
				{
					++b[7];
					b[3] = tmp->n;
				}
				tmp = tmp->nxt;
			}
		}
		if (b[6] + b[7] > b[0])
		{
			b[0] = b[6] + b[7];
			b[1] = b[4];
			b[2] = b[7];
		}
		++b[4];
		a = a->nxt;
	}
	*k = b[0];
	if (!(*s = (int *)malloc(sizeof(int) * b[0])))
		return (1);
	a = ts;
	b[5] = -1;
	while (++b[5] < b[1])
		a = a->nxt;
	b[0] = b[2];
	(*s)[b[2]] = a->n;
	while (a && a->c)
	{
		if (a->n > (*s)[b[2]])
			(*s)[++b[2]] = a->n;
		a = a->nxt;
	}
	if (b[0])
	{
		b[1] = 0;
		while (ts->n < (*s)[b[2]])
			ts = ts->nxt;
		(*s)[b[1]] = ts->n;
		ts = ts->nxt;
		while (b[1] + 1 < b[0])
		{
			if (ts->n > (*s)[b[1]])
				(*s)[++b[1]] = ts->n;
			ts = ts->nxt;
		}
	}
	return (0);
}
