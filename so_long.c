/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:40:55 by bsemmler          #+#    #+#             */
/*   Updated: 2021/11/18 16:40:57 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image			*create_images(void	*mlx);

int	main(int argn, char **args)
{
	t_gamedata	gamedata;

	if (argn == 2)
	{
		initialize_game(&gamedata, args[1]);
		mlx_key_hook(gamedata.win, game_logic, &gamedata);
		mlx_loop_hook(gamedata.mlx, increment_counter, &gamedata);
		mlx_hook(gamedata.win, 17, 0L, close_game, &gamedata);
		mlx_loop(gamedata.mlx);
	}
	else
		ft_printf("Error\nNO MAP PROVIDED\n");
}
