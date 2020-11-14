/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:24:22 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 15:53:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_math_iso(t_fdf *fdf)
{
	t_color	color;

	fdf->bres->z1 = fdf->map[(int)fdf->bres->y1][(int)fdf->bres->x1];
	fdf->bres->z2 = fdf->map[(int)fdf->bres->y2][(int)fdf->bres->x2];
	fdf->bres->z1 = fdf->bres->z1 * (fdf->zoom);
	fdf->bres->z2 = fdf->bres->z2 * (fdf->zoom);
	if ((fdf->bres->z1 != 0) || (fdf->bres->z2 != 0))
		color = (t_color){200, 50, 50, 0};
	else
		color = (t_color){255, 255, 255, 0};
	fdf->bres->x1 = fdf->bres->x1 * fdf->zoom;
	fdf->bres->y1 = fdf->bres->y1 * fdf->zoom;
	fdf->bres->x2 = fdf->bres->x2 * fdf->zoom;
	fdf->bres->y2 = fdf->bres->y2 * fdf->zoom;
	fdf->bres->x1 -= ((fdf->map_x - 1) * fdf->zoom) / 2;
	fdf->bres->y1 -= ((fdf->map_y - 1) * fdf->zoom) / 2;
	fdf->bres->x2 -= ((fdf->map_x - 1) * fdf->zoom) / 2;
	fdf->bres->y2 -= ((fdf->map_y - 1) * fdf->zoom) / 2;
	fdf_math_iso_rotate(fdf);
	fdf_math_iso_write(fdf, color);
}

void	fdf_math_iso_rotate(t_fdf *fdf)
{
	fdf_rotate_z(&fdf->bres->x1, &fdf->bres->y1, 0.523599);
	fdf_rotate_x(&fdf->bres->y1, &fdf->bres->z1, -0.723599);
	fdf_rotate_y(&fdf->bres->x1, &fdf->bres->z1, 0.223599);
	fdf_rotate_z(&fdf->bres->x2, &fdf->bres->y2, 0.523599);
	fdf_rotate_x(&fdf->bres->y2, &fdf->bres->z2, -0.723599);
	fdf_rotate_y(&fdf->bres->x2, &fdf->bres->z2, 0.223599);
	fdf->bres->x1 += (SIZE_X) / 2;
	fdf->bres->y1 += (SIZE_Y + fdf->map_y / fdf->zoom) / 2;
	fdf->bres->x2 += (SIZE_X) / 2;
	fdf->bres->y2 += (SIZE_Y + fdf->map_y / fdf->zoom) / 2;
}

void	fdf_math_iso_write(t_fdf *fdf, t_color color)
{
	double	delta_x;
	double	delta_y;
	double	sign_x;
	double	sign_y;
	int		error[2];

	delta_x = abs(fdf->bres->x2 - fdf->bres->x1);
	delta_y = abs(fdf->bres->y2 - fdf->bres->y1);
	fdf_math_iso_write_sign(fdf, &sign_x, &sign_y);
	error[0] = delta_x - delta_y;
	while ((int)fdf->bres->x1 != (int)fdf->bres->x2 ||
		(int)fdf->bres->y1 != (int)fdf->bres->y2)
	{
		fdf_put_pixel_iso(fdf, fdf->bres->x1, fdf->bres->y1, color);
		if ((error[1] = error[0] * 2) > -delta_y)
		{
			error[0] -= delta_y;
			fdf->bres->x1 += sign_x;
		}
		if (error[1] < delta_x)
		{
			error[0] += delta_x;
			fdf->bres->y1 += sign_y;
		}
	}
}

void	fdf_math_iso_write_sign(t_fdf *fdf, double *sign_x, double *sign_y)
{
	if (fdf->bres->x1 < fdf->bres->x2)
	{
		*sign_x = 1;
	}
	else
	{
		*sign_x = -1;
	}
	if (fdf->bres->y1 < fdf->bres->y2)
	{
		*sign_y = 1;
	}
	else
	{
		*sign_y = -1;
	}
}

void	fdf_put_pixel_iso(t_fdf *fdf, int x, int y, t_color color)
{
	int			i;

	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
	{
		i = (x * fdf->bit / 8) + (y * fdf->size);
		fdf->data_iso[i] = color.red;
		fdf->data_iso[++i] = color.green;
		fdf->data_iso[++i] = color.blue;
		fdf->data_iso[++i] = color.alpha;
	}
}
