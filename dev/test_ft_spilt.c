#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int  count_word (char const *s, char c)
{
    size_t  len;
    size_t  end_word;
    
    len = 0;
    end_word = 0;
    while (*s)
    {
        if (*s != c && end_word == 1)
        {
            len++;
            end_word = 0;
        }
        else if (*s == c && end_word == 0)
            end_word = 1;
        s++;
    }
    if (s[0] == c)
        len--;
    if (s[ft_strlen(s) - 1] == c)
        len--;
    return (len + 1);
}

int main()
{
    printf("%d", count_word("XXX-XXXX-XXXX",'-'));
    return(0);
}