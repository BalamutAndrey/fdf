/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:59:26 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 16:40:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw(t_fdf *fdf)
{
	if (fdf->image == true)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_iso, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	fdf_change_image(t_fdf *fdf)
{
	if (fdf->image == true)
		fdf->image = false;
	else
		fdf->image = true;
	fdf_draw(fdf);
}
