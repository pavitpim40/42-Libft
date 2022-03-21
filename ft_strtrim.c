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

static	int	check_set_trim(char const *set, char const c)
{
	if (*set && *set == c)
	{
		set++;
		return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*str;
	
	i = 0;
	len = ft_strlen(s1);
	while (len > 0 && check_set_trim(set, s1[len-1]))
		len--;	
	while (len > 0 && check_set_trim(set, s1[i]))
	{
		i++;
		len--;
	}
	i = 0;
	str = (char *)(ft_calloc(len,1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = *s1++;
	return (str);
}
