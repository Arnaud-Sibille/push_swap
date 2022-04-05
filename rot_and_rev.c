/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_and_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:05:58 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 10:06:39 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot0(t_data *ps, char st)
{
	if (st == 'a')
	{
		ps->sta = ft_rot(ps->sta);
		if (ps->sta)
		{
			ps->sta->prev->focus = 0;
			ps->sta->focus = 1;
		}
		write(1, "ra\n", 3);
	}
	else if (st == 'b')
	{
		ps->stb = ft_rot(ps->stb);
		if (ps->stb)
		{
			ps->stb->prev->focus = 0;
			ps->stb->focus = 1;
		}
		write(1, "rb\n", 3);
	}
}

void	ft_rev0(t_data *ps, char st)
{
	if (st == 'a')
	{
		ps->sta = ft_rev(ps->sta);
		if (ps->sta)
		{
			ps->sta->next->focus = 0;
			ps->sta->focus = 1;
		}
		write(1, "rra\n", 4);
	}
	else if (st == 'b')
	{
		ps->stb = ft_rev(ps->stb);
		if (ps->stb)
		{
			ps->stb->next->focus = 0;
			ps->stb->focus = 1;
		}
		write(1, "rrb\n", 4);
	}
}

void	ft_super_rot0(t_data *ps)
{
	ps->sta = ft_rot(ps->sta);
	ps->stb = ft_rot(ps->stb);
	if (ps->sta)
	{
		ps->sta->prev->focus = 0;
		ps->sta->focus = 1;
	}
	if (ps->stb)
	{
		ps->stb->prev->focus = 0;
		ps->stb->focus = 1;
	}
	write(1, "rr\n", 3);
}

void	ft_super_rev0(t_data *ps)
{
	ps->sta = ft_rev(ps->sta);
	ps->stb = ft_rev(ps->stb);
	if (ps->sta)
	{
		ps->sta->next->focus = 0;
		ps->sta->focus = 1;
	}
	if (ps->stb)
	{
		ps->stb->next->focus = 0;
		ps->stb->focus = 1;
	}
	write(1, "rrr\n", 4);
}
