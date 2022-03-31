#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;

	//  if ((size_t)dst - (size_t)src < len)
	//  {
       
		i = len - 1;
		 printf("OVERLAP %lu\n", i);
		while (i < len)
		{
			// printf("hey : len %lu : idx :%lu : char : %c\n" , len,i,((char *)src)[i]);
			// printf("%c len : %lu\n", ((unsigned char *)src)[i], i);
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	//  }
	//  else
	//  {
    //      printf("NORMAL\n");
	//  	while (i < len)
	//  	{
	//  		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	//  		i++;
	//  	}
	//  }
	return (dst);
}

// int     main(void)
// {
// char csrc[100] = "Geeksfor";
// memmove(csrc+5, csrc, strlen(csrc)+1);
// printf("%s\n", csrc);

// char src[100] = "Geeksfor";
// char dst[9];
// ft_memmove(src+5, src, strlen(src)+1);
// printf("%s\n", src);
// return 0;
// }

// int main()
// {
//    char csrc[100] = "Geeksfor";
//    ft_memmove(csrc+5, csrc, strlen(csrc)+1);
//    printf("%s", csrc);
//    return 0;
// }

int main()
{
    char str[100] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string :%s\n ", str);
      
    // when overlap happens then it just ignore it
    ft_memmove(first, first+8, 10);
    printf("memmove overlap : %s\n ", str);
  
    // when overlap it start from first position
    // ft_memmove(second + 8, first, 10);
    // printf("memmove overlap : %s\n ", str);
  
    return 0;
}