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

void	fdf_fillmap(t_fdf *fdf, t_str *first)
{
	int		i;
	t_str	*tmp;

	i = 0;
	tmp = first;
	fdf->map = fdf_memalloc(fdf, (sizeof(int *) * fdf->map_y));
	while (tmp)
	{
		fdf->map[i] = tmp->arr;
		i++;
		tmp = tmp->next;
	}
	fdf_read_clean(NULL, first, 0);
}

void	fdf_read_clean(char *str, t_str *fir, int fir_fl)
{
	t_str	*tmp;
	
	if (str)
		ft_strdel(&str);
	if (fir)
	{
		tmp = fir;
		while (tmp)
		{
			fir = tmp->next;
			tmp->next = NULL;
			if (fir_fl == 1)
			{
				free(tmp->arr);
				tmp->arr = NULL;
			}
			free (tmp);
			tmp = fir;
		}
	}
}

void	fdf_readmap_check(t_fdf *fdf, char *str, t_str *first)
{
	if (fdf->map_x == 0)
	{
		fdf->map_x = fdf_string_to_arr(fdf, first, str);
		if (fdf->map_x == -1)
		{
			fdf_read_clean(str, first, 1);
			fdf_error(fdf, "fdf: Map invalid\n");
		}
	}
	else if (fdf->map_x != fdf_string_to_arr(fdf, first, str))
	{
		fdf_read_clean(str, first, 1);
		fdf_error(fdf, "fdf: Map invalid\n");
	}
}

void	fdf_readmap(t_fdf *fdf, char *arg)
{
	int		fd;
	char	*str;
	t_str	*first;

	fd = open(arg, O_RDONLY);//errno?
	if (fd == -1)
		fdf_error(fdf, "fdf: Error opening file\n");
	first = fdf_memalloc(fdf, sizeof(t_str));
	first->next = NULL;
	first->arr = NULL;
	while (get_next_line(fd, &str) == 1)
	{
		fdf_readmap_check(fdf, str, first);
		fdf->map_y++;
		ft_strdel(&str);
	}
	ft_strdel(&str);
	if (fdf->map_y < 2)
	{
		fdf_read_clean(str, first, 1);
		fdf_error(fdf, "Map invalid\n");
	}
	fdf_fillmap(fdf, first);
}
