/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:26:03 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:26:04 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_keys(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->keys[i].x != -1)
	{
		if (gamedata->keys[i].collected != 1)
			draw_sprite(gamedata, &gamedata->textures.k_data,
				gamedata->keys[i].x * IMAGE_SIZE,
				gamedata->keys[i].y * IMAGE_SIZE);
		i++;
	}
}
