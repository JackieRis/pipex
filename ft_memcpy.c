/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 05:43:17 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 07:56:13 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cast_dst;
	const unsigned char	*cast_src;

	cast_dst = (unsigned char *) dst;
	cast_src = (unsigned char *) src;
	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return ((void *) cast_dst);
}
