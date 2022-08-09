/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_digit_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:35:51 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/10 16:35:51 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_gui_sprites(void *mlx, t_tex_data digits);

t_tex_data	create_gui_textures(void *mlx)
{
	t_tex_data	gui_elems;
	int			i;

	gui_elems.imgn = 5;
	gui_elems.imgt = 0;
	gui_elems.imgi = 0;
	gui_elems.changed = 1;
	gui_elems.imgs = malloc(sizeof(t_image) * gui_elems.imgn);
	i = 0;
	while (i < gui_elems.imgn)
	{
		gui_elems.imgs[i].img = mlx_new_image(mlx, IMAGE_SIZE / 2,
				IMAGE_SIZE / 2);
		gui_elems.imgs[i].addr = mlx_get_data_addr(gui_elems.imgs[i].img,
				&gui_elems.imgs[0].bits_per_pixel,
				&gui_elems.imgs[0].line_length,
				&gui_elems.imgs[0].endian);
		i++;
	}
	get_gui_sprites(mlx, gui_elems);
	return (gui_elems);
}

void	get_gui_sprites(void *mlx, t_tex_data digits)
{
	int	width;
	int	height;

	digits.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/StepIcon.xpm", &width, &height);
	digits.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/KeyIcon.xpm", &width, &height);
	digits.imgs[2].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/X.xpm", &width, &height);
	digits.imgs[3].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Lose.xpm", &width, &height);
	digits.imgs[4].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Win.xpm", &width, &height);
}
