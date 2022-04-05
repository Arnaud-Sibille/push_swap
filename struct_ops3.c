/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ops3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:16:01 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 09:24:21 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sw_cost(t_lst *ls, int mina, int maxa)
{
	if (ls)
	{
		if (ls->next == ls || ls->next == ls->prev)
			ls->sw_cost = 0;
		else
		{
			if ((ls->pos == mina && ls->next->pos == maxa)
				|| (ls->pos == 1 + ls->next->pos))
				ls->sw_cost = 1 + ft_min(ls->dist_rot, ls->dist_rev);
			else
				ls->sw_cost = 0;
		}
	}
}
