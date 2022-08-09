/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:28:03 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 17:28:04 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reset_player(t_gamedata *gamedata);
void	reset_enemies(t_gamedata *gamedata);
void	reset_misc(t_gamedata *gamedata);

void	restart_game(t_gamedata	*gamedata)
{
	reset_player(gamedata);
	reset_enemies(gamedata);
	reset_misc(gamedata);
	gamedata->gamestate = 0;
	draw_game(gamedata, 0);
}

void	reset_player(t_gamedata *gamedata)
{
	int	ix;
	int	iy;

	iy = 0;
	while (gamedata->mapdata[iy] != NULL)
	{
		ix = 0;
		while (gamedata->mapdata[iy][ix] != '\n'
			&& gamedata->mapdata[iy][ix] != 0)
		{
			if (gamedata->mapdata[iy][ix] == 'P')
			{
				gamedata->player.x = ix;
				gamedata->player.y = iy;
			}
			ix++;
		}
		iy++;
	}
	gamedata->player.keys = 0;
	gamedata->player.steps = 1;
	gamedata->player.dir = 'D';
}

void	reset_enemies(t_gamedata *gamedata)
{
	int	i;
	int	ix;
	int	iy;

	i = 0;
	iy = 0;
	while (gamedata->mapdata[iy] != NULL)
	{
		ix = 0;
		while (gamedata->mapdata[iy][ix] != '\n')
		{
			if (gamedata->mapdata[iy][ix] == 'U'
					|| gamedata->mapdata[iy][ix] == 'D'
					|| gamedata->mapdata[iy][ix] == 'L'
					|| gamedata->mapdata[iy][ix] == 'R')
			{
				gamedata->enemies[i].x = ix;
				gamedata->enemies[i].y = iy;
				gamedata->enemies[i].dir = gamedata->mapdata[iy][ix];
				i++;
			}
			ix++;
		}
		iy++;
	}
}

void	reset_misc(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->collectables[i].x != -1)
	{
		gamedata->collectables[i].collected = 0;
		i++;
	}
	i = 0;
	while (gamedata->keys[i].x != -1)
	{
		gamedata->keys[i].collected = 0;
		i++;
	}
	i = 0;
	while (gamedata->gates[i].x != -1)
	{
		gamedata->gates[i].active = 1;
		i++;
	}
}
