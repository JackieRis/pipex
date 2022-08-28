/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 05:42:25 by tnguyen-          #+#    #+#             */
/*   Updated: 2021/12/24 20:14:20 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;

	str = malloc(size * count);
	if (!str)
		return ((void *)0);
	ft_bzero(str, size * count);
	return ((void *)str);
}
