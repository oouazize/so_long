/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:50:51 by oouazize          #+#    #+#             */
/*   Updated: 2022/02/02 11:55:27 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalidpath(int fd, char *arv)
{
	if (fd < 0 || ft_strstr(arv, ".ber") == 0)
	{
		printf("Invalid Path!");
		exit (0);
	}		
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2, t_data *data)
{
	int		i;
	int		j;
	int		len;
	int		len1;

	i = -1;
	j = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	len1 = ft_strlen(s2);
	data->string = (char *)malloc((len + len1 + 1) * sizeof(char));
	if (data->string == NULL)
		return (0);
	while (s1[++i])
		data->string[i] = s1[i];
	while (s2[j])
		data->string[i++] = s2[j++];
	data->string[i] = '\0';
	return (data->string);
}

char	*ft_strdup(const char *s1, t_data *data)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	while (s1[l])
		l++;
	data->s2 = (char *)malloc(l + 1 * sizeof(char));
	if (data->s2 == NULL)
		return (0);
	while (s1[j])
		data->s2[i++] = s1[j++];
	data->s2[i] = '\0';
	return (data->s2);
}

char	**get_map(char *arv, t_data *data)
{
	int		fd;
	int		ret;
	int		check;
	char	**spl;
	char	*save;

	fd = open(arv, O_RDONLY);
	invalidpath(fd, arv);
	save = ft_strdup("", data);
	data->buff = (char *)malloc(sizeof(char) * 1000001);
	if (data->buff == NULL)
		return (0);
	ret = read(fd, data->buff, 1000000);
	if (ret == -1)
		return (0);
	save = ft_strjoin(save, data->buff, data);
	spl = ft_split(save, '\n', data);
	check = check_map(spl);
	if (check)
	{
		printf("Hint: The map is invalid!\n");
		exit (0);
	}
	return (spl);
}
