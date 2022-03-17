/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:23 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/17 22:57:27 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{

	size_t	i;
	int	j = 0;

	if (!dst && !src)
		return (0);
	if((size_t)src + len > (size_t)dst)
	{
		i = len - 1;
		while(i < len)
		{
			printf("%c:i = %lu : j = %d\n", ((char *)src)[i],i,j);
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
			j ++;
		}
	}
	else
	{
		i = 0;
		while(i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i ++;
		}
	}
	return (dst);
}

int	main(void)
{
	char csrc[100] = "Geeksfor";
	memmove(csrc+5, csrc, strlen(csrc)+1);
	printf("%s\n", csrc);

	char src[100] = "Geeksfor";
	ft_memmove(src+5, src, strlen(src)+1);
	printf("%s\n", src);
	         return 0;
}
