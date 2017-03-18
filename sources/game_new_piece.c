/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_new_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:20:53 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/18 16:26:57 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int check_end(t_2048 *wkw)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (wkw->map[i][j] == 0)
				return (0);
				j++;
		}
		i++;
	}
	return (1);
}

static void 		del_t_2048(t_2048 *wkw)
{
	int		tmp;

	tmp = 0;
	while (tmp < 4)
		ft_memdel((void**)&wkw->map[tmp++]);
	ft_memdel((void**)wkw->map);
	free(wkw->wdow);
	free(wkw);
}

t_2048		*game_new_piece(t_2048 *wkw)
{
	int		tmp;

	tmp = 2;
	while (1)
	{
		if (check_end(wkw) == 1)
		{
			del_t_2048(wkw);
			return (NULL);
		}
		wkw->lines = rand() % 4;
		wkw->columns = rand() % 4;
		if (wkw->map[wkw->lines][wkw->columns] == 0)
		{
			if (rand() % 2)
				tmp = 4;
			wkw->map[wkw->lines][wkw->columns] = tmp;
			break ;
		}
	}
	return (wkw);
}
