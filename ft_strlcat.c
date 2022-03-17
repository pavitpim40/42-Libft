/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:39:39 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/06 21:35:21 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dstsize == 0 || dst_len >= dstsize)
	{
		return (dst_len + src_len);
	}
	while ((i < dstsize - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++ ;
		j++ ;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
