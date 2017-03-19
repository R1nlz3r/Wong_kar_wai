/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 14:09:49 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 17:41:50 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		game_start(t_2048 *wkw)
{
	int		key;

	while (1)
	{
		clear();
		wkw->wdow = subwin(stdscr, LINES, COLS, 0, 0);
		wborder(wkw->wdow, '|','|',  '-' , '-', '+','+', '+','+');
		move(LINES * 0.5, COLS * 0.5 - ft_strlen("Welcome to 2048 ! \
			Press Enter to play") / 2 + 2);
		printw("Welcome to 2048 ! Press Enter to play");
		key = getch();
		if (key == KEY_UP)
			break ;
		else if (key == 27)
			return (1);
	}
	return (0);
}
