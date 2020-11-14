/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:46:00 by eboris            #+#    #+#             */
/*   Updated: 2020/11/14 16:32:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include "libft.h"

# define SIZE_X 1500
# define SIZE_Y 1000
# define MAX_X 150
# define MAX_Y 100

# define BUFF_SIZE 10000
# define ERROR -1
# define SUCCESS 1
# define END 0

typedef	struct		s_color
{
	char			red;
	char			green;
	char			blue;
	char			alpha;
}					t_color;

typedef struct		s_bres
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				z1;
	int				z2;
}					t_bres;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_iso;
	bool			image;
	char			*data;
	char			*data_iso;
	char			*data_cls;
	int				bit;
	int				size;
	int				endian;
	int				map_x;
	int				map_y;
	int				**map;
	int				zoom;
	t_bres			*bres;
}					t_fdf;

typedef struct		s_str
{
	int				*arr;
	struct s_str	*next;
}					t_str;

/*
** fdf.c
*/
int					main(int argc, char **argv);
int					fdf_close(void *param);
void				fdf_exit(t_fdf *fdf);
/*
** fdf_struct.c
*/
t_fdf				*fdf_create_fdf(void);
void				fdf_remove_fdf(t_fdf **fdf);
/*
** fdf_func.c
*/
void				*fdf_memalloc(t_fdf *fdf, size_t size);
/*
** fdf_error.c
*/
void				fdf_error(t_fdf *fdf, char *err);
/*
** fdf_readmap.c
*/
void				fdf_readmap(t_fdf *fdf, char *arg);
void				fdf_readmap_check(t_fdf *fdf, char *str, t_str *first);
void				fdf_read_clean(char *str, t_str *fir, int fir_fl);
void				fdf_fillmap(t_fdf *fdf, t_str *first);
/*
** fdf_map_valid.c
*/
int					fdf_string_to_arr(t_fdf *fdf, t_str *first, char *str);
void				fdf_fill_str_struct(t_fdf *fdf, t_str *first, char **split,
						int i);
void				fdf_fill_arr(t_fdf *fdf, t_str *f, char **split, int len);
int					fdf_check_is_number(t_fdf *fdf, char *str, char **spl);
void				fdf_remove_split(char ***split);
/*
** fdf_init.c
*/
void				fdf_init(t_fdf *fdf);
/*
** fdf_keyboard.c
*/
int					fdf_keyboard(int key, void *param);
/*
** fdf_draw.c
*/
void				fdf_draw(t_fdf *fdf);
/*
** fdf_math.c
*/
void				fdf_math(t_fdf *fdf);
void				fdf_math_x(t_fdf *fdf, int x, int y);
void				fdf_math_y(t_fdf *fdf, int x, int y);
/*
** fdf_math_parallel.c
*/
void				fdf_math_parallel(t_fdf *fdf);
void				fdf_math_parallel_write(t_fdf *fdf, t_color color);
void				fdf_put_pixel_paralel(t_fdf *fdf, int x, int y,
						t_color color);
/*
** fdf_math_iso.c
*/
void				fdf_math_iso(t_fdf *fdf);
void				fdf_math_iso_rotate(t_fdf *fdf);
void				fdf_math_iso_write(t_fdf *fdf, t_color color);
void				fdf_math_iso_write_sign(t_fdf *fdf, double *sign_x,
						double *sign_y);
void				fdf_put_pixel_iso(t_fdf *fdf, int x, int y, t_color color);
/*
** fdf_math_iso_rotate.c
*/
void				fdf_rotate_x(int *y, int *z, double alpha);
void				fdf_rotate_y(int *x, int *z, double beta);
void				fdf_rotate_z(int *x, int *y, double gamma);
/*
** gnl.c
*/
int					get_next_line(const int fd, char **line);
static t_list		*ft_findlist(t_list *first, int fd);
static int			ft_readplus(t_list *temp, char **line, char *buf);
static int			ft_fillstring(t_list *temp, char **line, char *part,
						int res);
static char			*ft_giveline(t_list *temp, char *part);
/*
** gnl_clear.c
*/
void				ft_lst_del(t_list *first);

#endif
