#include <stdio.h>

// SYNOPSIS
//      #include <string.h>

//      int
//      strncmp(const char *s1, const char *s2, size_t n);

// DESCRIPTIONxw
//      strncmp() functions lexicographically compare the null-terminated strings s1 and s2.

//      The strncmp() function compares not more than n characters.  Because strncmp() is designed for comparing strings rather than
//      binary data, characters that appear after a `\0' character are not compared.

// RETURN VALUES
//      strncmp() functions return an integer greater than, equal to, or less than 0, according as the string s1 is
//      greater than, equal to, or less than the string s2.  The comparison is done using unsigned characters, so that `\200' is greater
//      than `\0'.


int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(void)
{
    printf("%d", ft_strncmp("Hzllo","Hallo",20));
}