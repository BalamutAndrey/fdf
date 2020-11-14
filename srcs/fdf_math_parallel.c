/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_parallel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:04:03 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 15:47:35 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_math_parallel(t_fdf *fdf)
{
	t_color	color;
	int		t;

	fdf->bres->z1 = fdf->map[(int)fdf->bres->y1][(int)fdf->bres->x1];
	fdf->bres->z2 = fdf->map[(int)fdf->bres->y2][(int)fdf->bres->x2];
	fdf->bres->z1 = fdf->bres->z1 * fdf->zoom;
	fdf->bres->z2 = fdf->bres->z2 * fdf->zoom;
	if (fdf->bres->z1 > 0)
		color = (t_color){0, 0, 255, 0};
	else
		color = (t_color){255, 255, 255, 0};
	fdf->bres->x1 = fdf->bres->x1 * fdf->zoom;
	fdf->bres->y1 = fdf->bres->y1 * fdf->zoom;
	fdf->bres->x2 = fdf->bres->x2 * fdf->zoom;
	fdf->bres->y2 = fdf->bres->y2 * fdf->zoom;
	fdf->bres->x1 = fdf->bres->x1 + ((SIZE_X / 2) -
		((fdf->map_x * fdf->zoom) / 2));
	fdf->bres->y1 = fdf->bres->y1 + ((SIZE_Y / 2) -
		((fdf->map_y * fdf->zoom) / 2));
	fdf->bres->x2 = fdf->bres->x2 + ((SIZE_X / 2) -
		((fdf->map_x * fdf->zoom) / 2));
	fdf->bres->y2 = fdf->bres->y2 + ((SIZE_Y / 2) -
		((fdf->map_y * fdf->zoom) / 2));
	fdf_math_parallel_write(fdf, color);
}

void	fdf_math_parallel_write(t_fdf *fdf, t_color color)
{
	double	x_step;
	double	y_step;
	int		max;

	x_step = fdf->bres->x2 - fdf->bres->x1;
	y_step = fdf->bres->y2 - fdf->bres->y1;
	if (x_step > y_step)
		max = fabs(x_step);
	else
		max = fabs(y_step);
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(fdf->bres->x1 - fdf->bres->x2) ||
			(int)(fdf->bres->y1 - fdf->bres->y2))
	{
		fdf_put_pixel_paralel(fdf, fdf->bres->x1, fdf->bres->y1, color);
		fdf->bres->x1 = fdf->bres->x1 + x_step;
		fdf->bres->y1 = fdf->bres->y1 + y_step;
	}
}

void	fdf_put_pixel_paralel(t_fdf *fdf, int x, int y, t_color color)
{
	int			i;

	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
	{
		i = (x * fdf->bit / 8) + (y * fdf->size);
		fdf->data[i] = color.red;
		fdf->data[++i] = color.green;
		fdf->data[++i] = color.blue;
		fdf->data[++i] = color.alpha;
	}
}
