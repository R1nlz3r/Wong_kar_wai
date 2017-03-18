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
# define C_BOLD                        "\033[1m"
# define C_RESET_BOLD                "\033[21m"
# define C_DIM                        "\033[2m"
# define C_RESET_DIM                    "\033[22m"
# define C_UNDERLINE                    "\033[4m"
# define C_RESET_UNDERLINE            "\033[24m"
# define C_BLINK                        "\033[5m"
# define C_RESET_BLINK                "\033[25m"
# define C_REVERSE                    "\033[7m"
# define C_RESET_REVERSE                "\033[27m"
# define C_HIDDEN                    "\033[8m"
# define C_RESET_HIDDEN                "\033[28m"
# define C_EOC                        "\033[0m"
# define C_BLACK                        "\033[30m"
# define C_RED                        "\033[31m"
# define C_GREEN                        "\033[32m"
# define C_YELLOW                    "\033[33m"
# define C_BLUE                        "\033[34m"
# define C_MAGENTA                    "\033[35m"
# define C_CYAN                        "\033[36m"
# define C_LIGHT_GRAY                "\033[37m"
# define C_DARK_GRAY                    "\033[90m"
# define C_LIGHT_RED                    "\033[91m"
# define C_LIGHT_GREEN                "\033[92m"
# define C_LIGHT_YELLOW                "\033[93m"
# define C_LIGHT_BLUE                "\033[94m"
# define C_LIGHT_MAGENTA                "\033[95m"
# define C_LIGHT_CYAN                "\033[96m"
# define C_WHITE                        "\033[97m"
# define C_RESET_COLOR                "\033[39m"
# define C_BACKGROUND_BLACK            "\033[40m"
# define C_BACKGROUND_RED            "\033[41m"
# define C_BACKGROUND_GREEN            "\033[42m"
# define C_BACKGROUND_YELLOW            "\033[43m"
# define C_BACKGROUND_BLUE            "\033[44m"
# define C_BACKGROUND_MAGENTA        "\033[45m"
# define C_BACKGROUND_CYAN            "\033[46m"
# define C_BACKGROUND_LIGHT_GRAY        "\033[47m"
# define C_BACKGROUND_DARK_GRAY        "\033[100m"
# define C_BACKGROUND_LIGHT_RED        "\033[101m"
# define C_BACKGROUND_LIGHT_GREEN    "\033[102m"
# define C_BACKGROUND_LIGHT_YELLOW    "\033[103m"
# define C_BACKGROUND_LIGHT_BLUE        "\033[104m"
# define C_BACKGROUND_LIGHT_MAGENTA    "\033[105m"
# define C_BACKGROUND_LIGHT_CYAN        "\033[106m"
# define C_BACKGROUND_WHITE            "\033[107m"
# define C_RESET_BACKGROUND_COLOR    "\033[49m"

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

int				game(t_2048 *wkw);
t_2048		*game_new_piece(t_2048 *wong_kar_wai);
int				check_end_game(t_2048 *wkw);
void			draw_window(t_2048 *wkw);
int 			game_over(void);
void colo(void);
#endif
