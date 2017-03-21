/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:39:09 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/21 22:24:55 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		game_left2(t_2048 *wkw, int *tmp, int *count, int *lock)
{
	if (*tmp < 0 && (++*count))
	{
		wkw->map[wkw->lines][0] = wkw->map[wkw->lines]
			[wkw->columns];
		wkw->map[wkw->lines][wkw->columns] = 0;
	}
	else if (!*lock && wkw->map[wkw->lines][*tmp] == wkw->map[wkw->lines]
			[wkw->columns] && (++*count))
	{
		wkw->map[wkw->lines][*tmp] = wkw->map[wkw->lines]
			[wkw->columns] * 2;
		wkw->score += (size_t)wkw->map[wkw->lines]
			[wkw->columns] * 2;
		wkw->map[wkw->lines][wkw->columns] = 0;
		++*lock;
	}
	else if (*tmp + 1 != wkw->columns && (++count))
	{
		wkw->map[wkw->lines][*tmp + 1] = wkw->map[wkw->lines]
			[wkw->columns];
		wkw->map[wkw->lines][wkw->columns] = 0;
	}
}

int				game_left(t_2048 *wkw)
{
	int		tmp;
	int		count;
	int		lock;

	count = 0;
	wkw->lines = 0;
	while (wkw->lines < 4)
	{
		wkw->columns = 1;
		lock = 0;
		while (wkw->columns < 4)
		{
			if (wkw->map[wkw->lines][wkw->columns] != 0)
			{
				tmp = wkw->columns - 1;
				while (tmp >= 0 && wkw->map[wkw->lines][tmp] == 0)
					--tmp;
				game_left2(wkw, &tmp, &count, &lock);
			}
			++wkw->columns;
		}
		++wkw->lines;
	}
	if (count)
		return (1);
	return (0);
}
