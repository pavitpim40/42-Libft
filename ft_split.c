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
    while(k < len)
    {
        if(s[i] == c)
            i++;
        while (s[i] != c && s[i] != '\0')
            j++;
        word = ft_calloc(j - i + 1,sizeof(char));
        if(word == NULL)
            break;
        j = 0;
        while(s[i] != c && s[i] != '\0')
            word[j++] = s[i++];
        array_word[k] = word;
        k++;
    }
    if (k != len)
    {  
        len -= 1;
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
    
    len = 0;
    end_word = 0;
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
    if (s[0] == c)
        len--;
    if (s[ft_strlen(s) - 1] == c)
        len--;
    return (len + 1);
}

char    **ft_split(char const *s, char c)
{
    size_t  num_word;
    char    **array_word;

    num_word = count_word(s, c);
    array_word = malloc(num_word * sizeof(char *));
    if (array_word == NULL)
        return (NULL);
    array_word[num_word] = NULL;
    if (write_word(array_word, s, c, num_word) == 1)
        return (NULL);
  
    return (array_word);
}