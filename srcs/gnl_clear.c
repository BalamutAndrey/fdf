/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:45:59 by geliz             #+#    #+#             */
/*   Updated: 2020/11/14 15:42:49 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lst_del(t_list *first)
{
	t_list	*tmp;

	while (first)
	{
		tmp = first->next;
		if (first->content)
		{
			free(first->content);
			first->content = NULL;
		}
		first->next = NULL;
		free(first);
		first = tmp;
	}
}
