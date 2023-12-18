/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:36:33 by pudry             #+#    #+#             */
/*   Updated: 2023/12/18 18:07:05 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// Attention a bien generer l image avant.
void	ft_put_square(t_data *data, int x, int y, int icolor)
{
	int	i;
	int	ix;
	int	j;
	int	iy;

	i = (x * MAP_SIZE);
	j = (y * MAP_SIZE);
	iy = j;
	printf("i : %i, j : %i\n", i, j);
	while (iy - j < MAP_SIZE)
	{
		ix = i;
		while (ix - i < MAP_SIZE)
			put_pixel_img(data, ix ++, iy, icolor);
		iy ++;
	}
}

void	ft_new_img(t_data *data)
{
	t_pixput	*img;

	img = &data->img;
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_pp, \
				&img->line_len, &img->endian);
}

void	put_pixel_img(t_data *data, int x, int y, int icolor)
{
	char		*dst;
	t_pixput	*img;

	img =&data->img;
	dst = img->addr + (y * img->line_len + x * (img->bit_pp / 8));
	*(unsigned int*)dst = icolor;
}
