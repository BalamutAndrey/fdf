/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:19:59 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 16:10:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		fdf_error(NULL, "fdf: Usage: ./fdf mapfile\n");
	fdf = fdf_create_fdf();
	fdf_readmap(fdf, argv[1]);
	fdf->zoom = fminf((SIZE_X) / fdf->map_x / 2, SIZE_Y / fdf->map_y / 2);
	fdf_init(fdf);
	fdf_math(fdf);
	fdf_draw(fdf);
	mlx_hook(fdf->win, 2, (1L << 1), fdf_keyboard, fdf);
	mlx_hook(fdf->win, 17, 1, fdf_close, fdf);
	mlx_loop(fdf->mlx);
	fdf_exit(fdf);
	return (0);
}

int		fdf_close(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf_exit(fdf);
	return (0);
}

void	fdf_exit(t_fdf *fdf)
{
	if (fdf)
		fdf_remove_fdf(&fdf);
	exit(0);
}
