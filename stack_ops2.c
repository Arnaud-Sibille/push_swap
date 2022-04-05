/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:53:56 by asibille          #+#    #+#             */
/*   Updated: 2022/03/24 19:57:39 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_rot(t_lst *ls)
{
	if (ls)
		return (ls->next);
	return (ls);
}

t_lst	*ft_rev(t_lst *ls)
{
	if (ls)
		return (ls->prev);
	return (ls);
}
