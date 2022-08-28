/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:59:53 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/16 00:04:36 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sc1;
	const unsigned char	*sc2;

	if (!s1 || !s2)
		return (0);
	sc1 = (const unsigned char *) s1;
	sc2 = (const unsigned char *) s2;
	while (n--)
	{
		if (*sc1 != *sc2)
			return (*sc1 - *sc2);
		sc1++;
		sc2++;
	}
	return (0);
}
