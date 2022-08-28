/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:30:28 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/02/09 17:15:30 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/errno.h>
#include <string.h>

int	ft_exec_here_doc(t_pipe *p)
{
	int	f;

	p->here.in = -1;
	pipe(&p->here.in);
	f = fork();
	if (f == 0)
	{
		dup2(p->here.out, 1);
		close(p->here.out);
		close(p->here.in);
		ft_read(p);
		exit (0);
	}
	close(p->here.out);
	return (p->here.in);
}

void	ft_read(t_pipe *p)
{
	char	*line;

	line = get_next_line(0);
	while (ft_strncmpv(p->delim, line, (int)ft_strlen(p->delim)) != 0)
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	ft_here_doc(t_pipe *p, char **argv, int argc)
{
	if (ft_strncmp("here_doc", argv[1], 8) != 0)
	{
		p->here_doc = 0;
		return ;
	}
	if (argc < 6)
		exit (ft_putstr_fd("Arg error", 2));
	p->delim = argv[2];
	p->here_doc = 1;
}

void	ft_fork(t_pipe	*p)
{
	int	f;
	int	i;
	int	status;

	p->i = malloc(sizeof(t_vec) * (lentriple(p->cmd) - 1));
	if (!p->i)
		return ;
	i = -1;
	while (p->cmd[++i])
	{
		if (i < (lentriple(p->cmd) - 1) && pipe(&p->i[i].in) < 0)
		{
			perror("Pipex:");
			exit (1);
		}
		f = fork();
		if (f == 0)
			ft_process(p, i);
		if (i > 0)
			ft_close_pipe(p, i - 1);
	}
	while (i-- > 0)
		wait(&status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p;
	char	*tmp;
	int		i;

	if (argc < 5)
		return (ft_putstr_fd("Arg errors !", 2));
	ft_here_doc(&p, argv, argc);
	tmp = get_path(envp);
	if (!tmp)
		return (ft_putstr_fd("Command not found.", 2));
	p.env = envp;
	p.path = ft_split(tmp, ':');
	p.cmd = ft_parsing(&p, argc, argv);
	i = -1;
	while (++i < argc - (3 + p.here_doc))
		tmp = path_maker(p.cmd[i][0], p.path, p.cmd[i]);
	ft_fork(&p);
	free_all(&p);
	sleep(60);
	return (argc);
}
