/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchouai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 20:18:32 by elchouai          #+#    #+#             */
/*   Updated: 2018/10/16 22:25:44 by elchouai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	int	word;
	int number_words;
	int i;

	word = 0;
	number_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && word == 0)
		{
			number_words++;
			word = 1;
		}
		else if (str[i] == c)
			word = 0;
		i++;
	}
	return (number_words);
}

static int		calculate_length(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char		*fill_array(char *tab, const char *str, int i, int length)
{
	tab = (char *)malloc((length + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab = ft_strncpy(tab, &str[i], length);
	tab[length] = '\0';
	return (tab);
}

static void		initialize(int *x, int *y, int *z)
{
	*x = 0;
	*y = 0;
	*z = 0;
}

char			**ft_strsplit(char const *str, char c)
{
	char	**array;
	int		word;
	int		i;
	int		g_n_words;

	if (!str || !c)
		return (NULL);
	if (!(array = (char **)malloc((count_words(str, c) + 1) * sizeof(char *))))
		return (0);
	initialize(&word, &i, &g_n_words);
	while (str[i] != '\0')
	{
		if ((str[i] != c) && word == 0)
		{
			word = 1;
			array[g_n_words] = fill_array(array[g_n_words], str, i, \
				calculate_length(&str[i], c));
			g_n_words++;
		}
		else if (str[i] == c)
			word = 0;
		i++;
	}
	array[g_n_words] = 0;
	return (array);
}
