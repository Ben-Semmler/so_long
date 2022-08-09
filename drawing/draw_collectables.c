/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:25:14 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:25:15 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_collectables(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->collectables[i].x != -1)
	{
		if (gamedata->collectables[i].collected != 1)
			draw_sprite(gamedata, &gamedata->textures.c_data,
				gamedata->collectables[i].x * IMAGE_SIZE,
				gamedata->collectables[i].y * IMAGE_SIZE);
		i++;
	}
}
