/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:07 by asibille          #+#    #+#             */
/*   Updated: 2022/03/24 19:54:22 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_swap(t_lst *ls1)
{
	t_lst	*ls0;
	t_lst	*ls2;
	t_lst	*ls3;

	if (ls1)
	{
		if (ft_nbel(ls1) > 2)
		{
			ls0 = ls1->prev;
			ls2 = ls1->next;
			ls3 = ls2->next;
			ls0->next = ls2;
			ls2->prev = ls0;
			ls2->next = ls1;
			ls1->prev = ls2;
			ls1->next = ls3;
			ls3->prev = ls1;
			return (ls2);
		}
		else
			return (ls1->next);
	}
	return (ls1);
}

static t_lst	*ft_add(t_lst *new, t_lst *st)
{
	t_lst	*ls0;
	t_lst	*ls1;
	t_lst	*ls2;

	if (st)
	{
		if (new)
		{
			ls0 = st->prev;
			ls1 = new;
			ls2 = st;
			ls0->next = ls1;
			ls1->prev = ls0;
			ls1->next = ls2;
			ls2->prev = ls1;
		}
	}
	else if (new)
	{
		new->prev = new;
		new->next = new;
	}
	return (new);
}

static t_lst	*ft_rem(t_lst *st)
{
	t_lst	*ls0;
	t_lst	*ls2;

	if (st)
	{
		if (st == st->next)
			return (NULL);
		else
		{
			ls0 = st->prev;
			ls2 = st->next;
			ls0->next = ls2;
			ls2->prev = ls0;
			return (ls2);
		}
	}
	return (NULL);
}

void	ft_push(t_lst **lsfr, t_lst **lsto)
{
	t_lst	*fr;
	t_lst	*to;
	t_lst	*cp;

	if (lsfr && lsto)
	{
		fr = *lsfr;
		to = *lsto;
		if (*lsfr)
		{
			cp = fr;
			fr = ft_rem(fr);
			to = ft_add(cp, to);
			*lsfr = fr;
			*lsto = to;
		}
	}
}
