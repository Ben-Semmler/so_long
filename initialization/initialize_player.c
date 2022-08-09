/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:44:03 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/14 16:44:04 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_player	initialize_player(char **mapdata)
{
	t_player	player;
	int			ix;
	int			iy;

	player.x = -1;
	iy = 0;
	while (mapdata[iy] != NULL)
	{
		ix = 0;
		while (mapdata[iy][ix] != 0)
		{
			if (mapdata[iy][ix] == 'P')
			{
				player.x = ix;
				player.y = iy;
				player.steps = 1;
				player.dir = 'D';
				player.keys = 0;
			}
			ix++;
		}
		iy++;
	}
	return (player);
}
