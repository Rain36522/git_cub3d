/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:36:33 by pudry             #+#    #+#             */
/*   Updated: 2023/12/15 18:30:48 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

double	ft_calc_depl_x(int iangl)
{
	int		icadran;
	double	imv;

	if (iangl == 0 || iangl == 180)
		return (0);
	else if (iangl == 90)
		return (DEPLACEMENT);
	else if (iangl == 270)
		return (DEPLACEMENT * -1);
	icadran  = 0;
	if (iangl > 90 && iangl < 180)
		icadran = 1;
	else if (iangl > 180 && iangl < 270)
		icadran = 2;
	else if (iangl > 270)
		icadran = 3;
	iangl = iangl - (90 * icadran);
	if (icadran == 2 || icadran  == 3)
		imv = cos((double)iangl) * DEPLACEMENT;
	else
		imv = sin((double)iangl) * DEPLACEMENT;
	if (icadran > 1)
		return (imv * -1);
	return (imv);
}

double	ft_calc_depl_y(int iangl)
{
	int		icadran;
	double	imv;

	if (iangl == 180)
		return (DEPLACEMENT);
	DEBUG
	if (iangl == 0)
		return (DEPLACEMENT * -1);
	else if (iangl == 90 || iangl == 270)
		return (0);
	icadran  = 0;
	if (iangl > 90 && iangl < 180)
		icadran = 1;
	else if (iangl > 180 && iangl < 270)
		icadran = 2;
	else if (iangl > 270)
		icadran = 3;
	iangl = iangl - (90 * icadran);
	if (icadran == 2 || icadran  == 0)
		imv = cos((double)iangl) * DEPLACEMENT;
	else
		imv = sin((double)iangl) * DEPLACEMENT;
	if (icadran == 1 || icadran == 2)
		return (imv * -1);
	return (imv);
}

int	ft_calcul_ang(int iangl, int iofset)
{
	iangl += iofset;
	if (iangl < 0)
		return (360 - (iangl * -1));
	else if (iangl > 360)
		return (iangl - 360);
	return (iangl);
}