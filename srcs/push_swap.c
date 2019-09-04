/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 14:47:43 by shunt             #+#    #+#             */
/*   Updated: 2019/08/23 14:47:45 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	p1(t_rl **rules, t_ps **a, t_ps **b, int **s)
//{
//	int		i;
//	int 	j;
//
//	if (s[0][1] == 2)
//	{
//		add_t_rl(rules, "sa");
//		return (1);
//	}
//	if (s[0][1] > 3)
//	{
//		i = 0;
//		j = 0;
//		while (i < s[0][1] - 3 && !(issort2(*a)))
//		{
//			if (j < s[0][0] && (*a)->n == s[1][j])
//			{
//				applyrule(a, b, "ra");
//				add_t_rl(rules, "ra");
//				++j;
//			}
//			else
//			{
//				applyrule(a, b, "pb");
//				add_t_rl(rules, "pb");
//				++i;
//			}
//		}
//	}
//	if (!(issort2(*a)))
//	{
//		applyrule(a, b, "sa");
//		add_t_rl(rules, "sa");
//	}
//	return (0);
//}

static int	p1(t_rl **rules, t_ps **a, t_ps **b, int **s)
{
	int		i;
	int 	j;

	if (s[1][0] == 2)
	{
		add_t_rl(rules, "sa");
		return (1);
	}
	if (s[1][0] > 3)
	{
		i = 0;
		j = 0;
		while (i < s[1][0] - 3 && !(issort2(*a)))
		{
			if (j < s[1][1] && (*a)->n == s[0][j])
			{
				applyrule(a, b, "ra");
				add_t_rl(rules, "ra");
				++j;
			}
			else
			{
				applyrule(a, b, "pb");
				add_t_rl(rules, "pb");
				++i;
			}
		}
	}
	if (!(issort2(*a)))
	{
		applyrule(a, b, "sa");
		add_t_rl(rules, "sa");
	}
	return (0);
}

static void	p2(t_ps **a, t_ps **b, int **t, t_rl **rules)
{
	opt1(*a, *b, t[0]);
	opt2(*a, *b, t[1]);
	opt3(*a, *b, t[2]);
	opt4(*a, *b, t[3]);
	if (t[0][0] <= t[1][0] && t[0][0] <= t[2][0] && t[0][0] <= t[3][0])
		app_opt1(a, b, rules, t[0]);
	else if (t[1][0] <= t[0][0] && t[1][0] <= t[2][0] && t[1][0] <= t[3][0])
		app_opt2(a, b, rules, t[1]);
	else if (t[2][0] <= t[1][0] && t[2][0] <= t[0][0] && t[2][0] <= t[3][0])
		app_opt3(a, b, rules, t[2]);
	else if (t[3][0] <= t[1][0] && t[3][0] <= t[2][0] && t[3][0] <= t[0][0])
		app_opt4(a, b, rules, t[3]);
}

static void	p3(t_rl **rules, t_ps **a, t_ps **b)
{
	int		i;

	if (is_mn_ra(*a, &i))
	{
		while ((*a)->n != i)
		{
			applyrule(a, b, "ra");
			add_t_rl(rules, "ra");
		}
	}
	else
	{
		while ((*a)->n != i)
		{
			applyrule2(a, b, "rra");
			add_t_rl(rules, "rra");
		}
	}
}

//t_rl		*push_swap(t_ps *a, t_ps *b, int sz)
//{
//	t_rl	*rules;
//	int		**t;
//	int 	**s;
//	int		i;
//	int 	k;
//
//	k = 0;
//	if (!(s = (int **)malloc(sizeof(int *) * 2)))
//		return (NULL);
//	if (!(s[0] = (int *)malloc(sizeof(int) * sz + 1)))
//		return (NULL);
//	if (!(s[1] = (int *)malloc(sizeof(int) * sz + 1)))
//		return (NULL);
//	if (!(t = (int **)malloc(sizeof(int *) * 4)))
//		return (NULL);
//	i = -1;
//	while (++i < 4)
//		if (!(t[i] = (int *)malloc(sizeof(int) * 3)))
//			return (NULL);
//	rules = NULL;
//	sz > 3 ? sequence2(a, s, -1, &k) : 0;
//	s[0][0] = k;
//	s[0][1] = sz;
//	if (issort(a) || sz == 1)
//		return (NULL);
//	if (p1(&rules, &a, &b, s))
//		return (rules);
//	while (b->c)
//		p2(&a, &b, t, &rules);
//	p3(&rules, &a, &b);
//	i = -1;
//	while (++i < 4)
//		free(t[i]);
//	free(t);
//	return (rules);
//}

t_rl		*push_swap(t_ps *a, t_ps *b, int sz)
{
	t_rl	*rules;
	int		**t;
	int 	**s;
	int		i;

	if (!(t = (int **)malloc(sizeof(int *) * 4)))
		return (NULL);
	if (!(s = (int **)malloc(sizeof(int *) * 2)))
		return (NULL);
	if (!(s[1] = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	s[1][0] = sz;
	i = -1;
	while (++i < 4)
		if (!(t[i] = (int *)malloc(sizeof(int) * 3)))
			return (NULL);
	rules = NULL;
	if (sz > 3)
		if (sequence3(a, &s[0], &s[1][1]))
			return (NULL);
	if (issort(a) || sz == 1)
		return (NULL);
	if (p1(&rules, &a, &b, s))
		return (rules);
	while (b->c)
		p2(&a, &b, t, &rules);
	p3(&rules, &a, &b);
	i = -1;
	while (++i < 4)
		free(t[i]);
	free(t);
	return (rules);
}
