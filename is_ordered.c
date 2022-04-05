/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:20 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 10:49:40 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ordered(t_lst *st, int min, int max)
{
	t_lst	*first;

	first = st;
	if (!first)
		return (1);
	if ((st->pos > st->next->pos)
		&& !((st->pos == max) && (st->next->pos == min)))
		return (0);
	st = st->next;
	while (st != first)
	{
		if ((st->pos > st->next->pos)
			&& !((st->pos == max) && (st->next->pos == min)))
			return (0);
		st = st->next;
	}
	return (1);
}
