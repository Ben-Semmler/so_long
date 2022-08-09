/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:48:26 by bsemmler          #+#    #+#             */
/*   Updated: 2021/11/23 16:48:27 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_xsize(char **mapdata)
{
	int	i;

	i = 0;
	while (mapdata[0][i] != '\n' && mapdata[0][i] != 0)
		i++;
	return (i);
}

int	map_ysize(char	**mapdata)
{
	int	i;

	i = 0;
	while (mapdata[i] != NULL)
		i++;
	return (i);
}
