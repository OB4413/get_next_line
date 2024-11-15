#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("text", O_RDONLY);
    char    *line;
    while((line = get_next_line(fd)))
    {
        if (line == NULL)
            break;
        printf("%s", line);
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