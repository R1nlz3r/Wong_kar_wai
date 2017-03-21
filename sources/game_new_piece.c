/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_new_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:20:53 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/21 22:04:22 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void			game_new_piece(t_2048 *wkw)
{
	int		tmp;

	tmp = 4;
	while (1)
	{
		wkw->lines = rand() % 4;
		wkw->columns = rand() % 4;
		if (wkw->map[wkw->lines][wkw->columns] == 0)
		{
			if (rand() % 4)
				tmp = 2;
			wkw->map[wkw->lines][wkw->columns] = tmp;
			break ;
		}
	}
}
