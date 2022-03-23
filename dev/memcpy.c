
// PROTOTYPE 
//void * memcpy(void *restrict dst, const void *restrict src, size_t n);

#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dst,const void *src, size_t n)
{
    int i;
    
    i = 0;
    printf("%s\n", (unsigned char *)(src));
    while (i < n)
    {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        printf("%d:%c\n",i,*(unsigned char *)(src + i));
        i ++;
    }
    return (dst);
}

// int main (void)
// {
//  char str1[] = "Geeks"; 
//   char str2[] = "Quiz"; 
 
//   puts("str1 before memcpy ");
//   puts(str1);
 
//   /* Copies contents of str2 to str1 */
//   ft_memcpy (str1, str2, sizeof(str2));
 
//   puts("\nstr1 after memcpy ");
//   puts(str1);
 
//   return 0;   
// }

int main()
{
    char str[100] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string :%s\n ", str);
      
    // when overlap happens then it just ignore it
    ft_memcpy(first + 8, first, 10);
    printf("memcpy overlap : %s\n ", str);
  
    // when overlap it start from first position
    memmove(second + 8, first, 10);
    printf("memmove overlap : %s\n ", str);
  
    return 0;
}