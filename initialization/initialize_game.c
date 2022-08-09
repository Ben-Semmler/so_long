/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:12:13 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/14 18:12:14 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_game(t_gamedata *gamedata, char *filename)
{
	gamedata->counter = 0;
	gamedata->gamestate = 0;
	gamedata->mlx = mlx_init();
	gamedata->mapdata = get_map_data(filename);
	gamedata->win = mlx_new_window(gamedata->mlx,
			(map_xsize(gamedata->mapdata)) * IMAGE_SIZE,
			(map_ysize(gamedata->mapdata)) * IMAGE_SIZE + HEADER, "So Long!");
	gamedata->textures = create_textures(gamedata->mlx, gamedata->mapdata);
	gamedata->player = initialize_player(gamedata->mapdata);
	gamedata->collectables = find_collectables(gamedata->mapdata);
	gamedata->keys = find_keys(gamedata->mapdata);
	gamedata->gates = find_gates(gamedata->mapdata);
	gamedata->enemies = find_enemies(gamedata->mapdata);
	check_valid_map(gamedata);
	draw_game(gamedata, 0);
}
