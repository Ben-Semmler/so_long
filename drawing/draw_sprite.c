/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:30:03 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:30:04 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_sprite(t_gamedata *gamedata, t_tex_data *data, int x, int y)
{
	if ((gamedata->counter != 0 && gamedata->counter % data->imgt == 0
			&& data->changed == 0) && BONUS == 1)
	{
		data->imgi++;
		if (data->imgi >= data->imgn)
			data->imgi = 0;
		data->changed = 1;
	}
	mlx_put_image_to_window(gamedata->mlx, gamedata->win,
		data->imgs[data->imgi].img, x, HEADER + y);
}
