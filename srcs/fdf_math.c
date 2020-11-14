/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:44:47 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 15:35:17 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_math(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map_y)
	{
		x = 0;
		while (x < fdf->map_x)
		{
			if (x < fdf->map_x - 1)
			{
                fdf_math_x(fdf, x, y);
			}
			if (y < fdf->map_y - 1)
			{
				fdf_math_y(fdf, x, y);
			}
			x++;
		}
		y++;
	}
}

void    fdf_math_x(t_fdf *fdf, int x, int y)
{
	fdf->bres->x1 = x;
	fdf->bres->y1 = y;
	fdf->bres->x2 = x + 1;
	fdf->bres->y2 = y;
	fdf_math_parallel(fdf);
 	fdf->bres->x1 = x;
	fdf->bres->y1 = y;
	fdf->bres->x2 = x + 1;
	fdf->bres->y2 = y;
    fdf_math_iso(fdf);
}

void    fdf_math_y(t_fdf *fdf, int x, int y)
{
	fdf->bres->x1 = x;
	fdf->bres->y1 = y;
	fdf->bres->x2 = x;
	fdf->bres->y2 = y + 1;
	fdf_math_parallel(fdf);
	fdf->bres->x1 = x;
	fdf->bres->y1 = y;
	fdf->bres->x2 = x;
	fdf->bres->y2 = y + 1;
	fdf_math_iso(fdf);
}
