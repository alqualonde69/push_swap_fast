/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:30:33 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:30:34 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cycle(int fd, unsigned short flag, t_ps **a, t_ps **b)
{
	char	buf;
	int		i;
	char	rl[5];

	ft_bzero(rl, 5);
	i = -1;
	while ((read(fd, &buf, 1)))
	{
		if (buf && buf != '\n' && i < 3)
			rl[++i] = buf;
		else if (buf && buf != '\n' && i == 3)
			;
		else if (buf == '\n')
		{
			if (is_rule(rl))
				return (1);
			rl[2] == '\0' ? applyrule(a, b, rl) : applyrule2(a, b, rl);
			if (flag & V)
				flag & C ? print(*a, *b, 1) : print(*a, *b, 0);
			ft_bzero(rl, 5);
			i = -1;
		}
	}
	return (0);
}
