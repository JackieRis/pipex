/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:46:10 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/13 03:57:33 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	free_cmd(char ***s)
{
	int	i;

	i = -1;
	while (s[++i])
		free_split(s[i]);
	free(s);
}

void	free_all(t_pipe *p)
{
	free(p->i);
	free_split(p->path);
	free_cmd(p->cmd);
}
