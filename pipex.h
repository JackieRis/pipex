/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:29:10 by tnguyen-          #+#    #+#             */
/*   Updated: 2022/01/16 01:40:02 by tnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_vec
{
	int	in;
	int	out;
}		t_vec;

typedef struct s_pipe
{
	char	***cmd;
	char	**path;
	int		arg;
	char	**env;
	t_vec	*i;
	char	*input;
	char	*output;
	int		here_doc;
	char	*delim;
	t_vec	here;
}		t_pipe;

size_t	ft_strlen(const char *str);
int		ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	***ft_parsing(t_pipe *p, int argc, char **argv);
void	free_split(char **s);
void	free_cmd(char ***s);
char	*get_path(char **path);
char	*path_maker(char *c, char **path, char **cmd);
int		ft_wordcount(char const *s, char c);
int		lentriple(char	***s);
void	ft_inprocess(t_pipe *p);
void	ft_subprocess(t_pipe *p, int i);
void	ft_outprocess(t_pipe *p, int i);
void	ft_process(t_pipe *p, int i);
void	ft_close_in(t_pipe *p, int fd);
void	ft_close_sub(t_pipe *p, int i);
void	ft_close_out(t_pipe *p, int i, int fd);
void	ft_close_pipe(t_pipe *p, int i);
void	free_all(t_pipe *p);
char	*get_next_line(int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmpv(const char *s1, const char *s2, size_t n);
int		ft_exec_here_doc(t_pipe *p);
void	ft_read(t_pipe *p);

#endif
