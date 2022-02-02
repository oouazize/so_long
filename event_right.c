/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:40:03 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 12:40:03 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lines3(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->green, data->hy, data->wi);
	data->hy += 37;
	mlx_put_image_to_window(data->mlx, data->win,
		data->play, data->hy, data->wi);
	data->str[data->x][data->y] = '0';
	data->y++;
	data->str[data->x][data->y] = 'P';
	data->count++;
	mlx_string_put(data->mlx, data->win, ft_len(data->str) * 50 / 34 + 70, 15,
		0x00FFFFFF, ft_itoa(data));
	free(data->ito);
}

void	event_right(t_data *data)
{
	mlx_string_put(data->mlx, data->win, ft_len(data->str) * 50 / 34 + 70, 15,
		0x00000000, ft_itoa(data));
	free(data->ito);
	if (data->n_collect == 0 && data->str[data->x][data->y + 1] == 'E')
	{
		printf("You Win!\n");
		exit (0);
	}
	if (data->str[data->x][data->y + 1] != '1'
		&& data->str[data->x][data->y + 1] != 'E')
	{
		if (data->str[data->x][data->y + 1] != 'W')
			lines3(data);
		else
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->green, data->hy, data->wi);
			data->check = -1;
		}
	}
}
