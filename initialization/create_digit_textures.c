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

void	get_digit_sprites(void *mlx, t_tex_data digits);

t_tex_data	create_digit_textures(void *mlx)
{
	t_tex_data	digits;
	int			i;

	digits.imgn = 10;
	digits.imgt = 0;
	digits.imgi = 0;
	digits.changed = 1;
	digits.imgs = malloc(sizeof(t_image) * digits.imgn);
	i = 0;
	while (i < digits.imgn)
	{
		digits.imgs[i].img = mlx_new_image(mlx, IMAGE_SIZE / 2, IMAGE_SIZE / 2);
		digits.imgs[i].addr = mlx_get_data_addr(digits.imgs[i].img,
				&digits.imgs[0].bits_per_pixel,
				&digits.imgs[0].line_length,
				&digits.imgs[0].endian);
		i++;
	}
	get_digit_sprites(mlx, digits);
	return (digits);
}

void	get_digit_sprites(void *mlx, t_tex_data digits)
{
	int	width;
	int	height;

	digits.imgs[0].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Zero.xpm", &width, &height);
	digits.imgs[1].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/One.xpm", &width, &height);
	digits.imgs[2].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Two.xpm", &width, &height);
	digits.imgs[3].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Three.xpm", &width, &height);
	digits.imgs[4].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Four.xpm", &width, &height);
	digits.imgs[5].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Five.xpm", &width, &height);
	digits.imgs[6].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Six.xpm", &width, &height);
	digits.imgs[7].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Seven.xpm", &width, &height);
	digits.imgs[8].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Eight.xpm", &width, &height);
	digits.imgs[9].img = mlx_xpm_file_to_image(mlx,
			"sprites/bonus/gui/Nine.xpm", &width, &height);
}
