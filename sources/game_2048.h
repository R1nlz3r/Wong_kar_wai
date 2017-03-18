/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 10:47:07 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/18 11:19:14 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048
# define GAME_2048

#include <ncurses.h>
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
}					t_2048;

//prototypes

#endif
