/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_collide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:25:54 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/13 18:25:56 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_collision(t_gamedata *gamedata, int keycode)
{
	int		cpos[2];
	char	mappos;

	cpos[0] = gamedata->player.x;
	cpos[1] = gamedata->player.y;
	if (keycode == 0)
		cpos[0]--;
	else if (keycode == 2)
		cpos[0]++;
	else if (keycode == 1)
		cpos[1]++;
	else if (keycode == 13)
		cpos[1]--;
	if (cpos[0] >= 0 && cpos[0] < map_xsize(gamedata->mapdata)
		&& cpos[1] >= 0 && cpos[1] < map_ysize(gamedata->mapdata))
		mappos = gamedata->mapdata[cpos[1]][cpos[0]];
	else
		mappos = '1';
	if (mappos == '1' || mappos == 'G')
		return (0);
	if (mappos == 'C' || mappos == 'K')
		return (2);
	if (mappos == 'E')
		return (3);
	return (1);
}
