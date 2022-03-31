#include <stdio.h>


int main()
{
    int a = -2147483648;
    long b = (long)a * -1;
    printf("%ld\n", b);
    return (0);
}