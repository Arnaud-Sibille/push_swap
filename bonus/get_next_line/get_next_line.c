/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:44:44 by asibille          #+#    #+#             */
/*   Updated: 2022/03/25 14:55:11 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*str;
	int			ret;

	if (BUFFER_SIZE < 0)
		return (NULL);
	str = NULL;
	if (buf)
		str = ft_buf_to_str_newbuf(&buf);
	while (!str)
	{
		buf = ft_strjoin_buffer(buf);
		ret = read(fd, &buf[ft_strlen2(buf)], BUFFER_SIZE);
		if (ret == -1)
			return (ft_no_read_case(&buf));
		else if (ret == 0)
		{
			str = ft_nul_return(&buf);
			return (str);
		}
		else
			str = ft_buf_to_str_newbuf(&buf);
	}
	return (str);
}

char	*ft_buf_to_str_newbuf(char **buf)
{
	char	*str;
	char	*buf_cpy;
	int		i;

	i = 0;
	buf_cpy = *buf;
	while (*buf_cpy)
	{
		if (*buf_cpy == '\n')
		{
			str = *buf;
			buf_cpy = ft_strdup(buf_cpy + 1);
			str[i + 1] = 0;
			*buf = buf_cpy;
			return (str);
		}
		++(buf_cpy);
		++i;
	}
	return (NULL);
}

char	*ft_nul_return(char **buf)
{
	char	*buf_cpy;
	char	*str;

	buf_cpy = *buf;
	if (ft_strlen2(buf_cpy))
	{
		str = buf_cpy;
		*buf = NULL;
		return (str);
	}
	else
	{
		free(buf_cpy);
		*buf = NULL;
		return (NULL);
	}
}

char	*ft_no_read_case(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (NULL);
}
