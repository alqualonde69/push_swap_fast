/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:26:51 by shunt             #+#    #+#             */
/*   Updated: 2019/09/09 19:46:46 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	frav(char **av)
{
	int		i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

static int	isstr(char ***s, unsigned short *f, int *ac)
{
	f[2] = 1;
	if (!(*s = ft_strsplit((*s)[f[1] + 1], ' ')))
		return (1);
	*ac = -1;
	while ((*s)[++(*ac)])
		;
	++(*ac);
	f[1] = 0;
	return (0);
}

static int	m(int *fd, unsigned short *flag, int *ac, char ***av)
{
	*fd = 0;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	if (*ac < 2)
		return (1);
	if ((*fd = ch_fd(*av, *ac, &flag[1])) == -1)
	{
		error();
		return (1);
	}
	if (ch_flags(*av, *ac, &flag[0], &flag[1]))
		return (1);
	if (*ac - 1 - flag[1] == 1 && isstr(av, flag, ac))
		return (1);
	return (0);
}

int			main(int ac, char **av)
{
	int				fd;
	t_ps			*a;
	t_ps			*b;
	unsigned short	flag[3];

	if (m(&fd, flag, &ac, &av))
		return (0);
	a = flag[2] ? atoi_stack(av, -1) : atoi_stack(av, flag[1]);
	if (!a)
		return (error());
	if (!(b = b_stack(ac - 1 - flag[1])))
		return (0);
	if (cycle(fd, flag[0], &a, &b))
	{
		free_t_ps(&a, &b);
		flag[2] ? frav(av) : 0;
		return (error());
	}
	!(b->c) && issort(a) ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	free_t_ps(&a, &b);
	flag[2] ? frav(av) : 0;
	return (0);
}
