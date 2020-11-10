/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:19:59 by eboris            #+#    #+#             */
/*   Updated: 2020/11/10 17:41:17 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	ft_printf("%f", fabs(-5.11));

	mlx = mlx_init();
	win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "FDF");
	img = mlx_new_image(mlx, SIZE_X, SIZE_Y);

	mlx_pixel_put(mlx, win, 100, 100, 0xffffff);

	mlx_loop(mlx);
	return (0);
}