/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:34:23 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 08:48:32 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
	int				pos;
	int				val;
	int				focus;
	int				dist_rev;
	int				dist_rot;
	int				sw_cost;
	int				pu_cost;
	int				ad_cost;
	int				pu_way;
	struct s_lst	*pu_pl;
	int				mispl;
	int				ad_way;
	struct s_lst	*ad_pl;
}			t_lst;

typedef struct s_data
{
	t_lst	*sta;
	t_lst	*stb;
	int		nbela;
	int		nbelb;
	int		mina;
	int		maxa;
	int		minb;
	int		maxb;
}				t_data;

void	ft_apply_lst(t_lst *stack, void (*f)(t_lst *));
void	ft_apply_lst2(t_lst *stack, int min, void (*f)(t_lst *, int));
void	ft_apply_lst2bis(t_lst *stack, t_lst *stb, void (*f)(t_lst *, t_lst *));
void	ft_apls3(t_lst *stack, int min, int max, void (*f)(t_lst *, int, int));
void	ft_apply_lst4(t_data *ps, void (*f)(t_lst *, t_lst *, int, int));
void	ft_fill(t_data *ps);
void	ft_init_data(t_data *ps, char **s, int size);
void	ft_go_to_best_ad(t_data *ps, t_lst *best);
void	ft_go_to_best_pu(t_data *ps, t_lst *best);
void	ft_go_to_best_sw(t_data	*ps, t_lst *best);
void	ft_go_to_best(t_data *ps);
void	ft_go_to_focus(t_data *ps);
t_lst	*ft_input_to_stack(char *s, t_lst *stack);
int		ft_is_ordered(t_lst *st, int min, int max);
int		ft_nbel(t_lst *stack);
int		ft_find_min(t_lst *st);
int		ft_find_max(t_lst *st);
void	ft_rot_dist(t_lst *st);
void	ft_rev_dist(t_lst *st);
void	ft_mispl(t_lst *ls, int min);
void	ft_push0(t_data *ps, char st);
void	ft_res(t_data *ps);
void	ft_rot0(t_data *ps, char st);
void	ft_rev0(t_data *ps, char st);
void	ft_super_rot0(t_data *ps);
void	ft_super_rev0(t_data *ps);
t_lst	*ft_swap(t_lst *ls1);
void	ft_push(t_lst **lsfr, t_lst **lsto);
t_lst	*ft_rot(t_lst *ls);
t_lst	*ft_rev(t_lst *ls);
void	ft_pu_pl(t_lst *ls, t_lst *stb, int minb, int maxb);
void	ft_pu_cost(t_lst *ls);
void	ft_ad_pl(t_lst *ls, t_lst *stb);
void	ft_ad_cost(t_lst *ls);
void	ft_sw_cost(t_lst *ls, int mina, int maxa);
void	ft_swap0(t_data *ps, char st);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_free(t_lst *st);
void	ft_exit(t_lst *sta, t_lst *stb);
#endif
