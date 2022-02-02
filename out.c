/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:14:03 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 12:14:03 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	out(t_data *data)
{
	t_img	img;

	if (data->n_collect == 0)
	{
		data->opdoor = mlx_xpm_file_to_image(data->mlx, "./XPM/OpenDoor.xpm",
				&(img.width), &(img.height));
		mlx_put_image_to_window(data->mlx, data->win, data->opdoor,
			data->xdoor, data->ydoor);
	}
	if (data->check == -1)
	{
		printf("You Lose!\n");
		exit(0);
	}
}
