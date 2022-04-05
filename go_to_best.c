/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:45:14 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 11:22:14 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min2(int a, int b)
{
	if (a > 0)
	{
		if (b == 0)
			return (a);
		else
		{
			if (b > a)
				return (a);
			else
				return (b);
		}
	}
	else if (b > 0)
		return (b);
	return (0);
}

static t_lst	*find_best(t_lst *st)
{
	t_lst	*best;
	int		cost;

	best = st;
	if (st)
	{
		cost = min2(min2(st->pu_cost, st->ad_cost), st->sw_cost);
		st = st->next;
		while (st->focus != 1)
		{
			if ((min2(min2(st->pu_cost, st->ad_cost), st->sw_cost) > 0)
				&& (!cost || min2(min2(st->pu_cost, st->ad_cost), st->sw_cost)
					< cost))
			{
				cost = min2(min2(st->pu_cost, st->ad_cost), st->sw_cost);
				best = st;
			}
			st = st->next;
		}
	}
	return (best);
}

void	ft_go_to_best(t_data *ps)
{
	t_lst	*best;
	int		cost;

	if (ps->sta)
	{
		best = find_best(ps->sta);
		cost = min2(min2(best->pu_cost, best->ad_cost), best->sw_cost);
		if (cost == best->sw_cost)
			ft_go_to_best_sw(ps, best);
		else if (cost == best->ad_cost)
			ft_go_to_best_ad(ps, best);
		else if (cost == best->pu_cost)
			ft_go_to_best_pu(ps, best);
	}
}
