/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:46:34 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 15:46:36 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_counter(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_word(s, c);
		s += i;
		if (i > 0)
			word++;
	}
	return (word);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

char	**ft_split(char const *s, char c, t_data *data)
{
	int		string;
	int		count;
	int		len;

	if (!s)
		return (0);
	string = ft_counter(s, c);
	data->tab = (char **)malloc((string + 1) * sizeof(char *));
	if (data->tab == NULL)
		return (0);
	count = -1;
	while (++count < string)
	{
		while (*s && *s == c)
			s++;
		len = ft_word(s, c);
		data->tab[count] = (char *)malloc((len + 1) * sizeof(char));
		if (data->tab[count] == NULL)
			return (0);
		ft_strlcpy(data->tab[count], s, len + 1);
		s += len;
	}
	data->tab[string] = 0;
	return (data->tab);
}
