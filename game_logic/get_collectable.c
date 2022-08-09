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

void	get_collectable(t_gamedata *gamedata)
{
	int	i;

	i = 0;
	while (gamedata->collectables[i].x != -1
		&& (gamedata->collectables[i].x != gamedata->player.x
			|| gamedata->collectables[i].y != gamedata->player.y))
		i++;
	if (gamedata->collectables[i].x != -1)
		gamedata->collectables[i].collected = 1;
}
