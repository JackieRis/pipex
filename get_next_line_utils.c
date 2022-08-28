/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:45:37 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/13 04:39:48 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	i = -1;
	cast_dst = (unsigned char *) dst;
	cast_src = (unsigned char *) src;
	if (!src && !dst)
		return (NULL);
	if (cast_dst > cast_src)
	{
		while (0 < n)
		{
			cast_dst[n - 1] = cast_src[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			cast_dst[i] = cast_src[i];
	}
	return ((void *)cast_dst);
}

char	*ft_strjoine(char *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	dst = malloc(len_s1 + len_s2 + 1);
	if (!dst)
		return ((void *)0);
	dst[len_s1 + len_s2] = '\0';
	ft_memmove(dst, s1, len_s1);
	ft_memmove(dst + len_s1, s2, len_s2);
	free(s1);
	return (dst);
}

char	*ft_strcdup(const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	if (s[len] == c && c != '\0')
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = -1;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!c)
		return ((char *)s + s_len);
	while (++i < s_len)
		if (s[i] == (char) c)
			return ((char *)s + i);
	return (0);
}
