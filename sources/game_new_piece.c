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

t_2048		*game_new_piece(t_2048 *wkw)
{
	int		tmp;

	tmp = 2;
	while (1)
	{
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
