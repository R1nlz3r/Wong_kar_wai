/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:56:03 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/21 22:18:51 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		game_up2(t_2048 *wkw, int *tmp, int *count, int *lock)
{
	if (*tmp < 0 && (++count))
	{
		wkw->map[0][wkw->columns] = wkw->map[wkw->lines]
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
	else if (*tmp + 1 != wkw->lines && (++*count))
	{
		wkw->map[*tmp + 1][wkw->columns] = wkw->map[wkw->lines]
			[wkw->columns];
		wkw->map[wkw->lines][wkw->columns] = 0;
	}
}

int				game_up(t_2048 *wkw)
{
	int		tmp;
	int		count;
	int		lock;

	count = 0;
	wkw->columns = 0;
	while (wkw->columns < 4)
	{
		wkw->lines = 1;
		lock = 0;
		while (wkw->lines < 4)
		{
			if (wkw->map[wkw->lines][wkw->columns] != 0)
			{
				tmp = wkw->lines - 1;
				while (tmp >= 0 && wkw->map[tmp][wkw->columns] == 0)
					--tmp;
				game_up2(wkw, &tmp, &count, &lock);
			}
			++wkw->lines;
		}
		++wkw->columns;
	}
	if (count)
		return (1);
	return (0);
}
