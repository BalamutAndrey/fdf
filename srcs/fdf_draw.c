/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:59:26 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 15:32:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_iso, 0, 0);

//	fdf_draw_1(fdf);
//	fdf_bresenham(fdf);
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
