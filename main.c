#include "get_next_line.h"

int main()
{
    int fd = open("texthh", O_RDONLY);
    char buff[270];
    int h = 0;
    int num = 1;
    printf("%d", fd);
    while ((h = read(fd, buff, 4)))
    {
        printf("%d", h);
        if (h == -1)
            break;
    }
}