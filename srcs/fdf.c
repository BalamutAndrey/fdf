/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:19:59 by eboris            #+#    #+#             */
/*   Updated: 2020/11/11 15:12:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

//	ft_printf("%f", fabs(-5.11));
	if (argc != 2)
		fdf_error(NULL, "fdf: Usage: ./fdf mapfile\n");
	fdf = fdf_create_fdf();
	fdf_readmap(fdf, argv[1]);
	
//	temp_map(fdf);
//	fdf_init(fdf);

//	fdf_draw(fdf);

	//mlx_pixel_put(fdf->mlx, fdf->win, 100, 100, 0xffffff);

//	mlx_loop(fdf->mlx);
	return (0);
}

void	fdf_exit(t_fdf *fdf)
{
	if (fdf)
		fdf_remove_fdf(&fdf);
	exit(0);
}
