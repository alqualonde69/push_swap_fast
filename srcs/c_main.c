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

static int	isstr(char ***s, unsigned short *f, int *ac)
{
	int		i;

	i = -1;
	f[2] = 1;
	while ((*s)[f[1] + 1][++i])
		if ((*s)[f[1] + 1][i] != ' ')
			break ;
	if (!(*s)[f[1] + 1][i])
		return (1);
	if (!(ft_strlen((*s)[f[1] + 1])))
		return (2);
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
	if (*ac - 1 - flag[1] == 1 && (flag[3] = isstr(av, flag, ac)))
		return (flag[3] == 2 ? 2 : 1);
	return (0);
}

static int	ats(t_ps **a, char ***av, unsigned short *flag)
{
	if (!(*a))
	{
		flag[2] ? frav(*av) : 0;
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int				fd;
	t_ps			*a;
	t_ps			*b;
	char			buf;
	unsigned short	flag[4];

	if ((flag[3] = m(&fd, flag, &ac, &av)))
		return (flag[3] == 2 ? error() : 0);
	a = flag[2] ? atoi_stack(av, -1) : atoi_stack(av, flag[1]);
	if (ats(&a, &av, flag))
		return (error());
	if (!(b = b_stack(ac - 1 - flag[1])))
		return (0);
	if (read(fd, &buf, 0) == -1 || cycle(fd, flag[0], &a, &b))
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
