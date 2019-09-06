/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:44:30 by shunt             #+#    #+#             */
/*   Updated: 2019/09/06 22:44:31 by shunt            ###   ########.fr       */
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
