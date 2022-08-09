/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:18:29 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:18:31 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(t_gamedata *gamedata)
{
	if (gamedata->player.dir == 'U')
		draw_sprite(gamedata, &gamedata->textures.pu_data,
			gamedata->player.x * IMAGE_SIZE, gamedata->player.y * IMAGE_SIZE);
	else if (gamedata->player.dir == 'D')
		draw_sprite(gamedata, &gamedata->textures.pd_data,
			gamedata->player.x * IMAGE_SIZE, gamedata->player.y * IMAGE_SIZE);
	else if (gamedata->player.dir == 'L')
		draw_sprite(gamedata, &gamedata->textures.pl_data,
			gamedata->player.x * IMAGE_SIZE, gamedata->player.y * IMAGE_SIZE);
	else if (gamedata->player.dir == 'R')
		draw_sprite(gamedata, &gamedata->textures.pr_data,
			gamedata->player.x * IMAGE_SIZE, gamedata->player.y * IMAGE_SIZE);
}
