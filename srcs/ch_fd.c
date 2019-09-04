/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:29:26 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:29:28 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ch_fd(char **av, int ac, unsigned short *ff)
{
	int		fd;

	fd = 0;
	if (!(ft_strcmp(av[1], "-f")) || (ac > 2 && !(ft_strcmp(av[2], "-f"))) ||
		(ac > 3 && !(ft_strcmp(av[3], "-f"))))
	{
		if (!(ft_strcmp(av[1], "-f")))
			fd = 2;
		else if (ac > 2 && !(ft_strcmp(av[2], "-f")))
			fd = 3;
		else if (ac > 3 && !(ft_strcmp(av[3], "-f")))
			fd = 4;
		if ((fd = open(av[fd], O_RDONLY)) == -1)
			return (-1);
		*ff += 2;
	}
	return (fd);
}
