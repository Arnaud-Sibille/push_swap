/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:21:07 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 08:59:33 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_do_swap(t_data *ps, char *s)
{
	if (*s == 'a')
		ps->sta = ft_swap(ps->sta);
	else if (*s == 'b')
		ps->stb = ft_swap(ps->stb);
	else if (*s == 's')
	{
		ps->sta = ft_swap(ps->sta);
		ps->stb = ft_swap(ps->stb);
	}
	else
		ft_exit(ps->sta, ps->stb);
	if (s[1] != '\n')
		ft_exit(ps->sta, ps->stb);
}

void	ft_do_push(t_data *ps, char *s)
{
	t_lst	*sta;
	t_lst	*stb;

	sta = ps->sta;
	stb = ps->stb;
	if (*s == 'a')
		ft_push(&stb, &sta);
	else if (*s == 'b')
		ft_push(&sta, &stb);
	else
		ft_exit(ps->sta, ps->stb);
	if (s[1] != '\n')
		ft_exit(ps->sta, ps->stb);
	ps->sta = sta;
	ps->stb = stb;
}

void	ft_do_rot_rev(t_data *ps, char *s)
{
	if (*s == 'a' && s[1] == '\n')
		ps->sta = ft_rot(ps->sta);
	else if (*s == 'b' && s[1] == '\n')
		ps->stb = ft_rot(ps->stb);
	else if (*s == 'r' && s[1] == '\n')
	{
		ps->sta = ft_rot(ps->sta);
		ps->stb = ft_rot(ps->stb);
	}
	else if (*s == 'r' && s[1] == 'a' && s[2] == '\n')
		ps->sta = ft_rev(ps->sta);
	else if (*s == 'r' && s[1] == 'b' && s[2] == '\n')
		ps->stb = ft_rev(ps->stb);
	else if (*s == 'r' && s[1] == 'r' && s[2] == '\n')
	{
		ps->sta = ft_rev(ps->sta);
		ps->stb = ft_rev(ps->stb);
	}
	else
		ft_exit(ps->sta, ps->stb);
}
