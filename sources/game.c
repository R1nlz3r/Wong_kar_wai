/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:40:30 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 21:19:15 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		check_win(t_2048 *wkw)
{
	wkw->lines = 0;
	while (wkw->lines < 4)
	{
		wkw->columns = 0;
		while (wkw->columns < 4)
		{
			if (wkw->map[wkw->lines][wkw->columns++] == wkw->win_value
				&& (++wkw->win))
				return (1);
		}
		++wkw->lines;
	}
	return (0);
}

static int		check_loose(t_2048 *wkw)
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

int				game(t_2048 *wkw)
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
		if (!wkw->win && check_win(wkw) && aff_win(wkw))
			break ;
		else if (check_loose(wkw))
			return (aff_game_over(wkw));
	}
	return (0);
}
