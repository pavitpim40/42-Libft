/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:00:16 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/18 00:21:21 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
static void    ft_bzero(void *s, size_t n)
{
  char    *str;
  size_t  i;

  i = 0;
  str = (char *)s;
  while (i < n)
  {
    str[i] = '\0';
    i++;
    printf("i == %lu\n",i);
  }
}

void    *ft_calloc(size_t count, size_t size)
{
  void    *ptr;

  ptr = malloc(count * size);
  if(ptr == 0)
    return (ptr);
  ft_bzero(ptr, count * size);
  return (ptr);
}

int main () {
  int i, n;
  int *a;

  printf("Number of elements to be entered:");
  scanf("%d",&n);

  a = (int*)ft_calloc(n, sizeof(int));
  printf("Enter %d numbers:\n",n);
  for( i=0 ; i < n ; i++ ) {
  scanf("%d",&a[i]);
}
printf("The numbers entered are: ");
 for( i=0 ; i < n ; i++ ) {
  printf("%d ",a[i]);
  }
  free( a );
 
  return(0);
  }
