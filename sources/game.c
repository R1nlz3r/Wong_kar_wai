/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:40:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 12:54:54 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			game(t_2048 *wkw)
{
	int		key;

	//affichage début du jeu ou rejouer
	wkw = game_new_piece(wkw);
	while (1)
	{
		clear();
		draw_window(wkw);
		key = getch();
		if (key == KEY_UP && game_up(wkw))
			wkw = game_new_piece(wkw);
		else if (key == KEY_DOWN && game_down(wkw))
			wkw = game_new_piece(wkw);
		else if (key == KEY_LEFT && game_left(wkw))
			wkw = game_new_piece(wkw);
		else if (key == KEY_RIGHT && game_right(wkw))
			wkw = game_new_piece(wkw);
		else if (key == 27)
			break ;
		if (check_end_game(wkw))
		{
			clear();
			return (game_over());
		}
	}
	return (0);
}
