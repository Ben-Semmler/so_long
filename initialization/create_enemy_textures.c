/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enemy_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:46:24 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/06 17:46:25 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_enemy_indexes(t_textures *textures);
void	get_enemy_sprites(void *mlx, t_textures *textures);

void	create_enemy_textures(void *mlx, t_textures *textures)
{
	textures->eu_data.imgn = 2;
	textures->ed_data.imgn = 2;
	textures->el_data.imgn = 2;
	textures->er_data.imgn = 2;
	textures->eu_data.imgt = 10;
	textures->ed_data.imgt = 10;
	textures->el_data.imgt = 10;
	textures->er_data.imgt = 10;
	textures->eu_data.imgs = initialize_images(mlx, textures->eu_data.imgn);
	textures->ed_data.imgs = initialize_images(mlx, textures->ed_data.imgn);
	textures->el_data.imgs = initialize_images(mlx, textures->el_data.imgn);
	textures->er_data.imgs = initialize_images(mlx, textures->er_data.imgn);
	initialize_enemy_indexes(textures);
	get_enemy_sprites(mlx, textures);
}

void	initialize_enemy_indexes(t_textures *textures)
{
	textures->eu_data.imgi = 0;
	textures->ed_data.imgi = 0;
	textures->el_data.imgi = 0;
	textures->er_data.imgi = 0;
	textures->eu_data.changed = 1;
	textures->ed_data.changed = 1;
	textures->el_data.changed = 1;
	textures->er_data.changed = 1;
}

void	get_enemy_sprites(void *mlx, t_textures *textures)
{
	int	width;
	int	height;

	textures->eu_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockUp1.xpm", &width, &height);
	textures->eu_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockUp2.xpm", &width, &height);
	textures->ed_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockDown1.xpm", &width, &height);
	textures->ed_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockDown2.xpm", &width, &height);
	textures->el_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockLeft1.xpm", &width, &height);
	textures->el_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockLeft2.xpm", &width, &height);
	textures->er_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockRight1.xpm", &width, &height);
	textures->er_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/enemy/OctorockRight2.xpm", &width, &height);
}
