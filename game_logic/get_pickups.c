/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pickups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:30:41 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/13 18:30:42 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_pickups(t_gamedata *gamedata)
{
	get_collectable(gamedata);
	get_key(gamedata);
}
