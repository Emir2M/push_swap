/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:49:58 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/23 18:58:33 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static size_t	count_words(const char *str, char c)
{
	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while (*str != '\0')
	{
		if (*str != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*str == c)
		{
			word = 0;
		}
		str++;
	}
	return (count);
}
static char    *get_word(const char *s, size_t len)
    {                                                                                                                                         
        char    *word;                                                                                                                               
        size_t    i;                                                                                                                                 
  
        word = (char *)malloc((len + 1) * sizeof(char));
        if (!word)
            return (NULL);                                                                                                                           
        i = 0;                                                                                                                                   
        while (i < len)
        {                                                                                                                                        
            word[i] = s[i];                                                                                                                          
            i++;                                                                                                                                     
        }
        word[i] = '\0';
        return (word);
    }
static void	*free_all(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static char	**fill_words(char **new, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		len = 0;
		while (s[len] != '\0' && s[len] != c)
			len++;
		new[i] = get_word(s,len);
		if (!new[i])
			return (free_all(new, i));
		i++;
		s += len;
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	return (fill_words(new, s, c));
}
