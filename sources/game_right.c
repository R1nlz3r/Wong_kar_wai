/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:50:07 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 12:53:55 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		game_right(t_2048 *wkw)
{
	int		tmp;
	int		count;

	count = 0;
	wkw->lines = 0;
	while (wkw->lines < 4)
	{
		wkw->columns = 2;
		while (wkw->columns >= 0)
		{
			if (wkw->map[wkw->lines][wkw->columns] != 0)
			{
				tmp = wkw->columns + 1;
				while (tmp < 4 && wkw->map[wkw->lines][tmp] == 0)
					++tmp;
				if (tmp >= 4 && (++count))
				{
					wkw->map[wkw->lines][3] = wkw->map[wkw->lines][wkw->columns];
					wkw->map[wkw->lines][wkw->columns] = 0;
				}
				else if (wkw->map[wkw->lines][tmp] == wkw->map[wkw->lines][wkw->columns] && (++count))
				{
					wkw->map[wkw->lines][tmp] = wkw->map[wkw->lines][wkw->columns] * 2;
					wkw->map[wkw->lines][wkw->columns] = 0;
				}
				else if (tmp - 1 != wkw->columns && (++count))
				{
					wkw->map[wkw->lines][tmp - 1] = wkw->map[wkw->lines][wkw->columns];
					wkw->map[wkw->lines][wkw->columns] = 0;
				}
			}
			--wkw->columns;
		}
		++wkw->lines;
	}
	if (count)
		return (1);
	return (0);
}
