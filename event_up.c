/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:49:30 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 12:49:30 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lines4(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->green, data->hy, data->wi);
	data->wi -= 50;
	mlx_put_image_to_window(data->mlx, data->win,
		data->play, data->hy, data->wi);
	data->str[data->x][data->y] = '0';
	data->x--;
	data->str[data->x][data->y] = 'P';
	data->count++;
	mlx_string_put(data->mlx, data->win, ft_len(data->str) * 50 / 34 + 70, 15,
		0x00FFFFFF, ft_itoa(data));
	free(data->ito);
}

void	event_up(t_data *data)
{
	mlx_string_put(data->mlx, data->win, ft_len(data->str) * 50 / 34 + 70, 15,
		0x00000000, ft_itoa(data));
	free(data->ito);
	if (data->n_collect == 0 && data->str[data->x - 1][data->y] == 'E')
	{
		printf("You Win!\n");
		exit(0);
	}
	if (data->str[data->x - 1][data->y] != '1'
		&& data->str[data->x - 1][data->y] != 'E')
	{
		if (data->str[data->x - 1][data->y] != 'W')
			lines4(data);
		else
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->green, data->hy, data->wi);
			data->check = -1;
		}
	}
}
