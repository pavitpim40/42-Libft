#include <stdio.h>

int     ft_strlen(char *c)
{
    int len = 0;
    while(*c)
    {
        c ++;
        len += 1;
    }
    return (len);
}

char    *ft_strrchr(const char *s, int c)
{
    int i;
    char    *ptr;

    i=ft_strlen((char *)s);
    while(i >= 0)
    {
    if (s[i] == (char)c)
        return((char*)(&s[i]));
        i--;
    }
return (0);
}


int main(void)
{
    printf("%s\n", ft_strrchr("Hello",99));
}