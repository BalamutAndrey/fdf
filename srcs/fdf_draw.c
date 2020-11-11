/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:59:26 by eboris            #+#    #+#             */
/*   Updated: 2020/11/11 17:45:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw(t_fdf *fdf)
{
	fdf->bres = fdf_memalloc(fdf, sizeof(t_bres));

	fdf_draw_1(fdf);
//	fdf_bresenham(fdf);
}

void	fdf_draw_1(t_fdf *fdf)
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
				fdf->bres->x1 = x;
				fdf->bres->y1 = y;
				fdf->bres->x2 = x + 1;
				fdf->bres->y2 = y;
				fdf_bresenham(fdf);
			}
			if (y < fdf->map_y - 1)
			{
				fdf->bres->x1 = x;
				fdf->bres->y1 = y;
				fdf->bres->x2 = x;
				fdf->bres->y2 = y + 1;
				fdf_bresenham(fdf);
			}
			x++;
		}
		y++;
	}
}

void	fdf_bresenham(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;
	int		color;

	fdf->bres->z1 = fdf->map[(int)fdf->bres->y1][(int)fdf->bres->x1];
	fdf->bres->z2 = fdf->map[(int)fdf->bres->y2][(int)fdf->bres->x2];
	if (fdf->bres->z1 > 0)
		color = RED;
	else
		color = WHITE;
	fdf->bres->x1 = fdf->bres->x1 * ZOOM;
	fdf->bres->y1 = fdf->bres->y1 * ZOOM;
	fdf->bres->x2 = fdf->bres->x2 * ZOOM;
	fdf->bres->y2 = fdf->bres->y2 * ZOOM;
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
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->bres->x1, fdf->bres->y1, color);
		fdf->bres->x1 = fdf->bres->x1 + x_step;
		fdf->bres->y1 = fdf->bres->y1 + y_step;
	}
}

// Delete me!!!

void    temp_map(t_fdf *fdf)
{
	(void)fdf;
	char	*line;
	int		fd;

	char	**temp;

	int		i = 0;
	int		z;

	line = malloc(sizeof(char) * 57);
	fd = open("/Users/eboris/work/fdf/maps/42.fdf", O_RDONLY);
	while (i < 11)
	{
		get_next_line(fd, &line);
		temp = ft_strsplit(line, ' ');
		z = 0;
		while (z < 19)
		{
			fdf->map[i][z] = ft_atoi(temp[z]);
			z++;
		}
		free(line);
		z = 0;
		while (z < 19)
		{
			free(temp[z]);
			z++;
		}
		free(temp);
		i++;
	}
	fdf->map_x = 19;
	fdf->map_y = 11;
}
