/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pow_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:29:23 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/19 18:44:28 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_pow_2(int value)
{
	int		pow2;

	pow2 = 2;
	if (value < 2)
		return (1);
	while (value != pow2 && pow2 <= 65536)
		pow2 *= 2;
	if (value == pow2)
		return (0);
	return (1);
}
