/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obarais <obarais@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:39 by obarais           #+#    #+#             */
/*   Updated: 2024/11/13 17:49:00 by obarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char p[BUFFER_SIZE] = {0};

static char *read_file(int fd, char *p)
{
    char *buff;
    size_t i;

    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buff == NULL)
        return (NULL);
    i = read(fd, buff, BUFFER_SIZE);
    if (i <= 0)
    {
        free(buff);
        return (NULL);
    }
    buff[i] = '\0';

    char *joined = ft_strjoin(p, buff);
    free(buff);
    return (joined);
}

char *get_next_line(int fd)
{
    char *buff;
    char *mkhzan = NULL;
    size_t i, l, k = 0;
    int j = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // التحقق من `p` إذا كانت تحتوي على سطر كامل
    while (p[k] != '\0')
    {
        if (p[k] == '\n')
        {
            k++;
            // if (p[k] == '\0')
            //     return  (p);
            char *line = strdup(p);
            strcpy(p, &p[k]);
            line[k] = '\0';
            return (line);
        }
        k++;
    }

    // قراءة المزيد من البيانات إذا لم نجد سطرًا كاملاً
    while (j != 1 && (buff = read_file(fd, p)))
    {
        i = 0;
        while (buff[i] != '\0')
        {
            if (buff[i] == '\n')
            {
                j = 1;
                i++;
                strcpy(p, &buff[i]);  // نسخ المتبقي إلى `p`
                buff[i] = '\0';      // إنهاء السطر عند `\n`
                break;
            }
            i++;
        }
        mkhzan = ft_strjoin(mkhzan, buff); // نسخ إلى `mkhzan`
        free(buff);
    }

    return (mkhzan);
}

