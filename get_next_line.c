/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/13 20:54:29 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char p[BUFFER_SIZE] = {0};

static void ft_strcpy(char *s2)
{
    size_t  i;

    i = 0;
    while (s2[i] != '\0')
    {
        p[i] = s2[i];
        i++;
    }
    p[i] = '\0';
}

static char *read_file(int fd, char *p)
{
    char    *buff;
    size_t  i;

    i = 0;
    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    i = read(fd, buff, BUFFER_SIZE);
    buff[i] = '\0';
    if(buff[0] == '\0')
        return (NULL);
    return (ft_strjoin(p , buff));
}

char    *get_next_line(fd)
{
    char    *buff;
    char    *mkhzan = NULL;
    size_t  i;
    size_t  l;
    int     j;
    size_t  k;
    char    *line;

    l = 0;
    j = 0;
    k = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    // while (p[k] != '\0')
    // {
    //     if (p[k] == '\n')
    //     {
    //         k++;
    //         if (p[k] == '\0')
    //             return ()
    //         line = p;
    //         ft_strcpy(&p[k]);
    //         line[k] = '\0';
    //         return (line);
    //     }
    //     k++;
    // }
    while (j != 1 && (buff = read_file(fd, p)))
    {
        if (p[0] != '\0')
        {
            p[0] = '\0';
        }
        i = 0;
        while (buff[i] != '\0')
        {
            if(buff[i] == '\n')
            {
                i++;
                j = 1;
                while (buff[i + l] != '\0')
                {
                    p[l] = buff[i + l];
                    l++;
                }
                p[l] = '\0';
                buff[i] = '\0';
                break;
            }
            i++;
        }
        mkhzan = ft_strjoin(mkhzan, buff);
    }
    if (mkhzan == NULL)
    {
        printf("%s\n", p);
        while (p[k] != '\0')
        {
            if (p[k] == '\n')
            {
                k++;
                line = p;
                ft_strcpy(&p[k]);
                line[k] = '\0';
                return (line);
            }
            k++;
        }
    }
    return (mkhzan);
}
