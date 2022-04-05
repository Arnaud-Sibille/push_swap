/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:43:50 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 09:38:31 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_check(t_data *ps)
{
	if (!ps->stb)
	{
		if (!ps->sta)
			write(1, "OK\n", 3);
		else
		{
			if (!ps->sta->pos && ft_is_ordered(ps->sta, ps->mina, ps->maxa))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
	}
	else
		write(1, "KO\n", 3);
}

static void	ft_ops(t_data *ps, char *s)
{
	if (*s == 's')
		ft_do_swap(ps, s + 1);
	else if (*s == 'p')
		ft_do_push(ps, s + 1);
	else if (*s == 'r')
		ft_do_rot_rev(ps, s + 1);
	else
		ft_exit(ps->sta, ps->stb);
}

int	main(int argc, char **argv)
{
	t_data	ps;
	char	*s;

	if (argc >= 2)
	{
		ft_init_data(&ps, argv, argc);
		s = get_next_line(0);
		while (s)
		{
			ft_ops(&ps, s);
			free(s);
			s = get_next_line(0);
		}
		ft_check(&ps);
	}
}
