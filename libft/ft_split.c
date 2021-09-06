/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:20:09 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 14:58:12 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_letters(char *str, char *charset, int i)
{
	int	u;

	u = 0;
	while (!(ft_is_charset(str[i], charset)) && str[i])
	{
		u++;
		i++;
	}
	return (u);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	j;
	int	u;

	u = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		j = ft_count_letters(str, charset, i);
		if (j > 0)
			u++;
		i = i + j;
	}
	return (u);
}

void	ft_fill_tab(char *str, char *charset, char **tab, int word)
{
	int	i;
	int	j;
	int	n;
	int	u;

	j = 0;
	i = 0;
	while (i < word)
	{
		while (ft_is_charset(str[j], charset))
			j++;
		n = ft_count_letters(str, charset, j);
		tab[i] = (char *)malloc(sizeof(char) * (n + 1));
		if (!tab[i])
			return ;
		u = 0;
		while (u < n)
		{
			tab[i][u] = str[j];
			j++;
			u++;
		}
		tab[i][u] = '\0';
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		word;
	char	**tab;

	if (*str == '\0')
	{
		tab = NULL;
		return (NULL);
	}
	word = ft_count_word(str, charset);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	ft_fill_tab(str, charset, tab, word);
	tab[word] = 0;
	return (tab);
}
