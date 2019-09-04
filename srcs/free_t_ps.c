/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 20:46:11 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 20:46:12 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_t_ps(t_ps **a, t_ps **b)
{
	t_ps	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->nxt;
		free(tmp);
	}
	while (*b)
	{
		tmp = *b;
		*b = (*b)->nxt;
		free(tmp);
	}
}