/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:28:27 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:28:29 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ps **dst, t_ps **src)
{
	while (*dst && (*dst)->c)
		*dst = (*dst)->nxt;
	while (*dst && (*dst)->prv)
	{
		(*dst)->c = (*dst)->prv->c;
		(*dst)->n = (*dst)->prv->n;
		*dst = (*dst)->prv;
	}
	(*dst)->n = (*src)->n;
	(*dst)->c = (*src)->c;
	(*src)->n = 0;
	(*src)->c = 0;
	if ((*src)->nxt && (*src)->nxt->c)
	{
		while ((*src)->nxt && (*src)->nxt->c)
		{
			(*src)->n = (*src)->nxt->n;
			(*src)->c = (*src)->nxt->c;
			*src = (*src)->nxt;
		}
		(*src)->n = 0;
		(*src)->c = 0;
		while ((*src)->prv)
			*src = (*src)->prv;
	}
}
