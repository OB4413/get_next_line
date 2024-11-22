/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:31:14 by obarais           #+#    #+#             */
/*   Updated: 2024/11/22 11:39:30 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char **p)
{
	char	*buff;
	char	*join;
	ssize_t	i;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	i = read(fd, buff, BUFFER_SIZE);
	if (i == -1 || i == 0)
	{
		free(buff);
		if (i == -1)
		{
			free(*p);
			*p = NULL;
		}
		return (NULL);
	}
	buff[i] = '\0';
	join = ft_strjoin(*p, buff);
	free(buff);
	free(*p);
	*p = NULL;
	return (join);
}

static char	*finde_newline(char *buff, char **p, int *j)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			i++;
			*j = 1;
			*p = ft_strdup(&buff[i]);
			if (*p == NULL)
				return (NULL);
			buff[i] = '\0';
			return (buff);
		}
		i++;
	}
	return (buff);
}

static char	*ft_get_line(int fd, char **p)
{
	char	*buff;
	char	*join;
	char	*temp;
	int		j;

	join = NULL;
	j = 0;
	while (j != 1)
	{
		buff = read_file(fd, &(*p));
		if (buff == NULL)
			break ;
		buff = finde_newline(buff, &(*p), &j);
		temp = ft_strjoin(join, buff);
		free(join);
		join = temp;
		free(buff);
	}
	if (join == NULL && *p != NULL)
	{
		join = *p;
		*p = NULL;
	}
	return (join);
}

char	*get_next_line(int fd)
{
	static char	*p[OPEN_MAX];
	char		*temp;
	int			j;

	j = 0;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (p[fd] != NULL)
	{
		if (p[fd][0] == '\0')
		{
			free(p[fd]);
			p[fd] = NULL;
			break ;
		}
		temp = finde_newline(p[fd], &p[fd], &j);
		if (j == 1)
			return (temp);
		break ;
	}
	return (ft_get_line(fd, &p[fd]));
}
