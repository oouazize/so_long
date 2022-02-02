/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:55:48 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 12:55:48 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char **str)
{
	int	j;

	j = 0;
	while (str[0][j])
		j++;
	return (j);
}

int	ft_len2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put(t_data *data, t_img *img)
{
	mlx_string_put(data->mlx, data->win, ft_len(data->str) * 50 / 34, 15,
		0x00FFFFFF, "Move :");
	data->image = mlx_xpm_file_to_image(data->mlx, "./XPM/image.xpm",
			&(img->width), &(img->height));
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		ft_len(data->str) * 50 / 2.6, 0);
	data->image1 = mlx_xpm_file_to_image(data->mlx, "./XPM/image1.xpm",
			&(img->width), &(img->height));
	mlx_put_image_to_window(data->mlx, data->win, data->image1,
		ft_len(data->str) * 50 / 3.4, 0);
	data->heart = mlx_xpm_file_to_image(data->mlx, "./XPM/heart.xpm",
			&(img->width), &(img->height));
	mlx_put_image_to_window(data->mlx, data->win, data->heart,
		ft_len(data->str) * 50 / 9, 0);
	mlx_string_put(data->mlx, data->win, ft_len(data->str) * 50 / 7, 15,
		0x00FFFFFF, "1");
}

void	init_win(int arc, char *arv, t_data *data, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (arc != 2)
	{
		printf("Hint: Only 2 arguments");
		exit (0);
	}
	data->mlx = mlx_init();
	data->str = get_map(arv, data);
	data->win = mlx_new_window(data->mlx, ft_len(data->str) * 37,
			ft_len2(data->str) * 50 + 50, "Knight Game");
	put(data, img);
}
