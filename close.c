/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:03:40 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/13 03:47:48 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_in(t_pipe *p, int fd)
{
	if (close(fd) < 0)
	{
		perror("Pipex:4");
		exit (1);
	}
	if (close(p->i[0].out) < 0)
	{
		perror("Pipex:5");
		exit (1);
	}
	if (close(p->i[0].in) < 0)
	{
		perror("Pipex:6");
		exit (1);
	}
}

void	ft_close_sub(t_pipe *p, int i)
{
	if (close(p->i[i - 1].in) < 0)
	{
		perror("Pipex:");
		exit (1);
	}
	if (close(p->i[i].out) < 0)
	{
		perror("Pipex:");
		exit (1);
	}
	if (close(p->i[i - 1].out) < 0)
	{
		perror("Pipex:");
		exit (1);
	}
	if (close(p->i[i].in) < 0)
	{
		perror("Pipex:");
		exit (1);
	}
}

void	ft_close_out(t_pipe *p, int i, int fd)
{
	if (close(fd) < 0)
	{
		perror("Pipex:0");
		exit (1);
	}
	if (close(p->i[i - 1].in) < 0)
	{
		perror("Pipex:1");
		exit (1);
	}
	if (close(p->i[i - 1].out) < 0)
	{
		perror("Pipex:2");
		exit (1);
	}
}

void	ft_close_pipe(t_pipe *p, int i)
{
	if (close(p->i[i].in) < 0)
	{
		perror("Pipex:10");
		exit (1);
	}
	if (close(p->i[i].out) < 0)
	{
		perror("Pipex:11");
		exit (1);
	}
}
