/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:07:43 by shunt             #+#    #+#             */
/*   Updated: 2019/08/26 15:25:19 by shunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>

# define V			(1u << 0u)
# define C			(1u << 1u)
# define CH1		(av[i][0] != '-' && av[i][0] != '+')
# define CH2		(av[i][j] > '2')
# define CH2_1		av[i][j] == '2'
# define CH3		(CH2_1 && av[i][j + 1] > '1')
# define CH3_1		av[i][j + 1] == '1'
# define CH4		(CH2_1 && CH3_1 && av[i][j + 2] > '4')
# define CH4_1		av[i][j + 2] == '4'
# define CH5		(CH2_1 && CH3_1 && CH4_1 && av[i][j + 3] > '7')
# define CH5_1		av[i][j + 3] == '7'
# define CH6		(CH2_1 && CH3_1 && CH4_1 && CH5_1 && av[i][j + 4] > '4')
# define CH6_1		av[i][j + 4] == '4'
# define CH7_2		av[i][j + 5] > '8'
# define CH7		(CH2_1 && CH3_1 && CH4_1 && CH5_1 && CH6_1 && CH7_2)
# define CH7_1		av[i][j + 5] == '8'
# define CH8_2		av[i][j + 6] > '3'
# define CH8_3		CH2_1 && CH3_1
# define CH8		(CH8_3 && CH4_1 && CH5_1 && CH6_1 && CH7_1 && CH8_2)
# define CH8_1		av[i][j + 6] == '3'
# define CH9_2		CH2_1 && CH3_1 && CH4_1 && CH5_1 && CH6_1 && CH7_1 && CH8_1
# define CH9_3		av[i][j + 7] > '6'
# define CH9		(CH9_2 && CH9_3)
# define CH9_1		av[i][j + 7] == '6'
# define CH10		(CH9_2 && CH9_1 && av[i][j + 8] > '4')
# define CH10_1		av[i][j + 8] == '4'
# define CH11_2		av[i][j + 9] > '8'
# define CH11		(av[i][0] == '-' && CH9_2 && CH9_1 && CH10_1 && CH11_2)
# define CH12_2		av[i][j + 9] > '7'
# define CH12		(av[i][0] == '+' && CH9_2 && CH9_1 && CH10_1 && CH12_2)
# define CH12_3		CH9_2 && CH9_1 && CH10_1 && CH12_2
# define OV1		CH2 || CH3 || CH4 || CH5 || CH6 || CH7 || CH8 || CH9 || CH10
# define OVERINT1	CH1 || OV1 || CH11 || CH12
# define OVERINT2	OV1 || CH12_3
# define OPEN		O_WRONLY | O_TRUNC | O_CREAT, S_IWRITE | S_IREAD

typedef struct	s_ps
{
	int			n;
	char		c;
	struct s_ps	*nxt;
	struct s_ps	*prv;
}				t_ps;

typedef struct	s_rl
{
	char		*s;
	struct s_rl	*nxt;
	struct s_rl	*prv;
}				t_rl;

void			add_t_rl(t_rl **rules, char *s);
void			app_opt1(t_ps **a, t_ps **b, t_rl **rules, int *n);
void			app_opt2(t_ps **a, t_ps **b, t_rl **rules, int *n);
void			app_opt3(t_ps **a, t_ps **b, t_rl **rules, int *n);
void			app_opt4(t_ps **a, t_ps **b, t_rl **rules, int *n);
void			applyrule(t_ps **a, t_ps **b, char *rule);
void			applyrule2(t_ps **a, t_ps **b, char *rule);
t_ps			*atoi_stack(char **av, int f);
int				atst(t_ps **a, char ***av, int *fd);
t_ps			*b_stack(int i);
int				ch_fd(char **av, int ac, unsigned short *ff);
int				ch_flags(char **av, int ac, unsigned short *f,
		unsigned short *ff);
int				chckstack(char	**av, int i);
int				cycle(int fd, unsigned short flag, t_ps **a, t_ps **b);
int				error(void);
void			frav(char **av);
int				freetps(t_ps *a);
void			free_t_ps(t_ps **a, t_ps **b);
void			hd(t_ps **head, char **av, int *f);
int				isdup(t_ps *a);
int				is_mn_ra(t_ps *a, int *t);
int				is_nu(char **av, int i);
int				is_rule(char *rule);
int				issort(t_ps *a);
int				issort2(t_ps *a);
int				last_a(t_ps *a);
void			m_a(t_ps *a, int *mx, int *mn);
void			opt1(t_ps *a, t_ps *b, int *t);
void			opt2(t_ps *a, t_ps *b, int *t);
void			opt3(t_ps *a, t_ps *b, int *t);
void			opt4(t_ps *a, t_ps *b, int *t);
int				pc1(int ***t, int ***s, int i);
int				pc2(int ***t, int ***s, t_ps *a, int sz);
void			print(t_ps *a, t_ps *b, int f);
void			print_list(t_rl *rs, int fd);
void			push(t_ps **dst, t_ps **src);
t_rl			*push_swap(t_ps *a, t_ps *b, int sz);
void			rotate(t_ps **stack);
void			rrotate(t_ps **stack);
int				sequence(t_ps *a, int **s, int *k);
void			swap(t_ps **stack);

#endif
