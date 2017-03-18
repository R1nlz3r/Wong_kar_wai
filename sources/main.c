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

static void 		del_t_2048(t_2048 *wkw)
{
	int		tmp;

	tmp = 0;
	while (tmp < 4)
		ft_memdel((void**)&wkw->map[tmp++]);
	ft_memdel((void**)wkw->map);
	ft_memdel((void**)wkw->wdow);
	ft_memdel((void**)wkw);
}

int					main(void)
{
	t_2048		*wkw;

	wkw = NULL;
	if (!(wkw = init_t_2048(wkw))
		|| wkw->win_value % 2 != 0)
		return (-1);
	srand((unsigned)time(NULL));
	initscr();
	noecho();
	game(wkw);
	endwin();
	del_t_2048(wkw);
	return (0);
}
