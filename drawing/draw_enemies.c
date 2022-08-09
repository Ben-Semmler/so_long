/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:29:03 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:29:04 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_enemies(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->enemies[i].x != -1)
	{
		if (gamedata->enemies[i].dir == 'U')
			draw_sprite(gamedata, &gamedata->textures.eu_data,
				gamedata->enemies[i].x * IMAGE_SIZE,
				gamedata->enemies[i].y * IMAGE_SIZE);
		if (gamedata->enemies[i].dir == 'D')
			draw_sprite(gamedata, &gamedata->textures.ed_data,
				gamedata->enemies[i].x * IMAGE_SIZE,
				gamedata->enemies[i].y * IMAGE_SIZE);
		if (gamedata->enemies[i].dir == 'L')
			draw_sprite(gamedata, &gamedata->textures.el_data,
				gamedata->enemies[i].x * IMAGE_SIZE,
				gamedata->enemies[i].y * IMAGE_SIZE);
		if (gamedata->enemies[i].dir == 'R')
			draw_sprite(gamedata, &gamedata->textures.er_data,
				gamedata->enemies[i].x * IMAGE_SIZE,
				gamedata->enemies[i].y * IMAGE_SIZE);
		i++;
	}
}
