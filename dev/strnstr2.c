#include <stdio.h>
// NAME
//      strstr, strcasestr, strnstr -- locate a substring in a string
// LIBRARY
//      Standard C Library (libc, -lc)
// SYNOPSIS
//      #include <string.h>
//      char *
//      strnstr(const char *haystack, const char *needle, size_t len);

//      #include <string.h>

// DESCRIPTION

//      The strnstr() function locates the first occurrence of the null-terminated string needle in the string haystack, 
//      where not more than len characters are searched.  
//      Characters that appear after a `\0' character are not searched.  Since the strnstr() function
//      is a FreeBSD specific API, it should only be used when portability is not a concern.

// RETURN VALUES
//      If needle is an empty string, haystack is returned; 
//      if needle occurs nowhere in haystack, NULL is returned; 
//      otherwise a pointer to the first character of the first occurrence of needle is returned.

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    if(!*needle)
        return ((char *)haystack);
    while (haystack[i] != '\0')
    {
        j = 0;
        printf("@@@ %c\n", haystack[i]);
        while (haystack[i + j] == needle[j] &&  (i + j) < len)
        {
            if(needle[j+1] == '\0' )
                return ((char *)(&haystack[i]));
                   printf("result %s\n", ft_strnstr("Hello","lo",5));
            j++;
        }
        i++;
    }
    return(0);
}

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	h;
// 	size_t	n;

// 	h = 0;
// 	if (needle[0] == '\0')
// 		return ((char *)haystack);
// 	while (haystack[h] != '\0')
// 	{
// 		n = 0;
// 		while (haystack[h + n] == needle[n] && (h + n) < len)
// 		{
// 			if (haystack[h + n] == '\0' && needle[n] == '\0')
//             {
//                 printf("Hi");
// 				return ((char *)&haystack[h]);
//             }
// 			n++;
// 		}
// 		if (needle[n] == '\0')
// 			return ((char *)haystack + h);
// 		h++;
// 	}
// 	return (0);
// }

int main (void)
{
    printf("result %s\n", ft_strnstr("Hello","el",3));
    printf("result %s\n", ft_strnstr("Hello","lo",5));
    printf("result %s\n", ft_strnstr("Hello","lox",6));   
}

//|| (haystack[i+j] == '\0' && needle[j] == '\0')