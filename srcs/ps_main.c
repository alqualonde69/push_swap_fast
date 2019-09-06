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

void		print_list(t_rl *rs, int fd)
{
	t_rl	*tmp;

	tmp = rs;
	while (rs)
	{
		fd != -1 ? write(fd, rs->s, ft_strlen(rs->s)) :
			write(1, rs->s, ft_strlen(rs->s));
		fd != -1 ? write(fd, "\n", 1) : write(1, "\n", 1);
		rs = rs->nxt;
	}
	rs = tmp;
	while (rs)
	{
		tmp = rs;
		rs = rs->nxt;
		free(tmp);
	}
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

int			main(int ac, char **av)
{
	int		fd[2];
	t_ps	*a;
	t_ps	*b;
	t_rl	*rs;

	fd[0] = -1;
	fd[1] = 0;
	if (ac < 2 || (ac > 1 && help(av)))
		return (0);
	if (!(ft_strcmp(av[1], "-f")))
	{
		if (av[2])
			if ((fd[0] = open(av[2], OPEN)) == -1)
				return (error());
		fd[1] = 2;
	}
	if (!(a = atoi_stack(av, fd[1])))
		return (error());
	if (!(b = b_stack(ac - 1)))
		return (0);
	rs = push_swap(a, b, ac - 1 - fd[1]);
	print_list(rs, fd[0]);
	free_t_ps(&a, &b);
	return (0);
}
