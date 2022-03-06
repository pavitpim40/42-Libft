/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:34:51 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/06 21:52:17 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char	*content_dst = (char *)dst;
	char	*content_src = (char *)src;
	int	i;
	
	i = 0;
	while (i < n)
	{
		content_dst[i] = content_src[i];
		i++;
	}
	return (dst);
}

int	main (void)
{
	char str[100] = "Learningisfun";
	char str_2[100] = "Learningisfun";
	char *first, *second;
	first = str;
	second = str;
	printf("Original string :%s\n ", str);
			      
	//when overlap happens then it just ignore it
	memcpy(first + 8, str, 10);
	printf("memcpy overlap : %s\n ", str);
			               
	// my memcpy overlap
	ft_memcpy(first + 8, str, 10);
	printf("my memcpy overlap : %s\n ", str);
			                             
	return 0;
}
