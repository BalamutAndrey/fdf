/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:11:02 by geliz             #+#    #+#             */
/*   Updated: 2020/11/14 15:44:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(t_fdf *fdf, char *err)
{
	ft_fprintf(STDERR_FILENO, "\033[0;31;1m%s\033[0m", err);
	fdf_exit(fdf);
}
