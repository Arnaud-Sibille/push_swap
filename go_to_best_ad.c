/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_best_ad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:38 by asibille          #+#    #+#             */
/*   Updated: 2022/03/24 19:40:05 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr_way_ad(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rot;
	countb = best->ad_pl->dist_rot;
	while (counta > 0 && countb > 0)
	{
		ft_super_rot0(ps);
		--counta;
		--countb;
	}
	while (counta > 0)
	{
		ft_rot0(ps, 'a');
		--counta;
	}
	while (countb > 0)
	{
		ft_rot0(ps, 'b');
		--countb;
	}
}

static void	ft_ra_rrb_way_ad(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rot;
	countb = best->ad_pl->dist_rev;
	while (counta > 0)
	{
		ft_rot0(ps, 'a');
		--counta;
	}
	while (countb > 0)
	{
		ft_rev0(ps, 'b');
		--countb;
	}
}

static void	ft_rra_rb_way_ad(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rev;
	countb = best->ad_pl->dist_rot;
	while (counta > 0)
	{
		ft_rev0(ps, 'a');
		--counta;
	}
	while (countb > 0)
	{
		ft_rot0(ps, 'b');
		--countb;
	}
}

static void	ft_rrr_way_ad(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rev;
	countb = best->ad_pl->dist_rev;
	while (counta > 0 && countb > 0)
	{
		ft_super_rev0(ps);
		--counta;
		--countb;
	}
	while (counta > 0)
	{
		ft_rev0(ps, 'a');
		--counta;
	}
	while (countb > 0)
	{
		ft_rev0(ps, 'b');
		--countb;
	}
}

void	ft_go_to_best_ad(t_data *ps, t_lst *best)
{
	if (ps->sta)
	{
		if (best->ad_way == 0)
			ft_rr_way_ad(ps, best);
		else if (best->ad_way == 1)
			ft_ra_rrb_way_ad(ps, best);
		else if (best->ad_way == 2)
			ft_rra_rb_way_ad(ps, best);
		else if (best->ad_way == 3)
			ft_rrr_way_ad(ps, best);
	}
}
