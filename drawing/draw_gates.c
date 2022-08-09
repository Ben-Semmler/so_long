/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:39:20 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:39:21 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_gates(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->gates[i].x != -1)
	{
		if (gamedata->gates[i].active == 1)
			draw_sprite(gamedata, &gamedata->textures.g_data,
				gamedata->gates[i].x * IMAGE_SIZE,
				gamedata->gates[i].y * IMAGE_SIZE);
		i++;
	}
}
