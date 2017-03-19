/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:47:07 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 18:45:04 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048
# define GAME_2048

# include <ncurses.h>
# include <time.h>
# include "../libft/libft.h"

# define FOND		150
# define CHIFFRE	151
# define ZERO		152
# define DEUX		153
# define QUATRE		154
# define HUIT		155
# define SEIZE 		156
# define TRENTE		157
# define SOIXANTE	158
# define CENT 		159

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_2048
{
	WINDOW			*wdow;
	enum e_const	win_value;
	int				win;
	int				**map;
	int				lines;
	int				columns;
	size_t			score;
}					t_2048;

int					game(t_2048 *wkw);
void				game_new_piece(t_2048 *wkw);
void				draw_window(t_2048 *wkw);
int 				game_start(t_2048 *wkw);
int					game_down(t_2048 *wkw);
int					game_up(t_2048 *wkw);
int					game_left(t_2048 *wkw);
int					game_right(t_2048 *wkw);
int					check_pow_2(int value);

#endif
