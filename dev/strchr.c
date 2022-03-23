#include <stdio.h>
char *strchr(const char *s, int c)
{
    int     i;

    i = 0;
    while (s[i] != (char)c)
    {
    if(s[i]=='\0')
    return (0);
    i ++;
    }
    return ((char *)(&s[i]));
}
int main(void)
{
    printf("%s\n", strchr("Hello", 72)); //H
      printf("%s\n", strchr("Hello", 108)); //l  
}