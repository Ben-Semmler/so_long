/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:56:14 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/20 15:56:15 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	increment_counter(t_gamedata *gamedata)
{
	gamedata->counter++;
	draw_game(gamedata, 1);
	return (0);
}
