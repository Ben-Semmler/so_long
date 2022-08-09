/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:47:23 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/06 16:47:24 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image	*initialize_images(void *mlx, int n)
{
	int		i;
	t_image	*imgs;

	imgs = malloc(sizeof(t_image) * n);
	i = 0;
	while (i < n)
	{
		imgs[i].img = mlx_new_image(mlx, IMAGE_SIZE, IMAGE_SIZE);
		imgs[i].addr = mlx_get_data_addr(imgs[i].img, &imgs[0].bits_per_pixel,
				&imgs[0].line_length, &imgs[0].endian);
		i++;
	}
	return (imgs);
}
