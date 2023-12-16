/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:13:02 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 17:55:22 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	put_player(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (int)(data->xpos * 70);
	y = (int)(data->ypos * 70);

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, data->xpos + j, data->ypos + i, 0x00FFFF00);
			j ++;
		}
		i ++;
	}
}

void	put_map(t_data *data)
{
	int	of_x;
	int	of_y;
	int	i;
	int	j;

	of_x = 1;
	of_y = 1;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1')
				ft_put_square(data, i + of_x, j + of_y, 0x00808080);
			else
				ft_put_square(data, i + of_x, j + of_y, 0x00303030);
			i ++;
		}
		j ++;
	}
}