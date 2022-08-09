/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_background_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:05:21 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/06 18:05:22 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_header(t_tex_data *background, char **mapdata);
void	draw_game_area(t_tex_data *background, char **mapdata);
void	pixel_to_image(t_image *img, int x, int y, int colour);

t_tex_data	create_background_texture(void *mlx, char **mapdata)
{
	t_tex_data	background;

	background.imgn = 1;
	background.imgt = 60;
	background.imgi = 0;
	background.changed = 1;
	background.imgs = malloc(sizeof(t_image));
	background.imgs[0].img = mlx_new_image(mlx,
			(map_xsize(mapdata)) * IMAGE_SIZE,
			(map_ysize(mapdata)) * IMAGE_SIZE + HEADER);
	background.imgs[0].addr = mlx_get_data_addr(background.imgs[0].img,
			&background.imgs[0].bits_per_pixel,
			&background.imgs[0].line_length,
			&background.imgs[0].endian);
	draw_header(&background, mapdata);
	draw_game_area(&background, mapdata);
	return (background);
}

void	draw_header(t_tex_data *background, char **mapdata)
{
	int	ix;
	int	iy;

	ix = 0;
	while (ix < map_xsize(mapdata) * IMAGE_SIZE)
	{
		iy = 0;
		while (iy < HEADER)
		{
			pixel_to_image(&background->imgs[0], ix, iy, 0x00000000);
			iy++;
		}
		ix++;
	}
}

void	draw_game_area(t_tex_data *background, char **mapdata)
{
	int	ix;
	int	iy;

	ix = 0;
	while (ix < map_xsize(mapdata) * IMAGE_SIZE)
	{
		iy = 0;
		while (iy < map_ysize(mapdata) * IMAGE_SIZE)
		{
			pixel_to_image(&background->imgs[0], ix, HEADER + iy, 0x00FCE0A8);
			iy++;
		}
		ix++;
	}
}

void	pixel_to_image(t_image *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}
