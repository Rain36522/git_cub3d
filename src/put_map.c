/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:24:14 by pudry             #+#    #+#             */
/*   Updated: 2023/12/17 09:26:19 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

static void	put_player(t_data *data)
{
	double	i;
	double	j;
	double	x;
	double	y;

	x = data->xpos * MAP_SIZE;
	y = data->ypos * MAP_SIZE;

	j = y;
	while (j - y < PLAYER_SIZE)
	{
		i = x;
		while (i - x < PLAYER_SIZE)
			mlx_pixel_put(data->mlx, data->mlx_win, i ++, j, 0x00FF00FF);
		j ++;
	}
}

void	put_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			DEBUG
			if (data->map[i][j] == ' ')
				ft_put_square(data, j, i, 0x00000000);
			else if (data->map[i][j] == '1')
				ft_put_square(data, j, i, 0x00808080);
			else
				ft_put_square(data, j, i, 0x00FFFFFF);
			j ++;
			DEBUG
		}
		i ++;
	}
}

void	ft_make_moov(t_data *data, double x, double y)
{
	data->xpos = x;
	data->ypos = y;

	ft_raycasting(data);
	put_map(data);
	put_player(data);
}
