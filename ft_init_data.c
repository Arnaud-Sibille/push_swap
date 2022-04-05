/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:34 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 08:49:23 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pos(t_lst *ls)
{
	t_lst	*first;
	int		val;

	first = ls;
	if (ls)
	{
		val = ls->val;
		ls = ls->next;
		while (ls != first)
		{
			if (ls->val == val)
				ft_exit(first, NULL);
			else if (ls->val < val)
				++first->pos;
			ls = ls->next;
		}
	}
}

void	ft_init_data(t_data *ps, char **s, int size)
{
	int	i;

	i = 1;
	ps->sta = NULL;
	while (i < size)
	{
		ps->sta = ft_input_to_stack(s[i], ps->sta);
		++i;
	}
	ps->stb = NULL;
	ft_apply_lst(ps->sta, ft_pos);
	ps->nbela = ft_nbel(ps->sta);
	ps->nbelb = 0;
	ps->mina = 0;
	ps->minb = 0;
	ps->maxa = ps->nbela - 1;
	ps->maxb = 0;
}
