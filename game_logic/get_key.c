/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collectable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:30:03 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/14 16:30:05 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_key(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->keys[i].x != -1
		&& (gamedata->keys[i].x != gamedata->player.x
			|| gamedata->keys[i].y != gamedata->player.y))
		i++;
	if (gamedata->keys[i].x != -1 && gamedata->keys[i].collected == 0)
	{
		gamedata->keys[i].collected = 1;
		gamedata->player.keys++;
	}
}
