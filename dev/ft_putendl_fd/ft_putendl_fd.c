#include <stdlib.h>

void ft_putendl_fd(char *s, int fd)
{
    if(s == NULL)
        return (0);
    write(fd, s, ft_strlen(s));
    write(fd, "\n", 1);
}