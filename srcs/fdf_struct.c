/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:23:13 by geliz             #+#    #+#             */
/*   Updated: 2020/11/14 17:26:20 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_remove_fdf(t_fdf **fdf)
{
	int		i;
	t_fdf	*tmp;

	i = 0;
	tmp = *fdf;
	while (tmp->map && tmp->map[i])
	{
		free(tmp->map[i]);
		tmp->map[i] = NULL;
		i++;
	}
	free(tmp->map);
	tmp->map = NULL;
	tmp->mlx = NULL;
	tmp->win = NULL;
	tmp->img = NULL;
	tmp->img_iso = NULL;
	if (tmp->bres)
		free(tmp->bres);
	tmp->bres = NULL;
	free(tmp);
	*fdf = NULL;
}

t_fdf	*fdf_create_fdf(void)
{
	t_fdf	*new;

	new = fdf_memalloc(NULL, sizeof(t_fdf));
	new->map_x = 0;
	new->map_y = 0;
	new->mlx = NULL;
	new->win = NULL;
	new->img = NULL;
	new->map = NULL;
	new->bres = fdf_memalloc(new, sizeof(t_bres));
	new->image = 0;
	return (new);
}
