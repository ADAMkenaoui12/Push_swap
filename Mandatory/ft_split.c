/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:18:23 by kadam             #+#    #+#             */
/*   Updated: 2024/04/21 19:14:00 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	num_word;

	i = 0;
	num_word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			num_word++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (num_word);
}

static int	chack_len_word(char const *s, char c)
{
	int	i;
	int	len_word;

	i = 0;
	len_word = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len_word++;
	}
	return (len_word);
}

void	get_free(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	result = NULL;
}

static char	**cut_split(const char *s, char c, int j, char **dest)
{
	int	i;
	int	index;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			dest[j] = malloc(chack_len_word(s + i, c) + 1);
			if (dest[j] == NULL)
			{
				get_free(dest);
				return (NULL);
			}
			index = 0;
			while (s[i] != '\0' && s[i] != c)
				dest[j][index++] = s[i++];
			dest[j][index] = '\0';
			j++;
		}
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**dest;

	if (s == NULL)
		return (NULL);
	j = 0;
	dest = (char **)malloc((count_word(s, c) + 1) * (sizeof(char *)));
	if (dest == NULL)
		return (NULL);
	if (cut_split(s, c, j, dest) == NULL)
		return (NULL);
	return (dest);
}
