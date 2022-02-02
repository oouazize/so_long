/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:24:48 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 12:24:48 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display1(t_img *img, t_data *data, int i, int j)
{
	if (data->str[i][j] == '1')
	{	
		data->ptr = mlx_xpm_file_to_image(data->mlx, "./XPM/wall.xpm",
				&(img->width), &(img->height));
		mlx_put_image_to_window(data->mlx, data->win, data->ptr,
			data->h, data->w);
	}
	if (data->str[i][j] == 'E')
	{
		data->xdoor = data->h;
		data->ydoor = data->w;
		data->door = mlx_xpm_file_to_image(data->mlx, "./XPM/Door.xpm",
				&(img->width), &(img->height));
		mlx_put_image_to_window(data->mlx, data->win, data->door,
			data->h, data->w);
	}
	if (data->str[i][j] == '0')
	{
		data->green = mlx_xpm_file_to_image(data->mlx, "./XPM/Green.xpm",
				&(img->width), &(img->height));
		mlx_put_image_to_window(data->mlx, data->win, data->green,
			data->h, data->w);
	}
}
