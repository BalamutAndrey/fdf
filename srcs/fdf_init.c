/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:51:40 by eboris            #+#    #+#             */
/*   Updated: 2020/11/11 15:51:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fdf_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		fdf_error(fdf, "fdf: mlx initialization error\n");
	fdf->win = mlx_new_window(fdf->mlx, SIZE_X, SIZE_Y, "FDF");
	if (fdf->win == NULL)
		fdf_error(fdf, "fdf: win initialization error\n");
	fdf->img = mlx_new_image(fdf->mlx, SIZE_X, SIZE_Y);
	if (fdf->img == NULL)
		fdf_error(fdf, "fdf: img initialization error\n");
	mlx_key_hook(fdf->win, fdf_keyboard(fdf), NULL);
}
