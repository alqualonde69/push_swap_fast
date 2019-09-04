/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chckstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:44:47 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:44:48 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		chckstack(char **av, int i)
{
	int		len;
	int		j;

	while (av[++i])
	{
		if ((len = ft_strlen(av[i])) > 11)
			return (1);
		else if (len == 11)
		{
			j = 1;
			if (OVERINT1)
				return (1);
		}
		else if (len == 10)
		{
			j = 0;
			if (OVERINT2)
				return (1);
		}
	}
	return (0);
}
