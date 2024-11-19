/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/16 12:30:14 by obarais          ###   ########.fr       */
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
	if (i == 0)
	{
		free(buff);
		return (NULL);
	}
	if (i == -1)
	{
		free(buff);
		free(*p);
		*p = NULL;
		return (NULL);
	}
	buff[i] = '\0';
	joined = ft_strjoin(*p, buff);
	if (!joined)
	{
		free(buff);
		free(*p);
		*p = NULL;
		return (NULL);
	}
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
			if (line == NULL)
				return (NULL);
			ft_strcpy(*p, &(*p)[k]);
			line[k] = '\0';
			return (line);
		}
		k++;
	}
	line = ft_strdup(*p);
	if (line == NULL)
	{
		return (NULL);
		free(*p);
		*p = NULL;
	}
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
			if (*p == NULL)
				return (NULL);
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

	j = 0;
	mkhzan = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (j != 1)
	{
		buff = read_file(fd, &p);
		if (!buff)
			break ;
		buff = new_buff(buff, &p, &j);
		if (buff == NULL)
		{
			free(buff);
			return (NULL);
		}
		if (mkhzan)
		{
			char *temp = ft_strjoin(mkhzan, buff);
			if (temp == NULL)
			{
				free(mkhzan);
				free(buff);
				return (NULL);
			}
			free(mkhzan);
			mkhzan = temp;
		}
		else
		{
			mkhzan = ft_strdup(buff);
			if (mkhzan == NULL)
			{
				free(buff);
				return (NULL);
			}
		}
		free(buff);
	}
	if (!mkhzan && p && p[0] != '\0')
		return (last_p(&p));
	if (!mkhzan)
	{
		free(p);
		p = NULL;
		return (NULL);
	}
	return (mkhzan);
}
