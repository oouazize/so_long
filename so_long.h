/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:19:56 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/02 11:46:20 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void		*win;
	void		*mlx;
	char		**str;
	void		*ptr;
	void		*collect;
	void		*play;
	void		*door;
	void		*opdoor;
	void		*green;
	void		*monster;
	void		*image;
	void		*image1;
	void		*heart;
	int			check;
	int			count;
	int			n_collect;
	int			xdoor;
	int			ydoor;
	char		*buff;
	char		**tab;
	char		*s2;
	char		*string;
	char		*ito;
	int			i;
	int			j;
	int			x;
	int			y;
	int			h;
	int			w;
	int			hy;
	int			wi;
}				t_data;

char	**get_map(char *arv, t_data *data);
char	**ft_split(char const *s, char c, t_data *data);
int		ft_len(char **str);
int		ft_len2(char **str);
void	event_up(t_data *data);
void	event_down(t_data *data);
void	event_left(t_data *data);
void	event_right(t_data *data);
void	out(t_data *data);
void	init_win(int arc, char *arv, t_data *data, t_img *img);
void	display1(t_img *img, t_data *data, int i, int j);
void	display2(t_img *img, t_data *data, int i, int j);
int		check_map(char **str);
char	*ft_itoa(t_data *data);
void	check_char(char **str, int i, int j, int p);
int		ft_strstr(char *str, char	*to_find);

#endif