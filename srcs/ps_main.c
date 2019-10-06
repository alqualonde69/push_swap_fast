/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:05:05 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 21:49:11 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isstr(char ***s, int *f, int *ac)
{
	int		i;

	i = -1;
	f[2] = 1;
	while ((*s)[f[1] + 1][++i])
		if ((*s)[f[1] + 1][i] != ' ')
			break ;
	if (!(*s)[f[1] + 1][i])
		return (1);
	i = f[1];
	f[1] = -1;
	if (!(ft_strlen((*s)[i + 1])))
		return (2);
	if (!(*s = ft_strsplit((*s)[i + 1], ' ')))
		return (1);
	*ac = -1;
	while ((*s)[++(*ac)])
		;
	++(*ac);
	return (0);
}

static int	help(char **av)
{
	if (!(ft_strcmp(av[1], "-h")))
	{
		write(1, "usage: ./push_swap \"integer stack\"\n-f [file name]", 49);
		write(1, "\t-\twrite instructions to file\n", 30);
		return (1);
	}
	return (0);
}

static int	m(int *fd, char **av)
{
	if (!(ft_strcmp(av[1], "-f")))
	{
		if (av[2])
			if ((fd[0] = open(av[2], OPEN)) == -1)
				return (1);
		fd[1] = 2;
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		fd[4];
	t_ps	*a;
	t_ps	*b;
	t_rl	*rs;

	fd[0] = -1;
	fd[1] = 0;
	fd[2] = 0;
	if (ac < 2 || (ac > 1 && help(av)))
		return (0);
	if (m(fd, av))
		return (error());
	if (ac - 1 - fd[1] == 1 && (fd[3] = isstr(&av, fd, &ac)))
		return (fd[3] == 2 ? error() : 0);
	if (atst(&a, &av, fd))
		return (error());
	fd[1] == -1 ? fd[1] = 0 : 0;
	if (!(b = b_stack(ac - 1 - fd[1])))
		return (0);
	rs = push_swap(a, b, ac - 1 - fd[1]);
	print_list(rs, fd[0]);
	free_t_ps(&a, &b);
	fd[2] ? frav(av) : 0;
	return (0);
}
