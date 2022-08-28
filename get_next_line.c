/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:43:44 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/13 04:40:04 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *rst, char **ret)
{
	char	*tmp;

	*ret = NULL;
	if (ft_strchr(rst, '\n'))
	{
		*ret = ft_strcdup(rst, '\n');
		tmp = ft_strcdup(ft_strchr(rst, '\n') + 1, '\0');
		free(rst);
		return (tmp);
	}
	return (rst);
}

char	*get_next_line(int fd)
{
	int			res;
	char		buff[BUFFER_SIZE + 1];
	static char	*rst;
	char		*ret;

	if (read(fd, NULL, 0) < 0)
		return (NULL);
	while (!ft_strchr(rst, '\n'))
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res <= 0)
			break ;
		buff[res] = '\0';
		rst = ft_strjoine(rst, buff);
	}
	rst = new_line(rst, &ret);
	if (ret)
		return (ret);
	if (rst && rst[0] != '\0')
		ret = ft_strcdup(rst, '\0');
	free(rst);
	rst = NULL;
	return (ret);
}
