/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:49:40 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/18 11:48:21 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static t_2048		*init_t_2048(t_2048 *wong_kar_wai)
{
	if (!(wong_kar_wai = ft_memalloc(sizeof(t_2048))))
		return (NULL);
	return (wong_kar_wai);
}

static void 		del_t_2048(t_2048 *wong_kar_wai)
{
	ft_memdel((void**)wong_kar_wai->wdow);
	ft_memdel((void**)wong_kar_wai);
}

int					main(void)
{
	t_2048		*wong_kar_wai;
	int 		tmp = 0;

	wong_kar_wai = NULL;
	if (!(wong_kar_wai = init_t_2048(wong_kar_wai))
		|| wong_kar_wai->win_value % 2 != 0)
		return (-1);
	initscr();

	while (1)
	{
		clear();
		mvprintw(LINES / 2, COLS / 2, ft_itoa(tmp));
		tmp = getch();
		if (tmp == KEY_UP)
			break;
	}

	endwin();
	del_t_2048(wong_kar_wai);
	return (0);
}
