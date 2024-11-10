/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:36 by obarais           #+#    #+#             */
/*   Updated: 2024/11/10 11:32:21 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

char    *get_next_line(int fd);
ssize_t read(int fd, void *buff, size_t size);

#endif