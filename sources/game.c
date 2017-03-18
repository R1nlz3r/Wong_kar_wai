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

int		game(t_2048 *wkw)
{
	int key;
	keypad(stdscr, TRUE);
	set_escdelay(1);
	while (1)
	{
		clear();
		wkw = game_new_piece(wkw);
		if (wkw == NULL)
			return (game_over());
		draw_window(wkw);//afficher la grille
		key = getch();
		if (key == 27)
			return (1);
		//refresh();
			//game_change_up();
		//	game_change_left();
		//else if (tmp == 27) //else if
			//return ;
	}
}
