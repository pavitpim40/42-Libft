/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:15:08 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/22 01:29:26 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static	int	check_set(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s1);
	while (check_set(*(s1 + len - 1), set) && len > 0)
		len--;
	while (check_set(*s1++, set) && len > 0)
		len--;
	s1--;
	i = 0;
	str = malloc(sizeof(char) * len);
	while (i < len)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}

static	int	check_set(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}



// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	len;
// 	size_t	i;
// 	size_t	j;
// 	char	*res;

// 	i = 0;
// 	len = ft_strlen(s1);
// 	while (len > 0 && ft_strchr(set,s1[len - 1]) != NULL)
// 		len--;
// 	while (len > 0 && ft_strchr(set,s1[i++]) != NULL)
// 		len--;
// 	i -= 1;
// 	res = ft_calloc(len + 1,1);
// 	if (!res)
// 		return(NULL);
// 	j = 0;
// 	while (j < len)
// 		res[j++] = s1[i++];  
// 	res[j] = '\0';
// 	return (res);	
// }


