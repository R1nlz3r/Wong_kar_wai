/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_game_over.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 21:19:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 21:21:00 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		aff_game_over2(t_2048 *wkw)
{
	wkw->wdow = subwin(stdscr, LINES, COLS, 0, 0);
	wborder(wkw->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
	move(LINES * 0.5 - 2, COLS * 0.5 - 4);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(5));
	printw("GAME OVER.");
	attroff(COLOR_PAIR(5));
	move(LINES / 2, COLS / 2 - 34);
	printw("Partie terminee, "
		"appuyez sur ENTER pour rejouez ou ESC pour quitter.");
	move(LINES * 0.5 + 2, COLS * 0.5 - 5);
	printw("Score : %u", wkw->score);
}

int				aff_game_over(t_2048 *wkw)
{
	int		key;

	while (1)
	{
		clear();
		if (LINES < 20 || COLS < 80)
		{
			clear();
			printw("Window too small, fuck you.");
		}
		else
			aff_game_over2(wkw);
		key = getch();
		if (key == 10)
			return (1);
		else if (key == 27)
			break ;
	}
	return (0);
}
