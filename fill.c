/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:36:40 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 09:38:18 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_is_swap(t_lst *ls, int n)
{
	if (n >= 20)
	{
		if (ls)
			ls->sw_cost = 0;
	}
}

void	ft_fill(t_data *ps)
{
	ps->mina = ft_find_min(ps->sta);
	ps->maxa = ft_find_max(ps->sta);
	ps->minb = ft_find_min(ps->stb);
	ps->maxb = ft_find_max(ps->stb);
	ft_rot_dist(ps->sta);
	ft_rev_dist(ps->sta);
	ft_rot_dist(ps->stb);
	ft_rev_dist(ps->stb);
	ft_apls3(ps->sta, ps->mina, ps->maxa, ft_sw_cost);
	ft_apply_lst2(ps->sta, ps->nbela, ft_is_swap);
	ft_apply_lst2(ps->sta, ps->mina, ft_mispl);
	ft_apply_lst4(ps, ft_pu_pl);
	ft_apply_lst(ps->sta, ft_pu_cost);
	ft_apply_lst2bis(ps->sta, ps->stb, ft_ad_pl);
	ft_apply_lst(ps->sta, ft_ad_cost);
}
