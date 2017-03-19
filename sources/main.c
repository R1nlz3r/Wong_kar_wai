/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:49:40 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 22:36:06 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static t_2048	*init_t_2048(t_2048 *wkw)
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
	init_color(QUATRE, 237 * 4, 224 * 4, 200 * 4);
	init_color(HUIT, 242 * 4, 177 * 4, 121 * 4);
	init_color(SEIZE, 245 * 4, 149 * 4, 99 * 4);
	init_color(TRENTE, 246 * 4, 124 * 4, 95 * 4);
	init_color(SOIXANTE, 246 * 4, 94 * 4, 59 * 4);
	init_color(CENT, 237 * 4, 207 * 4, 114 * 4);
	init_color(DEUX_CENT, 237 * 4 - 30, 204 * 4 - 30, 97 * 4 - 30);
	init_color(CINQ_CENT, 237 * 4 - 80, 204 * 4 - 80, 97 * 4 - 80);
	init_color(MILLE, 237 * 4 - 130, 204 * 4 - 130, 97 * 4 - 130);
	init_color(DEUX_MILLE, 237 * 4 - 170, 204 * 4 - 170, 97 * 4 - 170);
}

int				main(void)
{
	t_2048		*wkw;
	int			rerun;

	wkw = NULL;
	rerun = 1;
	if (!(wkw = init_t_2048(wkw))
		|| check_pow_2(wkw->win_value))
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
	rerun = game_start(wkw);
	while (rerun && (rerun = game(wkw)))
		reset_t_2048(wkw);
	del_t_2048(wkw);
	endwin();
	return (0);
}
