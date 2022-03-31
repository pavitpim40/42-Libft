
#include "libft.h"
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