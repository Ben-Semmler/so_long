/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:36:54 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/07 16:36:55 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_enemy	advance_enemy(t_enemy enemy);
char	change_dir(char dir);
t_enemy	enemy_flip(t_enemy enemy, char **mapdata);
void	check_phase(t_enemy *estates, t_player *pstates, t_gamedata *gamedata);

void	move_enemies(t_gamedata *gamedata, t_player *pstates)
{
	int		i;
	t_enemy	newpos;
	t_enemy	*enemies;
	t_enemy	*estates;

	i = 0;
	estates = malloc(sizeof(t_enemy) * 2);
	enemies = gamedata->enemies;
	while (enemies[i].x != -1)
	{
		estates[0] = enemies[i];
		newpos = advance_enemy(enemies[i]);
		if (gamedata->mapdata[newpos.y][newpos.x] == '1'
			|| enemy_gate_check(gamedata, enemies[i]) == 0)
		{
			enemies[i].dir = change_dir(enemies[i].dir);
			newpos = enemy_flip(enemies[i], gamedata->mapdata);
		}
		enemies[i] = newpos;
		estates[1] = enemies[i];
		check_phase(estates, pstates, gamedata);
		i++;
	}
	free(estates);
}

t_enemy	advance_enemy(t_enemy enemy)
{
	t_enemy	newpos;

	newpos = enemy;
	if (enemy.dir == 'U')
		newpos.y--;
	if (enemy.dir == 'D')
		newpos.y++;
	if (enemy.dir == 'L')
		newpos.x--;
	if (enemy.dir == 'R')
		newpos.x++;
	return (newpos);
}

t_enemy	enemy_flip(t_enemy enemy, char **mapdata)
{
	t_enemy	newpos;

	newpos = advance_enemy(enemy);
	if (mapdata[newpos.y][newpos.x] == '1')
		newpos = enemy;
	return (newpos);
}

char	change_dir(char dir)
{
	if (dir == 'U')
		return ('D');
	if (dir == 'D')
		return ('U');
	if (dir == 'L')
		return ('R');
	if (dir == 'R')
		return ('L');
	return (0);
}

void	check_phase(t_enemy *estates, t_player *pstates, t_gamedata *gamedata)
{
	if (estates[0].x == pstates[1].x
		&& estates[0].y == pstates[1].y)
	{
		if (estates[1].x == pstates[0].x
			&& estates[1].y == pstates[0].y)
			game_lose(gamedata);
	}
}
