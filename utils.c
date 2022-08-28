/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 08:08:57 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/16 00:29:23 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		if (ft_strncmp(path[i], "PATH=", 5) == 0)
			return (&path[i][5]);
	return (NULL);
}

char	*path_maker(char *c, char **path, char **cmd)
{
	int		i;
	char	*s;

	i = -1;
	while (path[++i])
	{
		s = ft_strjoin(path[i], c);
		if (access(s, F_OK | X_OK) == 0)
		{
			free(cmd[0]);
			cmd[0] = s;
			return (s);
		}
		free(s);
	}
	return (NULL);
}

char	***ft_parsing(t_pipe *p, int argc, char **argv)
{
	char	***cmd;
	int		i;
	int		j;

	cmd = malloc(sizeof(char **) * (argc - 3 + 1));
	if (!cmd)
		return (0);
	p->input = argv[1];
	p->output = argv[argc - 1];
	i = 1 + p->here_doc;
	j = -1;
	while (++i < argc - 1)
	{
		cmd[++j] = ft_split(argv[i], ' ');
		if (!cmd)
			exit (ft_putstr_fd("Command error", 2));
	}
	cmd[++j] = NULL;
	return (cmd);
}

int	lentriple(char	***s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
