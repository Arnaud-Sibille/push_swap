/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:23:10 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 14:55:19 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen2(s1);
	ptr = malloc (len + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i <= len)
		ptr[i] = s1[i];
	return (ptr);
}

int	ft_strlen2(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		ptr[i] = 0;
		++i;
	}
	return ((void *) ptr);
}

char	*ft_strjoin_buffer(char *s1)
{
	char	*ptr;
	int		s1_len;
	char	*ptr_cpy;
	char	*s1_cpy;

	s1_cpy = s1;
	s1_len = ft_strlen2(s1);
	ptr = ft_calloc((s1_len + BUFFER_SIZE + 1), sizeof(char));
	ptr_cpy = ptr;
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (*s1)
			*(ptr++) = *(s1++);
	}
	free(s1_cpy);
	return (ptr_cpy);
}
