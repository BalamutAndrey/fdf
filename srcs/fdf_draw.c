/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:59:26 by eboris            #+#    #+#             */
/*   Updated: 2020/11/13 21:19:01 by eboris           ###   ########.fr       */
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
				fdf_bresenham_iso(fdf);
			}
			if (y < fdf->map_y - 1)
			{
				fdf->bres->x1 = x;
				fdf->bres->y1 = y;
				fdf->bres->x2 = x;
				fdf->bres->y2 = y + 1;
				fdf_bresenham_iso(fdf);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_iso, 0, 0);
}

void	fdf_isometria(double *x, double *y, int z)
{
	float	t_x;
	float	t_y;

	t_x = (float)*x;
	t_y = (float)*y;

	*x = (t_x - t_y) * cos(0.523599);
	*y = (t_x + t_y) * sin(0.523599) - z;
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

void	fdf_put_pixel(t_fdf *fdf, int x, int y, t_color color)
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

void	fdf_bresenham(t_fdf *fdf)
{
	double	x_step;
	double	y_step;
	int		max;
	t_color	color;

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
	fdf->bres->x1 = fdf->bres->x1 + ((SIZE_X / 2) - ((fdf->map_x  * fdf->zoom) / 2));
	fdf->bres->y1 = fdf->bres->y1 + ((SIZE_Y / 2) - ((fdf->map_y  * fdf->zoom) / 2));
	fdf->bres->x2 = fdf->bres->x2 + ((SIZE_X / 2) - ((fdf->map_x  * fdf->zoom) / 2));
	fdf->bres->y2 = fdf->bres->y2 + ((SIZE_Y / 2) - ((fdf->map_y  * fdf->zoom) / 2));
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
		fdf_put_pixel(fdf, fdf->bres->x1, fdf->bres->y1, color);
		fdf->bres->x1 = fdf->bres->x1 + x_step;
		fdf->bres->y1 = fdf->bres->y1 + y_step;
	}
}

void			rotate_x(int *y, int *z, double alpha)
{
	int			previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void			rotate_y(int *x, int *z, double beta)
{
	int			previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void			rotate_z(int *x, int *y, double gamma)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}


void	fdf_bresenham_iso(t_fdf *fdf)
{
	double	x_step;
	double	y_step;
	int		max;
	t_color	color;

	fdf->bres->z1 = fdf->map[(int)fdf->bres->y1][(int)fdf->bres->x1];
	fdf->bres->z2 = fdf->map[(int)fdf->bres->y2][(int)fdf->bres->x2];

	fdf->bres->z1 = fdf->bres->z1 * (fdf->zoom);
	fdf->bres->z2 = fdf->bres->z2 * (fdf->zoom);
	if ((fdf->bres->z1 != 0) || (fdf->bres->z2 != 0))
		color = (t_color){0, 0, 255, 0};
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

	rotate_z(&fdf->bres->x1, &fdf->bres->y1, 0.523599);
	rotate_x(&fdf->bres->y1, &fdf->bres->z1, -0.723599);
	// rotate_y(&fdf->bres->x1, &fdf->bres->z1, 0.523599);

	rotate_z(&fdf->bres->x2, &fdf->bres->y2, 0.523599);
	rotate_x(&fdf->bres->y2, &fdf->bres->z2, -0.723599);
	// rotate_y(&fdf->bres->x2, &fdf->bres->z2, 0.523599);


	// fdf_isometria(&fdf->bres->x1, &fdf->bres->y1, fdf->bres->z1);
	// fdf_isometria(&fdf->bres->x2, &fdf->bres->y2, fdf->bres->z2);

	fdf->bres->x1 += (SIZE_X) / 2;
	fdf->bres->y1 += (SIZE_Y + fdf->map_y / fdf->zoom) / 2;
	fdf->bres->x2 += (SIZE_X) / 2;
	fdf->bres->y2 += (SIZE_Y + fdf->map_y / fdf->zoom) / 2;


	// fdf->bres->x1 = fdf->bres->x1 + ((SIZE_X / 2) - ((fdf->map_x  * fdf->zoom) / 2));
	// fdf->bres->y1 = fdf->bres->y1 + ((SIZE_Y / 2) - ((fdf->map_y  * fdf->zoom) / 2));
	// fdf->bres->x2 = fdf->bres->x2 + ((SIZE_X / 2) - ((fdf->map_x  * fdf->zoom) / 2));
	// fdf->bres->y2 = fdf->bres->y2 + ((SIZE_Y / 2) - ((fdf->map_y  * fdf->zoom) / 2));

	double	delta_x;
	double	delta_y;
	double	sign_x;
	double	sign_y;
	int		error[2];

	delta_x = abs(fdf->bres->x2 - fdf->bres->x1);
	delta_y = abs(fdf->bres->y2 - fdf->bres->y1);
	sign_x = fdf->bres->x1 < fdf->bres->x2 ? 1 : -1;
	sign_y = fdf->bres->y1 < fdf->bres->y2 ? 1 : -1;
	error[0] = delta_x - delta_y;
	double i = fdf->zoom;
	while ((int)fdf->bres->x1 != (int)fdf->bres->x2 || (int)fdf->bres->y1 != (int)fdf->bres->y2)
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
	// if ((fdf->bres->x1 < fdf->bres->x2) || (fdf->bres->y1 < fdf->bres->y2))
	// {
	// 	double t;
	// 	t = fdf->bres->x1;
	// 	fdf->bres->x1 = fdf->bres->x2;
	// 	fdf->bres->x2 = t;
	// 	t = fdf->bres->y1;
	// 	fdf->bres->y1 = fdf->bres->y2;
	// 	fdf->bres->y2 = t;	
	// }
	// x_step = fdf->bres->x2 - fdf->bres->x1;
	// y_step = fdf->bres->y2 - fdf->bres->y1;
	// if (x_step > y_step)
	// 	max = fabs(x_step);
	// else
	// 	max = fabs(y_step);
	// x_step = x_step / max;
	// y_step = y_step / max;
	// while ((uint)(fdf->bres->x1 - fdf->bres->x2) ||
	// 		(uint)(fdf->bres->y1 - fdf->bres->y2))
	// {
	// 	fdf_put_pixel_iso(fdf, fdf->bres->x1, fdf->bres->y1, color);
	// 	fdf->bres->x1 = fdf->bres->x1 + x_step;
	// 	fdf->bres->y1 = fdf->bres->y1 + y_step;
	// }
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
