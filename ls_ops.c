/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:48 by asibille          #+#    #+#             */
/*   Updated: 2022/03/24 19:43:29 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbel(t_lst *stack)
{
	int		count;
	t_lst	*st_cpy;

	count = 0;
	st_cpy = stack;
	if (stack)
	{
		++count;
		stack = stack->next;
		while (stack != st_cpy)
		{
			++count;
			stack = stack->next;
		}
	}
	return (count);
}

int	ft_find_min(t_lst *st)
{
	int		min;
	t_lst	*first;

	if (st)
	{
		first = st;
		min = st->pos;
		st = st->next;
		while (st != first)
		{
			if (st->pos < min)
				min = st->pos;
			st = st->next;
		}
		return (min);
	}
	else
		return (0);
}

int	ft_find_max(t_lst *st)
{
	int		max;
	t_lst	*first;

	if (st)
	{
		first = st;
		max = st->pos;
		st = st->next;
		while (st != first)
		{
			if (st->pos > max)
				max = st->pos;
			st = st->next;
		}
		return (max);
	}
	else
		return (0);
}
