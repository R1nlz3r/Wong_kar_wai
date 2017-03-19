/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:49:40 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 16:19:17 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static t_2048		*init_t_2048(t_2048 *wkw)
{
	int		tmp;

	tmp = 0;
	if (!(wkw = ft_memalloc(sizeof(t_2048)))
		|| !(wkw->map = ft_memalloc(sizeof(int**) * 4)))
		return (NULL);
	while (tmp < 4)
		wkw->map[tmp++] = ft_tabnew(4);
	wkw->win_value = WIN_VALUE;
	wkw->lines = 0;
	wkw->columns = 0;
	wkw->score = 0;
	return (wkw);
}

static void		del_t_2048(t_2048 *wkw)
{
	int		tmp;

	tmp = 0;
	while (tmp < 4)
		ft_memdel((void**)&wkw->map[tmp++]);
	ft_memdel((void**)wkw->map);
	free(wkw->wdow);
	free(wkw);
}

static void		reset_t_2048(t_2048 *wkw)
{
	int		tmp;

	tmp = 0;
	while (tmp < 4)
		ft_tabfill(wkw->map[tmp++], 0, 4);
	wkw->score = 0;
}

static void		implement_color(void)
{
	init_color(FOND, 187 * 3, 173 * 3, 160 * 3);
	init_color(ZERO, 205 * 4, 193 * 4, 180 * 4);
	init_color(CHIFFRE, 119, 110, 101);
	init_color(DEUX, 238 * 4, 228 * 4, 218 * 4);
	init_color(QUATRE, 237 * 4, 224 * 4, 200* 4);
	init_color(HUIT, 242 * 5, 177 * 5, 121 * 5);
}

int					main(void)
{
	t_2048		*wkw;
	int			rerun;

	wkw = NULL;
	rerun = 1;
	if (!(wkw = init_t_2048(wkw))
		|| wkw->win_value % 2 != 0)
		return (-1);
	srand((unsigned)time(NULL));
	initscr();
	keypad(stdscr, TRUE);
	set_escdelay(1);
	noecho();
	cbreak();
	start_color();
	implement_color();
	curs_set(0);
	clear();
	if (game_start(wkw))
		rerun = 0;
	while (rerun)
	{
		clear();
		rerun = game(wkw);
		reset_t_2048(wkw);
	}
	del_t_2048(wkw);
	endwin();
	return (0);
}
