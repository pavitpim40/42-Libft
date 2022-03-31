#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char *ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *new_str;
	int i;

	if (!s)
		return (NULL);
	new_str = ft_strnew(ft_strlen(s));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}