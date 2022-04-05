/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_best_sw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:39:49 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 11:24:07 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_go_to_best_sw(t_data	*ps, t_lst *best)
{
	int	count;

	if (ps->sta)
	{
		if (best->dist_rev < best->dist_rot)
		{
			count = best->dist_rev;
			while (count > 0)
			{
				ft_rev0(ps, 'a');
				--count;
			}
		}
		else
		{
			count = best->dist_rot;
			while (count > 0)
			{
				ft_rot0(ps, 'a');
				--count;
			}
		}
	}
}
