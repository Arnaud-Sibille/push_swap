/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mispl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:34:30 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 11:34:40 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mispl(t_lst *ls, int min)
{
	int		count;
	int		pos;
	t_lst	*ls_cp;

	ls_cp = ls;
	count = 0;
	if (ls->pos != min)
	{
		pos = ls->pos;
		ls = ls->prev;
		while (ls->pos != min)
		{
			if (ls->pos > pos)
				++count;
			ls = ls->prev;
		}
	}
	ls_cp->mispl = count;
}
