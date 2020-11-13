/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:19:59 by eboris            #+#    #+#             */
/*   Updated: 2020/11/12 15:21:05 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tmp_print_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < fdf->map_y)
	{
		while (j < fdf->map_x)
		{
			ft_printf("%2i ", fdf->map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		fdf_error(NULL, "fdf: Usage: ./fdf mapfile\n");
	fdf = fdf_create_fdf();
	fdf_readmap(fdf, argv[1]);

//	tmp_print_map(fdf);

//	temp_map(fdf);
	fdf_init(fdf);
	fdf_draw(fdf);
	mlx_loop(fdf->mlx);
	fdf_exit(fdf);
	return (0);
}

void	fdf_exit(t_fdf *fdf)
{
	if (fdf)
		fdf_remove_fdf(&fdf);
	exit(0);
}
