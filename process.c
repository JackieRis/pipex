/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:16:46 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/16 01:37:15 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process(t_pipe *p, int i)
{
	if (i == 0)
		ft_inprocess(p);
	else if (i == lentriple(p->cmd) - 1)
		ft_outprocess(p, i);
	else
		ft_subprocess(p, i);
}

void	ft_inprocess(t_pipe *p)
{
	int	fd;

	if (p->here_doc == 1)
		fd = ft_exec_here_doc(p);
	else
		fd = open(p->input, 0);
	if (fd < 0)
	{
		perror("Pipex");
		exit (1);
	}
	dup2(fd, 0);
	dup2(p->i[0].out, 1);
	ft_close_in(p, fd);
	if (execve(p->cmd[0][0], p->cmd[0], p->env) < 0)
	{
		perror("Pipex");
		exit (1);
	}
}

void	ft_subprocess(t_pipe *p, int i)
{
	dup2(p->i[i - 1].in, 0);
	dup2(p->i[i].out, 1);
	ft_close_sub(p, i);
	if (execve(p->cmd[i][0], p->cmd[i], p->env) < 0)
	{
		perror("Pipex");
		exit (1);
	}
}

void	ft_outprocess(t_pipe *p, int i)
{
	int	fd;

	if (p->here_doc == 1)
		fd = open(p->output, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR \
	| S_IRGRP | S_IROTH);
	else
		fd = open(p->output, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR \
	| S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		perror("Pipex");
		exit (1);
	}
	dup2(fd, 1);
	dup2(p->i[i - 1].in, 0);
	ft_close_out(p, i, fd);
	if (execve(p->cmd[i][0], p->cmd[i], p->env) < 0)
	{
		perror("Pipex");
		exit (1);
	}
}
