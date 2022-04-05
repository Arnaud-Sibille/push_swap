/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:04 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 07:40:31 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_res(t_data *ps)
{
	while (!ft_is_ordered(ps->sta, ps->mina, ps->maxa) || ps->stb)
	{
		ft_fill(ps);
		if (ps->sta->sw_cost == 1)
			ft_swap0(ps, 'a');
		else if (ps->sta->ad_cost == 1)
			ft_push0(ps, 'a');
		else if (ps->sta->pu_cost == 1)
			ft_push0(ps, 'b');
		else
			ft_go_to_best(ps);
	}
	ft_fill(ps);
	ft_go_to_focus(ps);
}
