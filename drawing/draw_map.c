/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:22:11 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:22:13 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_exit(t_gamedata *gamedata, int x, int y);

void	draw_map(t_gamedata *gamedata)
{
	int	x;
	int	y;

	y = 0;
	while (gamedata->mapdata[y] != NULL)
	{
		x = 0;
		while (gamedata->mapdata[y][x] != '\n')
		{
			if (gamedata->mapdata[y][x] == '1')
				draw_sprite(gamedata, &gamedata->textures.w_data,
					x * IMAGE_SIZE, y * IMAGE_SIZE);
			else if (gamedata->mapdata[y][x] == 'E')
				draw_exit(gamedata, x, y);
			else
				draw_sprite(gamedata, &gamedata->textures.b_data,
					x * IMAGE_SIZE, y * IMAGE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_gamedata *gamedata, int x, int y)
{
	if (check_win_conditions(gamedata) == 1)
		draw_sprite(gamedata, &gamedata->textures.ex_data,
			x * IMAGE_SIZE, y * IMAGE_SIZE);
	else
		draw_sprite(gamedata, &gamedata->textures.lex_data,
			x * IMAGE_SIZE, y * IMAGE_SIZE);
}
