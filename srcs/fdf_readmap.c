/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_readmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:11:18 by geliz             #+#    #+#             */
/*   Updated: 2020/11/11 12:57:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_readmap(t_fdf *fdf, char *arg)
{
	int		fd;
	char	*str;

	fd = open(arg, O_RDONLY);//errno?
	if (fd == -1)
		fdf_error(fdf, "fdf: Error opening file\n");
	while (get_next_line(fd, &str) == 1)
	{
		break ;
	}
	return ;
}