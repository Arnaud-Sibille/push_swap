/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_best_pu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:41 by asibille          #+#    #+#             */
/*   Updated: 2022/03/24 19:41:57 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr_way_pu(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rot;
	if (best->pu_pl)
		countb = best->pu_pl->dist_rot;
	else
		countb = 0;
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

static void	ft_ra_rrb_way_pu(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rot;
	if (best->pu_pl)
		countb = best->pu_pl->dist_rev;
	else
		countb = 0;
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

static void	ft_rra_rb_way_pu(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rev;
	if (best->pu_pl)
		countb = best->pu_pl->dist_rot;
	else
		countb = 0;
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

static void	ft_rrr_way_pu(t_data *ps, t_lst *best)
{
	int	counta;
	int	countb;

	counta = best->dist_rev;
	if (best->pu_pl)
		countb = best->pu_pl->dist_rev;
	else
		countb = 0;
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

void	ft_go_to_best_pu(t_data *ps, t_lst *best)
{
	if (ps->sta)
	{
		if (best->pu_way == 0)
			ft_rr_way_pu(ps, best);
		else if (best->pu_way == 1)
			ft_ra_rrb_way_pu(ps, best);
		else if (best->pu_way == 2)
			ft_rra_rb_way_pu(ps, best);
		else if (best->pu_way == 3)
			ft_rrr_way_pu(ps, best);
	}
}
