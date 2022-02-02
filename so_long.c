/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:33:56 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/02 11:44:21 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	n_collect(t_data *data)
{
	int	i;
	int	j;

	data->n_collect = 0;
	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j])
		{
			if (data->str[i][j] == 'C')
				data->n_collect++;
			j++;
		}
		i++;
	}
}

int	handle_input(int keysym, t_data *data)
{
	n_collect(data);
	if (keysym == 53)
	{
		printf("Game Over\n");
		exit (0);
	}
	if (keysym == 2 || keysym == 124)
		event_right(data);
	else if (keysym == 0 || keysym == 123)
		event_left(data);
	else if (keysym == 1 || keysym == 125)
		event_down(data);
	else if (keysym == 13 || keysym == 126)
		event_up(data);
	out(data);
	return (0);
}

int	closed(void)
{
	printf("Game Over\n");
	exit (0);
}

void	intt(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx_hook(data->win, 17, 1L << 17, &closed, data);
	mlx_hook(data->win, 2, 1L << 0, &handle_input, data);
	data->w = 50;
}

int	main(int arc, char *arv[])
{
	t_img	img;
	t_data	data;
	int		i;
	int		j;

	i = 0;
	data.count = 0;
	init_win(arc, arv[1], &data, &img);
	intt(&data);
	while (data.str[i])
	{
		data.h = 0;
		j = 0;
		while (data.str[i][j])
		{
			display1(&img, &data, i, j);
			display2(&img, &data, i, j);
			data.h += 37;
			j++;
		}
		data.w += 50;
		i++;
	}
	mlx_loop(data.mlx);
}
