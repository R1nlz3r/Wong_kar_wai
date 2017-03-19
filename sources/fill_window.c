/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:15:24 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 15:32:08 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static short	get_color(short val)
{
	short		t[10] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	short		i;

	i = 0;
	while (t[i] != val)
		i++;
	return (i + 11);
}

void			draw_window(t_2048 *wkw)
{
	int			i;
	int			j;
	short		tmp;
	short		b;
	WINDOW		*win;

	i = 0;
	b = 4;
	init_pair(1, FOND, FOND);
	if (LINES < 40 || COLS < 40)
	{
		printw("Window too small, fuck you.");
		return ;
	}
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			win = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i,
				(COLS / 4 - 1) * j);
			tmp = get_color((short)wkw->map[i][j]);
			init_pair(b, tmp, tmp);
			init_pair(2000, CHIFFRE, tmp);
			wbkgd(win, COLOR_PAIR((chtype)b));
			b++;
			wkw->wdow = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i,
				(COLS / 4 - 1) * j);
			move((LINES / 4 - 1) * i + (LINES / 8),
				(COLS / 4 - 1) * j + (COLS / 8));
			attron(COLOR_PAIR(25));
			if (wkw->map[i][j] != 0)
			printw("%d", wkw->map[i][j]);
			attroff(COLOR_PAIR(25));
			wattron(wkw->wdow, COLOR_PAIR(1));
			wborder(wkw->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
			wattroff(wkw->wdow, COLOR_PAIR(1));
			++j;
		}
		++i;
	}
	wrefresh(wkw->wdow);
}
