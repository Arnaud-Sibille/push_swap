/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:17 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 09:07:09 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	ft_min(int a, int b)
{
	if (b < a)
		return (b);
	else
		return (a);
}

void	ft_free(t_lst *st)
{
	t_lst	*first;
	t_lst	*temp;

	first = st;
	if (st)
	{
		while (st != first)
		{
			temp = st->next;
			free(st);
			st = temp;
		}
	}
}

void	ft_exit(t_lst *sta, t_lst *stb)
{
	ft_free(sta);
	ft_free(stb);
	write(2, "Error\n", 6);
	exit(-1);
}
