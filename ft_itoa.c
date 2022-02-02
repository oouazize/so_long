/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:46:23 by oouazize          #+#    #+#             */
/*   Updated: 2022/01/31 15:46:23 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_min_n(char *str, int len, int n)
{
	unsigned int	min_n;

	min_n = n;
	min_n *= -1;
	str[0] = '-';
	while (min_n)
	{
		str[len--] = (min_n % 10) + 48;
		min_n /= 10;
	}
	return (*str);
}

char	n_positive(char	*str, int len, int n)
{
	if (n == 0)
		str[len] = n + 48;
	if (n == -2147483648)
	{
		ft_min_n(str, len, n);
		return (*str);
	}
	else if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n)
	{
		str[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (*str);
}

char	*ft_itoa(t_data *data)
{
	int		i;
	int		n_len;
	int		len;
	int		n;

	n = data->count;
	i = 0;
	len = 0;
	n_len = n;
	while (n_len)
	{
		n_len /= 10;
		len++;
	}
	if (n == 0)
		len++;
	if (n < 0)
		len += 1;
	data->ito = (char *)malloc((len + 1) * sizeof(char));
	if (!data->ito)
		return (0);
	data->ito[len--] = '\0';
	n_positive(data->ito, len, n);
	return (data->ito);
}
