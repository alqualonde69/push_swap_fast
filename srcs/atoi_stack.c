/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:27:37 by shunt             #+#    #+#             */
/*   Updated: 2019/08/13 21:27:39 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*atoi_stack(char **av, unsigned short f)
{
	t_ps	*head;
	t_ps	*a;

	if (is_nu(av, f))
		return (NULL);
	if (chckstack(av, f))
		return (NULL);
	if (!(head = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	hd(&head, av, &f);
	a = head;
	while (av[++f])
	{
		if (!(a->nxt = (t_ps *)malloc(sizeof(t_ps))))
			return (NULL);
		a->nxt->prv = a;
		a = a->nxt;
		a->n = ft_atoi(av[f]);
		a->c = 1;
		a->nxt = NULL;
	}
	if (isdup(head))
		return (NULL);
	return (head);
}
