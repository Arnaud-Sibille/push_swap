/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:13 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 11:53:43 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check(t_lst *ls, int pos)
{
	t_lst	*ls_cp;

	ls_cp = ls;
	ls_cp = ls_cp->prev;
	while (ls_cp->pos != 0)
	{
		if (ls_cp->pos > pos)
			ls->ad_pl = NULL;
		ls_cp = ls_cp->prev;
	}	
}

static void	ft_add(t_lst *ls, t_lst *stb, int *pos)
{
	ls->ad_pl = stb;
	*pos = stb->pos;
}

void	ft_ad_pl(t_lst *ls, t_lst *stb)
{
	t_lst	*first;
	int		pos;

	first = stb;
	if (ls)
	{
		ls->ad_pl = NULL;
		pos = 0;
		if (stb)
		{
			if ((stb->pos < ls->pos) && (stb->pos > pos))
				ft_add(ls, stb, &pos);
			stb = stb->next;
			while (stb != first)
			{
				if ((stb->pos < ls->pos) && (stb->pos > pos))
					ft_add(ls, stb, &pos);
				stb = stb->next;
			}
			ft_check(ls, pos);
		}
	}
}

static void	ft_ad_cost_case1(t_lst *ls)
{
	ls->ad_cost = 1 + ft_max(ls->dist_rot, ls->ad_pl->dist_rot);
	ls->ad_way = 0;
	if (1 + ls->dist_rot + ls->ad_pl->dist_rev < ls->ad_cost)
	{
		ls->ad_cost = 1 + ls->dist_rot + ls->ad_pl->dist_rev;
		ls->ad_way = 1;
	}
	if (1 + ls->dist_rev + ls->ad_pl->dist_rot < ls->ad_cost)
	{
		ls->ad_cost = 1 + ls->dist_rev + ls->ad_pl->dist_rot;
		ls->ad_way = 2;
	}
	if (1 + ft_max(ls->dist_rev, ls->ad_pl->dist_rev) < ls->ad_cost)
	{
		ls->ad_cost = 1 + ft_max(ls->dist_rev, ls->ad_pl->dist_rev);
		ls->ad_way = 3;
	}
}

void	ft_ad_cost(t_lst *ls)
{
	if (ls)
	{
		if (ls->ad_pl)
			ft_ad_cost_case1(ls);
		else
			ls->ad_cost = 0;
	}
	if (ls->mispl)
		ls->ad_cost = 0;
}
