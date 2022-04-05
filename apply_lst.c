/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:27 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 11:09:44 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_apply_lst(t_lst *stack, void (*f)(t_lst *))
{
	t_lst	*first;

	first = stack;
	if (stack)
	{
		(*f)(stack);
		stack = stack->next;
		while (stack != first)
		{
			(*f)(stack);
			stack = stack->next;
		}
	}
}

void	ft_apply_lst2(t_lst *stack, int min, void (*f)(t_lst *, int))
{
	t_lst	*first;

	first = stack;
	if (stack)
	{
		(*f)(stack, min);
		stack = stack->next;
		while (stack != first)
		{
			(*f)(stack, min);
			stack = stack->next;
		}
	}
}

void	ft_apply_lst2bis(t_lst *stack, t_lst *stb, void (*f)(t_lst *, t_lst *))
{
	t_lst	*first;

	first = stack;
	if (stack)
	{
		(*f)(stack, stb);
		stack = stack->next;
		while (stack != first)
		{
			(*f)(stack, stb);
			stack = stack->next;
		}
	}
}

void	ft_apls3(t_lst *stack, int min, int max, void (*f)(t_lst *, int, int))
{
	t_lst	*first;

	first = stack;
	if (stack)
	{
		(*f)(stack, min, max);
		stack = stack->next;
		while (stack != first)
		{
			(*f)(stack, min, max);
			stack = stack->next;
		}
	}
}

void	ft_apply_lst4(t_data *ps, void (*f)(t_lst *, t_lst *, int, int))
{
	t_lst	*first;
	t_lst	*sta;
	t_lst	*stb;
	int		min;
	int		max;

	first = ps->sta;
	sta = ps->sta;
	stb = ps->stb;
	min = ps->minb;
	max = ps->maxb;
	if (sta)
	{
		(*f)(sta, stb, min, max);
		sta = sta->next;
		while (sta != first)
		{
			(*f)(sta, stb, min, max);
			sta = sta->next;
		}
	}
}
