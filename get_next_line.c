/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/14 10:40:44 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *p = NULL;

static void ft_strcpy(char *s2)
{
    size_t i = 0;

    while (s2[i] != '\0')
    {
        p[i] = s2[i];
        i++;
    }
    p[i] = '\0';
}

static char *read_file(int fd, char *p)
{
    char *buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);

    ssize_t i = read(fd, buff, BUFFER_SIZE);
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

    char *joined = ft_strjoin(p, buff);
    free(buff);
    return (joined);
}
 
char *get_next_line(int fd)
{
    char *buff;
    char *mkhzan = NULL;
    size_t i, k = 0;
    int j = 0;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while (j != 1 && (buff = read_file(fd, p)))
    {
        if (p && p[0] != '\0')
            p[0] = '\0';

        i = 0;
        while (buff[i] != '\0')
        {
            if (buff[i] == '\n')
            {
                i++;
                j = 1;
                free(p);
                p = ft_strdup(&buff[i]);
                buff[i] = '\0';
                break;
            }
            i++;
        }
        mkhzan = ft_strjoin(mkhzan, buff);
        free(buff);
    }

    if (!mkhzan && p)
    {
        while (p[k] != '\0')
        {
            if (p[k] == '\n')
            {
                k++;
                line = ft_strdup(p);
                ft_strcpy(&p[k]);
                line[k] = '\0';
                return (line);
            }
            k++;
        }
        line = ft_strdup(p);
        free(p);
        p = NULL;
        return (line);
    }
    return (mkhzan);
}
