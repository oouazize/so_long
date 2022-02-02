/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:16:41 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 15:44:48 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid(void)
{
	printf("Hint: The map is invalid! (Characters)\n");
	exit (0);
}

void	check2(char **str, int i, int j)
{
	int	p;
	int	e;
	int	c;
	int	w;

	e = 0;
	c = 0;
	w = 0;
	p = 0;
	if (str[i][j] != 'P' && str[i][j] != 'E' && str[i][j] != 'W'
			&& str[i][j] != 'C' && str[i][j] != '1' && str[i][j] != '0')
		invalid();
}

void	check_char(char **str, int i, int j, int p)
{
	int	e;
	int	c;
	int	w;

	e = 0;
	c = 0;
	w = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			check2(str, i, j);
			if (str[i][j] == 'P')
				p++;
			if (str[i][j] == 'E')
				e++;
			if (str[i][j] == 'C')
				c++;
			if (str[i][j] == 'W')
				w++;
		}
	}
	if (p != 1 || e != 1 || c < 1 || w < 1)
		invalid();
}
