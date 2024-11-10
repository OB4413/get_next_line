/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/10 15:33:25 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *found_new_line(char *buff, int fd)
{
    char    *buff;
    int     b;
    int     i;

    b = 0;
    buff = (char *)malloc(BUFFER_SIZE + 1);
    b = read(fd, buff, BUFFER_SIZE);
    buff[b] = '\0';
    while (buff[i] != '\n' && buff[i] != '\0')
        buff[i] = buff[i];
    buff[i + 1] = '\0';
    i = 0;
    while (buff[i] != '\0')
    {
        if (buff[i] == '\n')
            return (NULL);
    }
    return (buff);
}

char *get_next_line(int fd)
{
    char    *buff;
    t_list  *lst;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
        return (NULL);
    buff = found_new_line(fd);
    while (buff != NULL)
    {
        lst = buff;
        
    }
}

int main()
{
    int fd = opne("text", O_RDONLY);
    char *line;
    int lines;

    lines = 1;
    while ((line = get_next_line(fd)))
    {
        printf("%d->%s", lines++, line);
    }
}