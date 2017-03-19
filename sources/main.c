/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:49:40 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/18 17:33:28 by mdardakh         ###   ########.fr       */
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
	return (wkw);
}

int					main(void)
{
	t_2048		*wkw;
	int				tmp;

	tmp = 1;
	wkw = NULL;
	while (tmp)
	{
	if (!(wkw = init_t_2048(wkw))
		|| wkw->win_value % 2 != 0)
		return (-1);
	srand((unsigned)time(NULL));
	initscr();
	noecho();
	cbreak();
	start_color();
	keypad(stdscr, TRUE);
	set_escdelay(1);
	curs_set(0);
	clear();
	start(wkw);
	tmp = game(wkw);
	endwin();
}
	return (0);
}
