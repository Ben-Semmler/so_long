/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:37:23 by bsemmler          #+#    #+#             */
/*   Updated: 2021/11/25 17:37:24 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_textures(t_gamedata *gamedata);

int	close_game(t_gamedata *gamedata, int i)
{
	free(gamedata->mlx);
	free(gamedata->win);
	free_textures(gamedata);
	free(gamedata->collectables);
	free(gamedata->keys);
	free(gamedata->gates);
	free(gamedata->enemies);
	i = 0;
	while (gamedata->mapdata[i] != NULL)
	{
		free(gamedata->mapdata[i]);
		i++;
	}
	free(gamedata->mapdata[i]);
	free(gamedata->mapdata);
	exit(1);
}

void	free_textures(t_gamedata *gamedata)
{
	free(gamedata->textures.pu_data.imgs);
	free(gamedata->textures.pd_data.imgs);
	free(gamedata->textures.pl_data.imgs);
	free(gamedata->textures.pr_data.imgs);
	free(gamedata->textures.eu_data.imgs);
	free(gamedata->textures.ed_data.imgs);
	free(gamedata->textures.el_data.imgs);
	free(gamedata->textures.er_data.imgs);
	free(gamedata->textures.c_data.imgs);
	free(gamedata->textures.b_data.imgs);
	free(gamedata->textures.w_data.imgs);
	free(gamedata->textures.ex_data.imgs);
	free(gamedata->textures.lex_data.imgs);
	free(gamedata->textures.k_data.imgs);
	free(gamedata->textures.g_data.imgs);
	free(gamedata->textures.background.imgs);
	free(gamedata->textures.gui_elems.imgs);
	free(gamedata->textures.digits.imgs);
}
