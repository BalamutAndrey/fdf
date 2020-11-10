/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:13:12 by geliz             #+#    #+#             */
/*   Updated: 2020/11/10 19:14:08 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*fdf_memalloc(t_fdf *fdf, size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		fdf_error(fdf, "Malloc error\n");
	ft_memset(res, 0, size);
	return (res);
}
