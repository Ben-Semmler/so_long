/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:42:31 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/06 16:42:32 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialize_player_indexes(t_textures *textures);
void	get_player_sprites(void *mlx, t_textures *textures);

void	create_player_textures(void *mlx, t_textures *textures)
{
	textures->pu_data.imgn = 2;
	textures->pd_data.imgn = 2;
	textures->pl_data.imgn = 2;
	textures->pr_data.imgn = 2;
	textures->pu_data.imgt = 30;
	textures->pd_data.imgt = 30;
	textures->pl_data.imgt = 30;
	textures->pr_data.imgt = 30;
	textures->pu_data.imgs = initialize_images(mlx, textures->pu_data.imgn);
	textures->pd_data.imgs = initialize_images(mlx, textures->pd_data.imgn);
	textures->pl_data.imgs = initialize_images(mlx, textures->pl_data.imgn);
	textures->pr_data.imgs = initialize_images(mlx, textures->pr_data.imgn);
	initialize_player_indexes(textures);
	get_player_sprites(mlx, textures);
}

void	initialize_player_indexes(t_textures *textures)
{
	textures->pu_data.imgi = 0;
	textures->pd_data.imgi = 0;
	textures->pl_data.imgi = 0;
	textures->pr_data.imgi = 0;
	textures->pu_data.changed = 1;
	textures->pd_data.changed = 1;
	textures->pl_data.changed = 1;
	textures->pr_data.changed = 1;
}

void	get_player_sprites(void *mlx, t_textures *textures)
{
	int	width;
	int	height;

	textures->pu_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkUp1.xpm", &width, &height);
	textures->pu_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkUp2.xpm", &width, &height);
	textures->pd_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkDown1.xpm", &width, &height);
	textures->pd_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkDown2.xpm", &width, &height);
	textures->pl_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkLeft1.xpm", &width, &height);
	textures->pl_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkLeft2.xpm", &width, &height);
	textures->pr_data.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkRight1.xpm", &width, &height);
	textures->pr_data.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/player/LinkRight2.xpm", &width, &height);
}
