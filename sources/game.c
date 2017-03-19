/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:40:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 16:23:10 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			game(t_2048 *wkw)
{
	int		key;

	game_new_piece(wkw);
	while (1)
	{
		clear();
		draw_window(wkw);
		key = getch();
		if (key == KEY_UP && game_up(wkw))
			game_new_piece(wkw);
		else if (key == KEY_DOWN && game_down(wkw))
			game_new_piece(wkw);
		else if (key == KEY_LEFT && game_left(wkw))
			game_new_piece(wkw);
		else if (key == KEY_RIGHT && game_right(wkw))
			game_new_piece(wkw);
		else if (key == 27)
			break ;
		if (check_end_game(wkw))
		{
			clear();
			return (game_over(wkw));
		}
	}
	return (0);
}
