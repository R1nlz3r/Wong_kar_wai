/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:40:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/18 17:31:04 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		game(t_2048 *wkw)
{
	int		key;

	key = 0;
	while (1)
	{
		clear();
		wkw = game_new_piece(wkw);
		draw_window(wkw);//afficher la grille
		key = getch();
		//if (tmp == KEY_UP)
			//game_change_up();
		//else if (tmp == KEY_DOWN)
			//game_change_down();
		//else if (tmp == KEY_RIGHT)
			//game_change_right();
		//else if (tmp == KEY_LEFT)
			//game_change_left();
		if (key == 27 || check_end_game(wkw)) //else if
			break ;
	}
}
