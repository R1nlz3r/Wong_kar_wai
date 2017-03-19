/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:15:24 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 22:38:27 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static short	get_color(int val)
{
	short		t[12];
	short		i;

	if (val > 2048)
		return (COLOR_RED);
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
	while (t[i] != (short)val && i < 12)
		i++;
	return (i + 152);
}

static void		draw_window2(t_2048 *wkw, short *tmp, short *a, short *b)
{
	char		*nb;

	nb = ft_itoabase_signed(wkw->map[wkw->lines][wkw->columns], 10);
	wkw->wdow2 = subwin(stdscr, LINES / 4, COLS / 4,
		(LINES / 4 - 1) * wkw->lines, (COLS / 4 - 1) * wkw->columns);
	*tmp = get_color(wkw->map[wkw->lines][wkw->columns]);
	init_pair(*a, *tmp, *tmp);
	init_pair(*b, CHIFFRE, *tmp);
	wbkgd(wkw->wdow2, COLOR_PAIR((chtype)(*a)));
	++*a;
	wkw->wdow = subwin(stdscr, LINES / 4, COLS / 4,
		(LINES / 4 - 1) * wkw->lines, (COLS / 4 - 1) * wkw->columns);
	move((LINES / 4 - 1) * wkw->lines + (LINES / 8),
		(COLS / 4 - 1) * wkw->columns + (COLS / 8) -
		(int)(ft_strlen(nb) / 2));
	attron(COLOR_PAIR((chtype)(*b)));
	if (wkw->map[wkw->lines][wkw->columns] != 0)
		printw("%d", wkw->map[wkw->lines][wkw->columns]);
	attroff(COLOR_PAIR((chtype)(*b)));
	++*b;
	wattron(wkw->wdow, COLOR_PAIR(1));
	wborder(wkw->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
	wattroff(wkw->wdow, COLOR_PAIR(1));
	ft_strdel(&nb);
}

void			draw_window(t_2048 *wkw)
{
	short		tmp;
	short		a;
	short		b;

	wkw->lines = 0;
	tmp = 0;
	a = 150;
	b = 200;
	init_pair(1, FOND, FOND);
	if (LINES < 20 || COLS < 60)
	{
		printw("Window too small, fuck you.");
		return ;
	}
	while (wkw->lines < 4)
	{
		wkw->columns = 0;
		while (wkw->columns < 4)
		{
			draw_window2(wkw, &tmp, &a, &b);
			++wkw->columns;
		}
		++wkw->lines;
	}
	wrefresh(wkw->wdow);
}
