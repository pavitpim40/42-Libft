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

#include <stdio.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}


static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}
static int ft_intlen (long nb)
{
	int	size;
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
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

static char	*ft_write(char *str, long nbr, int sign, int len)
{
	int	i;

	i = 0;
	if (sign < 0)
	{
		str[i++] = '-';
		len-- ;
	}
	while (len--)
	{
		str[i++] = (nbr / ft_power(10, len)) + '0';
		nbr = nbr  % ft_power(10, len);
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
		nbr = (long)nb * (long)sign;
	len += ft_intlen (nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	printf("in ITOA %ld \n", nbr);
	return (ft_write(str, nbr, sign, len));
}

int main ()
{

	// printf("## %u\n", ft_intlen(-214));
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
