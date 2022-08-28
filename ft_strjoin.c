/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 05:43:47 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/11 21:49:25 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	dst = malloc(len_s1 + len_s2 + 2);
	if (!dst)
		return ((void *)0);
	dst[len_s1 + len_s2 + 1] = '\0';
	ft_memcpy(dst, s1, len_s1);
	ft_memcpy(dst + len_s1, "/", 1);
	ft_memcpy(dst + len_s1 + 1, s2, len_s2);
	return (dst);
}
