/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:53:50 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 14:25:35 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_end_game(t_2048 *wkw)
{
	wkw->lines = 0;
	while (wkw->lines < 4)
	{
		wkw->columns = 0;
		while (wkw->columns < 4)
		{
			if (!(wkw->map[wkw->lines][wkw->columns] != 0
				&& ((!(wkw->lines + 1 < 4)
				|| wkw->map[wkw->lines][wkw->columns]
				!= wkw->map[wkw->lines + 1][wkw->columns])
				&& (!(wkw->columns + 1 < 4)
				|| wkw->map[wkw->lines][wkw->columns]
				!= wkw->map[wkw->lines][wkw->columns + 1]))))
				return (0);
			++wkw->columns;
		}
		++wkw->lines;
	}
	return (1);
}
