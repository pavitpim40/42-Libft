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
	int len;
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
		str[i++] = ((long)nb * sign / ft_power(10, len)) + '0';
		nb = nb % ft_power(10, len);
	}
	return (str);
}

int main ()
{

	// printf("## %u\n", ft_intlen(-214));
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
