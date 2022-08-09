/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:22:43 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/14 16:22:45 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_player *player, int keycode);
void	check_enemy_collision(t_gamedata *gamedata);

void	move_objects(t_gamedata *gamedata, int keycode)
{
	t_player	*pstates;

	pstates = malloc(sizeof(t_player) * 2);
	pstates[0] = gamedata->player;
	move_player(&gamedata->player, keycode);
	pstates[1] = gamedata->player;
	move_enemies(gamedata, pstates);
	check_enemy_collision(gamedata);
	free(pstates);
}

void	move_player(t_player *player, int keycode)
{
	if (keycode == 0)
		player->x--;
	else if (keycode == 2)
		player->x++;
	else if (keycode == 1)
		player->y++;
	else if (keycode == 13)
		player->y--;
	if (BONUS == 0)
		ft_printf("Steps: %i\n", player->steps);
	player->steps++;
}

void	check_enemy_collision(t_gamedata *gamedata)
{
	int			i;
	t_enemy		*enemies;
	t_player	player;

	enemies = gamedata->enemies;
	player = gamedata->player;
	i = 0;
	while (enemies[i].x != -1)
	{
		if (enemies[i].x == player.x && enemies[i].y == player.y)
			game_lose(gamedata);
		i++;
	}
}
