/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:51 by asibille          #+#    #+#             */
/*   Updated: 2022/03/24 19:37:52 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_dist(t_lst *st)
{
	int	count;

	count = 0;
	if (st)
	{
		st->dist_rot = count;
		st = st->next;
		++count;
		while (st->focus != 1)
		{
			st->dist_rot = count;
			st = st->next;
			++count;
		}
	}
}

void	ft_rev_dist(t_lst *st)
{
	int	count;

	count = 0;
	if (st)
	{
		st->dist_rev = count;
		st = st->prev;
		++count;
		while (st->focus != 1)
		{
			st->dist_rev = count;
			st = st->prev;
			++count;
		}
	}
}
