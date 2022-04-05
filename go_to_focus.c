/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_focus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:38:08 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 10:39:03 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*ft_find(t_lst *st, int pos)
{
	t_lst	*first;

	first = st;
	if (st)
	{
		if (st->pos == pos)
			return (st);
		st = st->next;
		while (st != first)
		{
			if (st->pos == pos)
				return (st);
			st = st->next;
		}
	}
	return (NULL);
}

void	ft_go_to_focus(t_data *ps)
{
	t_lst	*min;

	if (ps->sta)
	{
		min = ft_find(ps->sta, ps->mina);
		if (min)
		{
			if (min->dist_rev < min->dist_rot)
			{
				while (ps->sta->pos != ps->mina)
					ft_rev0(ps, 'a');
			}
			else
			{
				while (ps->sta->pos != ps->mina)
					ft_rot0(ps, 'a');
			}
		}
	}
}
