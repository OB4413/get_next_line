/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/10 17:58:45 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *found_new_line(char **buff, int fd)
{
    int     b;
    int     i;

    b = 0;
    *buff = (char *)malloc(BUFFER_SIZE + 1);
    b = read(fd, buff, BUFFER_SIZE);
    buff[b] = '\0';
    return (*buff);
}

static size_t   count_char(t_list *lst)
{
    size_t  len;

    len = 0;
    while (lst != NULL)
    {
        len = len + ft_strlen(lst->content);
        lst = lst->next;
    }
    return (len);
}

static char *cpy_line_in_buff(t_list *lst, char *buff)
{
    
}

char *get_next_line(int fd)
{
    char    *buff;
    t_list  *lst;
    t_list  *ihtafd;
    int     i;
    int     j;

    lst = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
        return (NULL);
    while (found_new_line(&buff, fd) != NULL)
    {
        while (buff[i] != '\0')
        {
            if (buff[i] == '\n')
            {
                i++;
                j++;
                buff[i] = '\0';
                break;
            }
            i++;
        }
        if (lst == NULL)
        {
            lst = (t_list *)malloc(sizeof(t_list));
            lst->content = buff;
            ihtafd = lst;
        }
        if (lst != NULL)
        {
            ihtafd->next = (t_list *)malloc(sizeof(t_list));
            ihtafd = ihtafd->next;
            ihtafd->content = buff;
        }
        if (j == 1)
            break;
        free(buff);
    }
    free(buff);
    i = count_char(lst);
    buff = (char *)malloc(sizeof(char) * (i + 1));
    cpy_line_in_buff(lst, &buff);
    return (buff);
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