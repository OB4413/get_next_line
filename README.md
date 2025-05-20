# 📄 get_next_line

> A function that reads a file line by line using only `read()`. Built for the 1337 School curriculum.

## 📌 Description

The **get_next_line** project consists of implementing a function that returns a line read from a file descriptor, one call at a time. The function must be efficient, memory-safe, and capable of handling multiple file descriptors simultaneously.

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── main.c            # For testing (optional)
├── Makefile
└── README.md
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
make BUFFER_SIZE=42
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
./a.out
