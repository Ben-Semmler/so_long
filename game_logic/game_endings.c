/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_endings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:34:20 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/13 17:34:21 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_lose(t_gamedata *gamedata)
{
	if (BONUS == 0)
		ft_printf("\n---YOU LOSE---\n");
	gamedata->gamestate = 1;
}

void	game_win(t_gamedata *gamedata)
{
	if (BONUS == 0)
		ft_printf("\n---YOU WIN!---\nSteps Taken: %i\n",
			gamedata->player.steps - 1);
	gamedata->gamestate = 2;
}
