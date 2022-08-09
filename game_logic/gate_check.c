/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:57:13 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/11 16:57:14 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	gate_check_ixiy(char dir, int *ix, int *iy);

int	player_gate_check(t_gamedata *gamedata)
{
	int	i;
	int	ix;
	int	iy;

	ix = gamedata->player.x;
	iy = gamedata->player.y;
	gate_check_ixiy(gamedata->player.dir, &ix, &iy);
	i = 0;
	while (gamedata->gates[i].x != -1)
	{
		if (gamedata->gates[i].x == ix && gamedata->gates[i].y == iy
			&& gamedata->player.keys >= 1 && gamedata->gates[i].active == 1)
		{
			gamedata->gates[i].active = 0;
			gamedata->player.keys--;
			return (1);
		}
		if (gamedata->gates[i].x == ix && gamedata->gates[i].y == iy
			&& gamedata->gates[i].active == 0)
			return (1);
		i++;
	}
	return (0);
}

int	enemy_gate_check(t_gamedata *gamedata, t_enemy enemy)
{
	int	i;
	int	ix;
	int	iy;

	ix = enemy.x;
	iy = enemy.y;
	gate_check_ixiy(enemy.dir, &ix, &iy);
	i = 0;
	while (gamedata->gates[i].x != -1)
	{
		if (gamedata->gates[i].x == ix && gamedata->gates[i].y == iy
			&& gamedata->gates[i].active == 1)
			return (0);
		i++;
	}
	return (1);
}

void	gate_check_ixiy(char dir, int *ix, int *iy)
{
	if (dir == 'U')
		*iy -= 1;
	else if (dir == 'D')
		*iy += 1;
	else if (dir == 'L')
		*ix -= 1;
	else if (dir == 'R')
		*ix += 1;
}
