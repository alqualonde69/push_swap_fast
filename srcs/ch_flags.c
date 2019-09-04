/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 19:29:56 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 19:30:00 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ch_flags(char **av, int ac, unsigned short *f, unsigned short *ff)
{
	if (!(ft_strcmp(av[1], "-v")) || (ac > 2 && !(ft_strcmp(av[2], "-v"))) ||
		(ac > 3 && !(ft_strcmp(av[3], "-v"))))
	{
		*f |= V;
		++(*ff);
	}
	if (!(ft_strcmp(av[1], "-c")) || (ac > 2 && !(ft_strcmp(av[2], "-c"))) ||
		(ac > 3 && !(ft_strcmp(av[3], "-c"))))
	{
		*f |= C;
		++(*ff);
	}
	if (!(ft_strcmp(av[1], "-h")))
	{
		write(1, "usage:\t./checker \"integer stack\"\n-f [file name]\t-", 49);
		write(1, "\tread instructions from file\n-v\t\t-\tvisualizer\n-c", 48);
		write(1, "\t\t-\tcolorful visualizer (works only with -v)\n", 45);
		return (1);
	}
	return (0);
}
