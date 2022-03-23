#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:03:38 by ppimchan          #+#    #+#             */
/*   Updated: 2022/03/23 13:03:43 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static  int    write_word(char **array_word, char const *s, char c, size_t len)
{
    // if sucess return (0)
    // if fail return (1)
    size_t  i;  
    size_t  j; // each word index
    size_t  k; // string index 
    char    *word;

    i = 0;
    j = 0;
    k = 0;
    printf("in write_word\n");
    while(k < len)
    {
        if(s[i] == c){
            printf("split char here : %c with i = %lu\n", s[i],i);
            i++;
        }
            
        printf("in logic before i = %lu , j = %lu , k = %lu\n",i,j,k);
        j = i;       
        while (s[j] != c && s[j] != '\0')
        {
            printf("not split char : %c\n", s[i]);
            j++;
        }
            
           printf("in logic after i = %lu , j = %lu , k = %lu\n",i,j,k);    
        word = ft_calloc(j - i + 1,sizeof(char));
        if(word == NULL)
            break;
        j = 0;
        while(s[i] != c && s[i] != '\0')
            word[j++] = s[i++];
        array_word[k] = word;
        k++;
    }
    printf("k === %lu\n",k);
    if (k != len)
    {  
        len -= 1;
          printf("Free \n");
        while (len > 0)
        {
            free(array_word[len]);
            len--;
        }
        return (1);       
    }
    return (0);
}

static  int  count_word (char const *s, char c)
{
    size_t  len;
    size_t  end_word;
     printf("count_word\n");
    len = 0;
    end_word = 0;
    if(s[0] == c)
        s++;
    while (*s)
    {
        if (*s != c && end_word == 1)
        {
            len++;
            end_word = 0;
        }
        else if (*s == c && end_word == 0)
            end_word = 1;

        s++;
    }
    printf("NUM WORD BEFORE CALIBRATE %lu\n",len);
    if (s[ft_strlen(s)] == c)
        len--;
    return (len + 1);
}

char    **ft_split(char const *s, char c)
{
    size_t  num_word;
    char    **array_word;

    num_word = count_word(s, c);
    printf("num_word = %lu\n",num_word);
    array_word = malloc((num_word + 1) * sizeof(char *));
    if (array_word == NULL)
        return (NULL);
    printf("After Malloc\n");
    array_word[num_word] = NULL;
    printf("After Null terminate\n");
    if (write_word(array_word, s, c, num_word) == 1)
        return (NULL);
  
    return (array_word);
}

int main()
{
    char    **array_word;
    char    *string = "-XXXXXX-AAAAA-BBBBBB";
    array_word = ft_split(string,'-');
    for (int i = 0; i < 3; i++)
        printf("%s\n", array_word[i]);
    return (0);
}

