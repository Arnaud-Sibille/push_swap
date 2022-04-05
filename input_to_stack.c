/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:37:44 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 09:06:57 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_algo(size_t val, int sign, const char *s, t_lst *st)
{
	if (!ft_isdigit(*s))
		ft_exit(st, NULL);
	while (*s >= '0' && *s <= '9')
	{
		val = val * 10 + *s - '0';
		++s;
		if (sign == 1 && val > INT_MAX)
			ft_exit(st, NULL);
		else if (sign == -1 && (-1 * (long) val < INT_MIN))
			ft_exit(st, NULL);
	}
	if (!(*s == ' ' || (*s >= 9 && *s <= 13) || !*s))
		ft_exit(st, NULL);
	return (val);
}

static int	ft_new_atoi(const char *s, t_lst *st)
{
	int				sign;
	size_t			val;

	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	val = 0;
	if (!ft_isdigit(*s))
		ft_exit(st, NULL);
	val = ft_algo(val, sign, s, st);
	return (sign * (int) val);
}

static void	ft_init(t_lst *new, int val)
{
	new->val = val;
	new->focus = 0;
	new->pos = 0;
	new->next = new;
	new->prev = new;
	new->sw_cost = 0;
	new->pu_cost = 0;
	new->ad_cost = 0;
	new->dist_rev = 0;
	new->dist_rot = 0;
	new->pu_pl = NULL;
	new->pu_way = -1;
	new->mispl = 0;
	new->ad_pl = NULL;
	new->ad_way = -1;
}

static t_lst	*ft_addback(t_lst *stack, t_lst *new)
{
	t_lst	*first;

	first = stack;
	if (!stack)
	{
		new->focus = 1;
		return (new);
	}
	else
	{
		while (stack->next != first)
			stack = stack->next;
		stack->next = new;
		new->prev = stack;
		new->next = first;
		first->prev = new;
	}
	return (first);
}

t_lst	*ft_input_to_stack(char *s, t_lst *stack)
{
	t_lst	*new;
	int		count;

	count = 0;
	while (*s)
	{
		if ((ft_isdigit(*s) || *s == '-' || *s == '+') && ++count)
		{
			new = malloc(sizeof(t_lst));
			if (!new)
				ft_exit(stack, NULL);
			ft_init(new, ft_new_atoi(s, stack));
			stack = ft_addback(stack, new);
			while (ft_isdigit(*s) || *s == '-' || *s == '+')
				++s;
		}
		else if (*s == ' ' || (*s >= 9 && *s <= 13))
			++s;
		else
			ft_exit(stack, NULL);
	}
	if (count == 0)
		ft_exit(stack, NULL);
	return (stack);
}
