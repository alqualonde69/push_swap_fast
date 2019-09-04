/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:26:51 by shunt             #+#    #+#             */
/*   Updated: 2019/08/10 13:27:02 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	int				fd;
	t_ps			*a;
	t_ps			*b;
	unsigned short	flag[2];

	fd = 0;
	flag[0] = 0;
	flag[1] = 0;
	if (ac < 2)
		return (0);
	if ((fd = ch_fd(av, ac, &flag[1])) == -1)
		return (error());
	if (ch_flags(av, ac, &flag[0], &flag[1]))
		return (0);
	if (!(a = atoi_stack(av, flag[1])))
		return (error());
	if (!(b = b_stack(ac - 1 - flag[1])))
		return (0);
	if (cycle(fd, flag[0], &a, &b))
		return (error());
	!(b->c) && issort(a) ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	free_t_ps(&a, &b);
	return (0);
}
