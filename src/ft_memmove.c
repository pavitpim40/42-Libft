/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:34:23 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/14 14:06:24 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	char	*tmp;
	int		i;

	if (!dst && !src)
		return (0);
	cdst = (char *)dst;
	csrc = (char *)src;
	tmp = new char[len];
	i = 0;
	while (i < len)
	{
		tmp[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cdst[i] = tmp[i];
		i ++;
	}
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
