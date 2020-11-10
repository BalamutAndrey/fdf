/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:46:00 by eboris            #+#    #+#             */
/*   Updated: 2020/11/10 19:31:29 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

# define SIZE_X 1500
# define SIZE_Y 1000
# define MAX_X 150
# define MAX_Y 100

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			map_x;
	int			map_y;
	int			**map;
}				t_fdf;

/*
** fdf.c
*/
int				main(int argc, char **argv);
void			fdf_exit(t_fdf *fdf);
/*
** fdf_struct.c
*/
t_fdf			*fdf_create_fdf(void);
void			fdf_remove_fdf(t_fdf **fdf);
/*
** fdf_func.c
*/
void	*fdf_memalloc(t_fdf *fdf, size_t size);
/*
** fdf_error.c
*/
void	fdf_error(t_fdf *fdf, char *err);
/*
** fdf_readmap.c
*/
void	fdf_readmap(t_fdf *fdf, char *arg);


#endif
