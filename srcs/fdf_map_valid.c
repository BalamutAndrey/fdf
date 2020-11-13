
#include "fdf.h"

void	fdf_remove_split(char ***split)
{
	char	**tmp;
	int		i;

	tmp = *split;
	i = 0;
	while (tmp && tmp[i])
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
	*split = NULL;
}

int		fdf_check_is_number(t_fdf *fdf, char *str, char **spl)
{
	int		i;
	int		c_len;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1)
		i++;
	if (ft_isdigit(str[i]) != 1)
		return (-1);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (!str[i])
		return (0);
	if (ft_strlen(&str[i]) >= 3 && (ft_strncmp(&str[i], ",0x", 3) == 0))
		return (0);
	else
		return (-1);
}

void	fdf_fill_arr(t_fdf *fdf, t_str *f, char **split, int len)
{
	int		j;

	j = 0;
	f->arr = fdf_memalloc(fdf, (sizeof(int) * len));
	while (j < len)
	{
		f->arr[j] = ft_atoi(split[j]);
		j++;
	}
}

void	fdf_fill_str_struct(t_fdf *fdf, t_str *first, char **split, int i)
{
	t_str	*tmp;

	tmp = first;
	if (!first->arr)
		fdf_fill_arr(fdf, first, split, i);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = fdf_memalloc(fdf, sizeof(t_str));
		tmp = tmp->next;
		tmp->next = NULL;
		fdf_fill_arr(fdf, tmp, split, i);
	}
}

int		fdf_string_to_arr(t_fdf *fdf, t_str *first, char *str)
{
	char	**split;
	int		i;
	int		err;

	i = 0;
	err = 0;
	split = ft_strsplit(str, ' ');
	while (split[i] && err == 0)
	{
		err = fdf_check_is_number(fdf, split[i], split);
		i++;
	}
	if (i < 2)
		err = -1;
	if (err == -1)
	{
		fdf_remove_split(&split);
		return (-1);
	}
	fdf_fill_str_struct(fdf, first, split, i);
	fdf_remove_split(&split);
	return (i);
}
