/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:07:47 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/31 11:25:01 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nb)
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

static int	ft_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

static char	*ft_write(char *str, int nbr, int sign, int len)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		len-- ;
	}
	while (len--)
	{
		str[i++] = (nbr * sign / ft_power(10, len)) + '0';
		nbr = nbr % ft_power(10, len);
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		len;
	int		sign;
	long	nbr;

	len = 0;
	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		len = 1;
	}
	nbr = nb * sign;
	len += ft_intlen (nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (ft_write(str, nb, sign, len));
}
