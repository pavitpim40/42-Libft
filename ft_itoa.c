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
static size_t ft_intlen (size_t nb)
{
	size_t len;
	size_t i;

	len = 0;
	i = nb;
	if (nb < 0)
	{
		len++;
		i = -nb;
	}
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
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
	size_t	len;
	size_t	i;
	int		sign;

	sign = 1;
	len = ft_intlen(nb);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		sign = -1;
		str[i++] = '-';
	}
	while (len--)
	{
		str[i++] = (nb / ft_power(10, len)) * sign + '0';
		nb = nb % ft_power(10, len);
	}
	return (str);
}
