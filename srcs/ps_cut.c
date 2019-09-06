/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:52:17 by shunt             #+#    #+#             */
/*   Updated: 2019/09/06 18:52:18 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pc1(int ***t, int ***s, int i)
{
	if (!(*t = (int **)malloc(sizeof(int *) * 4)))
		return (1);
	if (!(*s = (int **)malloc(sizeof(int *) * 2)))
	{
		free(*t);
		return (1);
	}
	if (!((*s)[1] = (int *)malloc(sizeof(int) * 2)))
	{
		free(*t);
		free(*s);
		return (1);
	}
	while (++i < 4)
		if (!((*t)[i] = (int *)malloc(sizeof(int) * 3)))
		{
			free(*t);
			free((*s)[1]);
			free(*s);
			return (1);
		}
	return (0);
}

int		pc2(int ***t, int ***s, t_ps *a, int sz)
{
	int		i;

	if ((sz > 3 && sequence(a, &(*s)[0], &(*s)[1][1])))
	{
		i = -1;
		while (++i < 4)
			free((*t)[i]);
		free(*t);
		free((*s)[1]);
		free(*s);
		return (1);
	}
	if (issort(a) || sz == 1)
	{
		i = -1;
		while (++i < 4)
			free((*t)[i]);
		free(*t);
		sz > 3 ? free((*s)[0]) : 0;
		free((*s)[1]);
		free(*s);
		return (1);
	}
	return (0);
}
