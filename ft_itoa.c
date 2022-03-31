/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:07:47 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/27 00:07:49 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ft_intlen (long nb)
{
	int	size;
	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

static int ft_power (int nb, int power)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int 	len;
	size_t	i;
	int		sign;

	len = 0;
	i = 0;
	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		len = 1;
	}
	len += ft_intlen((long)nb*sign);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (nb < 0){
		str[i++] = '-';
		len-- ;
	}
	while (len--)
	{
		str[i++] = ((long)nb*sign / ft_power(10, len)) + '0';
		nb = nb % ft_power(10, len);
	}
	return (str);
}
