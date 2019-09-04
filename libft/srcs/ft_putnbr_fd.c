/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:38:18 by shunt             #+#    #+#             */
/*   Updated: 2019/04/09 16:18:01 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd != -1 && n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (fd != -1 && n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (fd != -1 && n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	if (fd != -1 && n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}