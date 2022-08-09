/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:22:04 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/13 16:22:05 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	boringstuff1(t_textures *textures);
void	boringstuff2(t_textures *textures);
void	get_images_from_xpm(void *mlx, t_textures *textures);

t_textures	create_textures(void *mlx, char **mapdata)
{
	t_textures	textures;

	textures.gui_elems = create_gui_textures(mlx);
	textures.digits = create_digit_textures(mlx);
	create_player_textures(mlx, &textures);
	create_enemy_textures(mlx, &textures);
	boringstuff1(&textures);
	boringstuff2(&textures);
	textures.c_data.imgs = initialize_images(mlx, textures.c_data.imgn);
	textures.b_data.imgs = initialize_images(mlx, textures.b_data.imgn);
	textures.w_data.imgs = initialize_images(mlx, textures.w_data.imgn);
	textures.ex_data.imgs = initialize_images(mlx, textures.ex_data.imgn);
	textures.lex_data.imgs = initialize_images(mlx, textures.lex_data.imgn);
	textures.k_data.imgs = initialize_images(mlx, textures.k_data.imgn);
	textures.g_data.imgs = initialize_images(mlx, textures.g_data.imgn);
	get_images_from_xpm(mlx, &textures);
	textures.background = create_background_texture(mlx, mapdata);
	return (textures);
}

void	boringstuff1(t_textures *textures)
{
	textures->c_data.imgn = 1;
	textures->b_data.imgn = 1;
	textures->w_data.imgn = 1;
	textures->ex_data.imgn = 1;
	textures->lex_data.imgn = 1;
	textures->k_data.imgn = 1;
	textures->g_data.imgn = 1;
	textures->c_data.imgt = 1;
	textures->b_data.imgt = 1;
	textures->w_data.imgt = 1;
	textures->ex_data.imgt = 1;
	textures->lex_data.imgt = 1;
	textures->k_data.imgt = 1;
	textures->g_data.imgt = 1;
}

void	boringstuff2(t_textures *textures)
{
	textures->c_data.imgi = 0;
	textures->b_data.imgi = 0;
	textures->w_data.imgi = 0;
	textures->ex_data.imgi = 0;
	textures->lex_data.imgi = 0;
	textures->k_data.imgi = 0;
	textures->g_data.imgi = 0;
	textures->c_data.changed = 1;
	textures->b_data.changed = 1;
	textures->w_data.changed = 1;
	textures->ex_data.changed = 1;
	textures->lex_data.changed = 1;
	textures->k_data.changed = 1;
	textures->g_data.changed = 1;
}

void	get_images_from_xpm(void *mlx, t_textures *textures)
{
	int		width;
	int		height;

	textures->c_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/Rupee.xpm", &width, &height);
	textures->b_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/Background.xpm", &width, &height);
	textures->w_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/Wall.xpm", &width, &height);
	textures->ex_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/Exit.xpm", &width, &height);
	textures->lex_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/LockedExit.xpm", &width, &height);
	textures->k_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/Key.xpm", &width, &height);
	textures->g_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/Gate.xpm", &width, &height);
}
