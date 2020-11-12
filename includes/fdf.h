/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:46:00 by eboris            #+#    #+#             */
/*   Updated: 2020/11/11 17:48:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
//# include <mlx.h>
# include <math.h>
# include "libft.h"

# define SIZE_X 1500
# define SIZE_Y 1000
# define MAX_X 150
# define MAX_Y 100
# define ZOOM 20

# define WHITE 0xffffff
# define RED 0xe80c0c

typedef struct	s_bres
{
	float		x1;
	float		y1;
	float		x2;
	float		y2;
	float		z1;
	float		z2;
}				t_bres;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			map_x;
	int			map_y;
	 int			**map;
//	int			map[11][19];
	t_bres		*bres;
}				t_fdf;

typedef struct		s_str
{
	int				*arr;
	struct s_str	*next;
}					t_str;

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
void	fdf_readmap_check(t_fdf *fdf, char *str, t_str *first);
void	fdf_read_clean(char *str, t_str *fir, int fir_fl);
void	fdf_fillmap(t_fdf *fdf, t_str *first);
/*
** 
*/
int		fdf_string_to_arr(t_fdf *fdf, t_str *first, char *str);
void	fdf_fill_str_struct(t_fdf *fdf, t_str *first, char **split, int i);
void	fdf_fill_arr(t_fdf *fdf, t_str *f, char **split, int len);
int		fdf_check_is_number(t_fdf *fdf, char *str, char **spl);
void	fdf_remove_split(char ***split);
/*
** fdf_init.c
*/
void    fdf_init(t_fdf *fdf);
/*
** fdf_keyboard.c
*/
int		fdf_keyboard(t_fdf *fdf);
/*
** fdf_draw.c
*/
void	fdf_draw(t_fdf *fdf);
void	fdf_draw_1(t_fdf *fdf);
void	fdf_bresenham(t_fdf *fdf);
void    temp_map(t_fdf *fdf);

#endif
