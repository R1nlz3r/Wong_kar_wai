/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:07:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/21 22:23:20 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		game_down2(t_2048 *wkw, int *tmp, int *count, int *lock)
{
	if (*tmp >= 4 && (++*count))
	{
		wkw->map[3][wkw->columns] = wkw->map[wkw->lines]
			[wkw->columns];
		wkw->map[wkw->lines][wkw->columns] = 0;
	}
	else if (!*lock && wkw->map[*tmp][wkw->columns] == wkw->map[wkw->lines]
			[wkw->columns] && (++*count))
	{
		wkw->map[*tmp][wkw->columns] = wkw->map[wkw->lines]
			[wkw->columns] * 2;
		wkw->score += (size_t)wkw->map[wkw->lines]
			[wkw->columns] * 2;
		wkw->map[wkw->lines][wkw->columns] = 0;
		++*lock;
	}
	else if (*tmp - 1 != wkw->lines && (++count))
	{
		wkw->map[*tmp - 1][wkw->columns] = wkw->map[wkw->lines]
			[wkw->columns];
		wkw->map[wkw->lines][wkw->columns] = 0;
	}
}

int				game_down(t_2048 *wkw)
{
	int		tmp;
	int		count;
	int		lock;

	count = 0;
	wkw->columns = 0;
	while (wkw->columns < 4)
	{
		wkw->lines = 2;
		lock = 0;
		while (wkw->lines >= 0)
		{
			if (wkw->map[wkw->lines][wkw->columns] != 0)
			{
				tmp = wkw->lines + 1;
				while (tmp < 4 && wkw->map[tmp][wkw->columns] == 0)
					++tmp;
				game_down2(wkw, &tmp, &count, &lock);
			}
			--wkw->lines;
		}
		++wkw->columns;
	}
	if (count)
		return (1);
	return (0);
}
