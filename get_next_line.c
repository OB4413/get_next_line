/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/14 14:38:41 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	*read_file(int fd, char **p)
{
	char	*buff;
	ssize_t	i;
	char	*joined;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = read(fd, buff, BUFFER_SIZE);
	if (i < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[i] = '\0';
	if (buff[0] == '\0')
	{
		free(buff);
		return (NULL);
	}
	joined = ft_strjoin(*p, buff);
	free(buff);
	free(*p);
	*p = NULL;
	return (joined);
}

static char	*last_p(char **p)
{
	char	*line;
	size_t	k;

	k = 0;
	if (!(*p))
		return (NULL);
	while ((*p)[k] != '\0')
	{
		if ((*p)[k] == '\n')
		{
			k++;
			line = ft_strdup(*p);
			ft_strcpy(*p, &(*p)[k]);
			line[k] = '\0';
			return (line);
		}
		k++;
	}
	line = strdup(*p);
	free(*p);
	*p = NULL;
	return (line);
}

static char	*new_buff(char *buff, char **p, int *j)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			i++;
			*j = 1;
			free(*p);
			*p = ft_strdup(&buff[i]);
			buff[i] = '\0';
			return (buff);
		}
		i++;
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*p = NULL;
	char		*buff;
	char		*mkhzan;
	int			j;

	mkhzan = NULL;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (j != 1 && (buff = read_file(fd, &p)))
	{
		buff = new_buff(buff, &p, &j);
		mkhzan = ft_strjoin(mkhzan, buff);
		free(buff);
	}
	if (!mkhzan && p)
		return (last_p(&p));
	return (mkhzan);
}
