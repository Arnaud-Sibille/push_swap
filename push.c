/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:04:10 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 10:04:26 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_pusha0(t_data *ps)
{
	t_lst	*sta;
	t_lst	*stb;

	sta = ps->sta;
	stb = ps->stb;
	if (ps->stb)
	{
		--ps->nbelb;
		++ps->nbela;
		ft_push(&stb, &sta);
		ps->sta = sta;
		ps->stb = stb;
		if (ps->sta)
		{
			ps->sta->next->focus = 0;
			ps->sta->focus = 1;
		}
		if (ps->stb)
			ps->stb->focus = 1;
	}
	write(1, "pa\n", 3);
}

static void	ft_pushb0(t_data *ps)
{
	t_lst	*sta;
	t_lst	*stb;

	sta = ps->sta;
	stb = ps->stb;
	if (ps->sta)
	{
		--ps->nbela;
		++ps->nbelb;
		ft_push(&sta, &stb);
		ps->sta = sta;
		ps->stb = stb;
		if (ps->stb)
		{
			ps->stb->next->focus = 0;
			ps->stb->focus = 1;
		}
		if (ps->sta)
			ps->sta->focus = 1;
	}
	write(1, "pb\n", 3);
}

void	ft_push0(t_data *ps, char st)
{
	if (st == 'a')
		ft_pusha0(ps);
	else if (st == 'b')
		ft_pushb0(ps);
}
