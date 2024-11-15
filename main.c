#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("files/empty", O_RDWR);
    char    *line;
    while((line = get_next_line(fd)))
    {
        
        printf("%s", line);
        if (line == NULL)
            break;
    }
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
    // printf("==%s\n", get_next_line(fd));
}