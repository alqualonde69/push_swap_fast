/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 19:49:29 by shunt             #+#    #+#             */
/*   Updated: 2019/08/14 19:49:31 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*b_stack(int i)
{
	int		j;
	t_ps	*head;
	t_ps	*b;

	if (!(head = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	head->prv = NULL;
	head->nxt = NULL;
	head->c = 0;
	head->n = 0;
	b = head;
	j = -1;
	while (++j < i - 1)
	{
		if (!(b->nxt = (t_ps *)malloc(sizeof(t_ps))))
			return (NULL);
		b->nxt->prv = b;
		b = b->nxt;
		b->n = 0;
		b->c = 0;
		b->nxt = NULL;
	}
	return (head);
}
