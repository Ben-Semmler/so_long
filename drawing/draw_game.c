/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:09:13 by bsemmler          #+#    #+#             */
/*   Updated: 2021/11/18 17:09:15 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <signal.h>

void	draw_game(t_gamedata *gamedata, int mode)
{
	if (mode == 0)
	{
		mlx_clear_window(gamedata->mlx, gamedata->win);
		draw_sprite(gamedata, &gamedata->textures.background, 0, -HEADER);
	}
	draw_map(gamedata);
	draw_gates(gamedata);
	draw_collectables(gamedata);
	draw_keys(gamedata);
	draw_enemies(gamedata);
	draw_player(gamedata);
	if (BONUS == 1)
		draw_gui(gamedata);
	reset_anims(&gamedata->textures);
}
