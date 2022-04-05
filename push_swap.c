/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:38:01 by asibille          #+#    #+#             */
/*   Updated: 2022/03/28 08:56:20 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	ps;

	if (argc >= 2)
	{
		ft_init_data(&ps, argv, argc);
		ft_res(&ps);
	}
	ft_free(ps.sta);
	return (0);
}
