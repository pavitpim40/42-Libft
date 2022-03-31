

char    *ft_itoa(int c){
    int     i;
    int     n;
    char    *str;

    i = 0;
    n = c;
    while (n != 0)
    {
        n = n / 10;
        i++;
    }
    str = (char*)malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    while (i > 0)
    {
        str[i - 1] = c % 10 + '0';
        c = c / 10;
        i--;
    }
    return (str);
}