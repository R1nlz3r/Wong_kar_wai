/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 15:24:33 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 15:27:15 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			game_over(void)
{
	int		key;

	while (1)
	{
		clear();
		move(LINES * 0.46, COLS * 0.44);
		init_pair(5, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(5));
		printw("GAME OVER.");
		attroff(COLOR_PAIR(5));
		move(LINES / 2, COLS / 5);
		printw("Partie terminee, appuyez sur une touche pour rejouez ou ESC \
			pour quitter.");
		move(LINES * 0.55, COLS * 0.44);
		printw("Score : 42");
		key = getch();
		if (key == KEY_UP)
			break ;
		else if (key == 27)
			return (1);
	}
	return (1);
}
