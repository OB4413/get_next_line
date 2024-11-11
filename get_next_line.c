/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:45 by obarais           #+#    #+#             */
/*   Updated: 2024/11/11 15:54:25 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *found_new_line(char *buff, int fd)
{
    size_t  i;

    i = 0;
    buff = (char *)malloc(BUFFER_SIZE + 1);
    i = read(fd, buff, BUFFER_SIZE);
    buff[i] = '\0';
    return (buff);
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
    int  i;
    int  j;
    char *content;
    
    i = 0;
    while (lst != NULL)
    {
        content = (char *)(lst->content);
        j = 0;
        while (content[j] != '\0')
        {
            buff[i] = content[j];
            i++;
            j++;
        }
        lst = lst->next;
    }
    buff[i] = '\0';
    return (buff);
}

char *get_next_line(int fd)
{
    char    *buff;
    t_list  *lst;
    t_list  *ihtafd;
    size_t    i;
    size_t    j;

    i = 0;
    j = 0;
    lst = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
        return (NULL);
    while ((buff = found_new_line(buff, fd)) && j != 1)
    {
        i = 0;
        if (buff[i] == '\0')
            return NULL;
        while (buff[i] != '\0')
        {
            if (buff[i] == '\n')
            {
                j = 1;
                buff[i] = '\0';
                break;
            }
            i++;
        }
        if (lst == NULL)
        {
            lst = (t_list *)malloc(sizeof(t_list));
            lst->content = ft_strdup(buff);
            lst->next = NULL;
            ihtafd = lst;
        }
        else
        {
            ihtafd->next = (t_list *)malloc(sizeof(t_list));
            ihtafd = ihtafd->next;
            ihtafd->content = ft_strdup(buff);
            ihtafd->next = NULL;
        }
        // printf("%s", buff);
        if (j == 1)
            break;
    }
    i = count_char(lst);
    buff = (char *)malloc(sizeof(char) * (i + 1));
    return (cpy_line_in_buff(lst, buff));
}
