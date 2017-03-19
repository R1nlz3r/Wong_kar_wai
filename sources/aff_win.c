/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 21:19:31 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 21:21:53 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		aff_win2(t_2048 *wkw)
{
	wkw->wdow = subwin(stdscr, LINES, COLS, 0, 0);
	wborder(wkw->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
	move(LINES * 0.5 - 2, COLS * 0.5 - 4);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(5));
	printw("YOU WIN");
	attroff(COLOR_PAIR(5));
	move(LINES / 2, COLS / 2 - 34);
	printw("Partie terminee, "
		"appuyez sur ENTER pour continuer ou ESC pour quitter.");
	move(LINES * 0.5 + 2, COLS * 0.5 - 5);
	printw("Score : %u", wkw->score);
}

int				aff_win(t_2048 *wkw)
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
			aff_win2(wkw);
		key = getch();
		if (key == 10)
			break ;
		else if (key == 27)
			return (1);
	}
	return (0);
}
