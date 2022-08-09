/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:08:22 by bsemmler          #+#    #+#             */
/*   Updated: 2021/11/18 17:08:23 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"

int	game_logic(int keycode, t_gamedata *gamedata)
{
	int	collision;

	if ((keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		&& gamedata->gamestate == 0)
	{
		gamedata->player.dir = get_player_dir(keycode);
		collision = check_map_collision(gamedata, keycode);
		if (collision != 0 || player_gate_check(gamedata) == 1)
		{
			move_objects(gamedata, keycode);
			if (collision == 2)
				get_pickups(gamedata);
			else if (collision == 3)
			{
				if (check_win_conditions(gamedata) == 1)
					game_win(gamedata);
			}
		}
	}
	else if (keycode == 15 && BONUS == 1)
		restart_game(gamedata);
	else if (keycode == 53)
		close_game(gamedata, 1);
	return (1);
}
