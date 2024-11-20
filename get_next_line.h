/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:44:36 by obarais           #+#    #+#             */
/*   Updated: 2024/11/20 11:11:13 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
ssize_t				read(int fd, void *buff, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);

#endif