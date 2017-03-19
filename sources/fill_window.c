/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:15:24 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 19:33:06 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static short	get_color(short val)
{
	short		t[12];
	short i;

	i = 0;
	t[0] = 0;
	t[1] = 2;
	t[2] = 4;
	t[3] = 8;
	t[4] = 16;
	t[5] = 32;
	t[6] = 64;
	t[7] = 128;
	t[8] = 256;
	t[9] = 512;
	t[10] = 1024;
	t[11] = 2048;
	while (t[i] != val && i < 12)
		i++;
	if (i == 12)
		return (RED);
	return (i + 152);
}

void			draw_window(t_2048 *wkw)
{
	int			i;
	int			j;
	short		tmp;
	short		b;
	short		c;
	WINDOW		*win;

	i = 0;
	b = 150;
	c = 200;
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
			init_pair(c, CHIFFRE, tmp);
			wbkgd(win, COLOR_PAIR((chtype)b));
			++b;
			wkw->wdow = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i,
				(COLS / 4 - 1) * j);
			move((LINES / 4 - 1) * i + (LINES / 8),
				(COLS / 4 - 1) * j + (COLS / 8) -
				(int)(ft_strlen(ft_itoa(wkw->map[i][j])) / 2));
			attron(COLOR_PAIR( (chtype)c ));
			if (wkw->map[i][j] != 0)
			printw("%d", wkw->map[i][j]);
			attroff(COLOR_PAIR( (chtype)c ));
			++c;
			wattron(wkw->wdow, COLOR_PAIR(1));
			wborder(wkw->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
			wattroff(wkw->wdow, COLOR_PAIR(1));
			++j;
		}
		++i;
	}
	wrefresh(wkw->wdow);
}
