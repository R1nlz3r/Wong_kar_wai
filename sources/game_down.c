/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:07:08 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 16:21:06 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		game_down(t_2048 *wkw)
{
	int		tmp;
	int		count;

	count = 0;
	wkw->columns = 0;
	while (wkw->columns < 4)
	{
		wkw->lines = 2;
		while (wkw->lines >= 0)
		{
			if (wkw->map[wkw->lines][wkw->columns] != 0)
			{
				tmp = wkw->lines + 1;
				while (tmp < 4 && wkw->map[tmp][wkw->columns] == 0)
					++tmp;
				if (tmp >= 4 && (++count))
				{
					wkw->map[3][wkw->columns] = wkw->map[wkw->lines][wkw->columns];
					wkw->map[wkw->lines][wkw->columns] = 0;
				}
				else if (wkw->map[tmp][wkw->columns] == wkw->map[wkw->lines][wkw->columns] && (++count))
				{
					wkw->map[tmp][wkw->columns] = wkw->map[wkw->lines][wkw->columns] * 2;
					wkw->score += (size_t)wkw->map[wkw->lines]
						[wkw->columns] * 2;
					wkw->map[wkw->lines][wkw->columns] = 0;
				}
				else if (tmp - 1 != wkw->lines && (++count))
				{
					wkw->map[tmp - 1][wkw->columns] = wkw->map[wkw->lines][wkw->columns];
					wkw->map[wkw->lines][wkw->columns] = 0;
				}
			}
			--wkw->lines;
		}
		++wkw->columns;
	}
	if (count)
		return (1);
	return (0);
}
