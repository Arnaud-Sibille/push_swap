/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:02:12 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 10:03:08 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap0(t_data *ps, char st)
{
	if (st == 'a')
	{
		if (ps->sta)
		{
			ps->sta = ft_swap(ps->sta);
			ps->sta->next->focus = 0;
			ps->sta->focus = 1;
		}
		write(1, "sa\n", 3);
	}
	else if (st == 'b')
	{
		if (ps->stb)
		{
			ps->stb = ft_swap(ps->stb);
			ps->stb->next->focus = 0;
			ps->stb->focus = 1;
		}
		write(1, "sb\n", 3);
	}
}
