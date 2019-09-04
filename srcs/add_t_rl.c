/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_t_rl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:56:08 by shunt             #+#    #+#             */
/*   Updated: 2019/08/23 18:56:11 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_t_rl(t_rl **rules, char *s)
{
	t_rl	*tmp;
	t_rl	*head;

	if (!(tmp = (t_rl *)malloc(sizeof(t_rl))))
		return ;
	tmp->s = s;
	tmp->nxt = NULL;
	tmp->prv = NULL;
	if (!(*rules))
		*rules = tmp;
	else
	{
		head = *rules;
		while (head->nxt)
			head = head->nxt;
		head->nxt = tmp;
		tmp->prv = head;
	}
}
