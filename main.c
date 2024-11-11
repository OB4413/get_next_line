#include "get_next_line.h"

int main()
{
    int fd = open("text", O_RDONLY);
    char *line;
    int lines;

    lines = 0;
    while((line = get_next_line(fd)))
    {
        if (line == NULL)
            break;
        printf("%d->%s\n", lines++, line);
    }
}