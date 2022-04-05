/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:10 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 12:20:41 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_algo(t_lst *ls, t_lst *b, int min, int max)
{
	t_lst	*first;

	first = b;
	if ((b->prev->pos > ls->pos || (b->prev->pos == min && ls->pos == max))
		&& (ls->pos > b->pos || (ls->pos == min && b->pos == max)))
	{
		ls->pu_pl = b;
		return ;
	}
	b = b->next;
	while (b != first)
	{
		if ((b->prev->pos > ls->pos || (b->prev->pos == min && ls->pos == max))
			&& (ls->pos > b->pos || (ls->pos == min && b->pos == max)))
		{
			ls->pu_pl = b;
			return ;
		}
		b = b->next;
	}
	ls->pu_pl = NULL;
}

void	ft_pu_pl(t_lst *ls, t_lst *stb, int minb, int maxb)
{
	if (ls)
	{
		if (stb)
		{
			if (ls->pos < minb)
				minb = ls->pos;
			if (ls->pos > maxb)
				maxb = ls->pos;
			if (stb == stb->next)
				ls->pu_pl = stb;
			else
				ft_algo(ls, stb, minb, maxb);
		}
		else
			ls->pu_pl = NULL;
	}
}

static void	ft_pu_cost_case1(t_lst *ls)
{
	ls->pu_cost = 1 + ft_max(ls->dist_rot, ls->pu_pl->dist_rot);
	ls->pu_way = 0;
	if (1 + ls->dist_rot + ls->pu_pl->dist_rev < ls->pu_cost)
	{
		ls->pu_cost = 1 + ls->dist_rot + ls->pu_pl->dist_rev;
		ls->pu_way = 1;
	}
	if (1 + ls->dist_rev + ls->pu_pl->dist_rot < ls->pu_cost)
	{
		ls->pu_cost = 1 + ls->dist_rev + ls->pu_pl->dist_rot;
		ls->pu_way = 2;
	}
	if (1 + ft_max(ls->dist_rev, ls->pu_pl->dist_rev) < ls->pu_cost)
	{
		ls->pu_cost = 1 + ft_max(ls->dist_rev, ls->pu_pl->dist_rev);
		ls->pu_way = 3;
	}
}

void	ft_pu_cost(t_lst *ls)
{
	if (ls)
	{
		if (ls->pu_pl)
			ft_pu_cost_case1(ls);
		else
		{
			if (ls->dist_rev < ls->dist_rot)
			{
				ls->pu_cost = 1 + ls->dist_rev;
				ls->pu_way = 3;
			}
			else
			{
				ls->pu_cost = 1 + ls->dist_rot;
				ls->pu_way = 0;
			}
		}
	}
	if (ls->mispl == 0)
		ls->pu_cost = 0;
}
