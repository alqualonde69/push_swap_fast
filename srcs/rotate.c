/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:28:44 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:28:45 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_ps **stack)
{
	int		tmp;

	while ((*stack)->nxt && (*stack)->nxt->c)
		*stack = (*stack)->nxt;
	tmp = (*stack)->n;
	while ((*stack)->prv)
	{
		(*stack)->n = (*stack)->prv->n;
		*stack = (*stack)->prv;
	}
	(*stack)->n = tmp;
}

void	rotate(t_ps **stack)
{
	int		tmp;

	tmp = (*stack)->n;
	while ((*stack)->nxt && (*stack)->nxt->c)
	{
		(*stack)->n = (*stack)->nxt->n;
		*stack = (*stack)->nxt;
	}
	(*stack)->n = tmp;
	while ((*stack)->prv)
		*stack = (*stack)->prv;
}
