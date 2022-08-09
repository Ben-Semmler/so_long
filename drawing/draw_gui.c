/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:12:37 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/04 18:12:39 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_steps(t_gamedata *gamedata);
void	draw_key_num(t_gamedata *gamedata);
void	draw_ending(t_gamedata *gamedata);

void	draw_gui(t_gamedata *gamedata)
{
	draw_steps(gamedata);
	if (gamedata->gamestate == 0)
		draw_key_num(gamedata);
	else
		draw_ending(gamedata);
}

void	draw_steps(t_gamedata *gamedata)
{
	int		i;
	char	*step_a;

	mlx_put_image_to_window(gamedata->mlx, gamedata->win,
		gamedata->textures.gui_elems.imgs[0].img, 0, 0);
	mlx_put_image_to_window(gamedata->mlx, gamedata->win,
		gamedata->textures.gui_elems.imgs[2].img, IMAGE_SIZE / 2, 0);
	step_a = ft_itoa(gamedata->player.steps - 1);
	i = 0;
	while ((size_t)i < ft_strlen(step_a))
	{
		mlx_put_image_to_window(gamedata->mlx, gamedata->win,
			gamedata->textures.digits.imgs[step_a[i] - '0'].img,
			i * (IMAGE_SIZE / 2) + IMAGE_SIZE, 0);
		i++;
	}
}

void	draw_key_num(t_gamedata *gamedata)
{
	int		i;
	char	*keys_a;

	mlx_put_image_to_window(gamedata->mlx, gamedata->win,
		gamedata->textures.gui_elems.imgs[1].img, 0, IMAGE_SIZE / 2);
	mlx_put_image_to_window(gamedata->mlx, gamedata->win,
		gamedata->textures.gui_elems.imgs[2].img,
		IMAGE_SIZE / 2, IMAGE_SIZE / 2);
	keys_a = ft_itoa(gamedata->player.keys);
	i = 0;
	while ((size_t)i < ft_strlen(keys_a))
	{
		mlx_put_image_to_window(gamedata->mlx, gamedata->win,
			gamedata->textures.digits.imgs[keys_a[i] - '0'].img,
			i * (IMAGE_SIZE / 2) + IMAGE_SIZE, IMAGE_SIZE / 2);
		i++;
	}
}

void	draw_ending(t_gamedata *gamedata)
{
	if (gamedata->gamestate == 1)
		mlx_put_image_to_window(gamedata->mlx, gamedata->win,
			gamedata->textures.gui_elems.imgs[3].img,
			map_xsize(gamedata->mapdata) * IMAGE_SIZE / 2
			- 4 * (IMAGE_SIZE / 2), IMAGE_SIZE / 2);
	else
		mlx_put_image_to_window(gamedata->mlx, gamedata->win,
			gamedata->textures.gui_elems.imgs[4].img,
			map_xsize(gamedata->mapdata) * IMAGE_SIZE / 2
			- 4 * (IMAGE_SIZE / 2), IMAGE_SIZE / 2);
}
