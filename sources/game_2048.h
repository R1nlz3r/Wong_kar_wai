/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:47:07 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/18 17:28:06 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048
# define GAME_2048

#include <ncurses.h>
#include <time.h>
#include "../libft/libft.h"

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_2048
{
	WINDOW			*wdow;
	enum e_const	win_value;
	char			pad_0[4];
	int				**map;
	int				lines;
	int				columns;
}					t_2048;

void		game(t_2048 *wkw);
t_2048		*game_new_piece(t_2048 *wong_kar_wai);
int			check_end_game(t_2048 *wkw);
void		draw_window(t_2048 *wkw);
#endif
