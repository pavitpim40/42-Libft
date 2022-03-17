/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:13:57 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/17 23:29:35 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((void *)(s + i));
		i ++;
	}
	return (0);
}
