/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:46:00 by eboris            #+#    #+#             */
/*   Updated: 2020/11/13 18:07:55 by eboris           ###   ########.fr       */
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
# define ZOOM 35

typedef	struct	s_color
{
	char	red;
	char	green;
	char	blue;
	char	alpha;
}				t_color;


typedef struct	s_bres
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		z1;
	double		z2;
}				t_bres;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_iso;
	char		*data;
	char		*data_iso;
	int			bit;
	int			size;
	int			endian;
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
void	fdf_bresenham_iso(t_fdf *fdf);
void    temp_map(t_fdf *fdf);

#endif
