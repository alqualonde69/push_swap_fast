/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:26:38 by shunt             #+#    #+#             */
/*   Updated: 2019/04/15 17:40:34 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str(char *s, char c)
{
	int i;
	int n;
	int k;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		k = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			k = 1;
		}
		k ? n++ : n;
	}
	return (n);
}

static char	**ft_f(char *s, char **d, char c)
{
	int i;
	int n;
	int j;
	int k;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		k = 0;
		while (s[i] && s[i] != c)
		{
			d[n][j] = s[i];
			j++;
			i++;
			k = 1;
		}
		if (k)
			d[n][j] = '\0';
		n++;
	}
	return (d);
}

static char	**ft_free(char **d, int i)
{
	while (i-- >= 0)
		free(d[i]);
	free(d);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**d;
	int		n;
	int		k;

	if (!s)
		return (NULL);
	n = ft_str((char *)s, c);
	if (!(d = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	d[n] = NULL;
	i = -1;
	j = 0;
	while (++i < n)
	{
		while (s[j] && s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		if (!(d[i] = (char *)malloc(sizeof(char) * (j - k + 1))))
			return (ft_free(d, i - 1));
	}
	return (ft_f((char *)s, d, c));
}
