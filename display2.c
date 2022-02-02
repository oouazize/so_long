/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:25:48 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 12:25:48 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display2(t_img *img, t_data *data, int i, int j)
{
	if (data->str[i][j] == 'C')
	{
		data->collect = mlx_xpm_file_to_image(data->mlx, "./XPM/Coin.xpm",
				&(img->width), &(img->height));
		mlx_put_image_to_window(data->mlx, data->win, data->collect,
			data->h, data->w);
	}
	if (data->str[i][j] == 'W')
	{
		data->monster = mlx_xpm_file_to_image(data->mlx, "./XPM/Enemie.xpm",
				&(img->width), &(img->height));
		mlx_put_image_to_window(data->mlx, data->win, data->monster,
			data->h, data->w);
	}
	if (data->str[i][j] == 'P')
	{
		data->x = i;
		data->y = j;
		data->hy = data->h;
		data->wi = data->w;
		data->play = mlx_xpm_file_to_image(data->mlx, "./XPM/Player.xpm",
				&(img->width), &(img->height));
		mlx_put_image_to_window(data->mlx, data->win, data->play,
			data->h, data->w);
	}
}
