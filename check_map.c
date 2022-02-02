/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:21:59 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 14:03:24 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalidmap(int i)
{
	if (i == 1)
		printf("Empty Map!\n");
	else
		printf("Invalid Map!\n");
	exit (0);
}

int	square(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i][j])
		j++;
	while (str[i])
		i++;
	return (i * j);
}

int	count(char **str, int i, int j)
{
	int	c;

	c = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] != '1')
			invalidmap(0);
		while (str[i][j])
		{
			j++;
			c++;
		}
		if (str[i][j - 1] != '1')
			invalidmap(0);
		i++;
	}
	return (c);
}

void	last_line(char **str, int i, int j)
{
	while (str[i - 1][j])
	{
		if (str[i - 1][j] != '1')
			invalidmap(0);
		j++;
	}
}

int	check_map(char **str)
{
	int	c;
	int	j;
	int	i;
	int	check;

	i = 0;
	j = 0;
	if (!(*str))
		invalidmap(1);
	while (str[i][j])
	{
		if (str[i][j] != '1')
			invalidmap(0);
		j++;
	}
	c = count(str, i, j);
	while (str[i])
		i++;
	last_line(str, i, 0);
	check_char(str, -1, -1, 0);
	check = square(str);
	if (check != c)
		return (1);
	return (0);
}
