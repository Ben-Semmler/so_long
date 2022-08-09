/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:05:02 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/04 16:05:47 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_dimensions(char **mapdata);
int	check_map_border(char **mapdata);

void	check_valid_map(t_gamedata *gamedata)
{
	int	count;

	if (check_map_dimensions(gamedata->mapdata) == 0)
		invalid_map_error(gamedata, "MAP IS NOT RECTANGULAR");
	if (gamedata->player.x == -1)
		invalid_map_error(gamedata, "NO PLAYER");
	if (count_objects("C", gamedata->mapdata) < 1)
		invalid_map_error(gamedata, "LESS THAN ONE COLLECTABLE");
	if (count_objects("E", gamedata->mapdata) < 1)
		invalid_map_error(gamedata, "NO EXIT");
	count = count_objects("01CEP", gamedata->mapdata);
	if (BONUS == 1)
		count += count_objects("KGUDLR", gamedata->mapdata);
	if (count < map_xsize(gamedata->mapdata) * map_ysize(gamedata->mapdata))
		invalid_map_error(gamedata, "UNKNOWN CHARACTERS");
	if (check_map_border(gamedata->mapdata) == 0)
		invalid_map_error(gamedata, "NOT ENCLOSED BY WALLS");
}

void	invalid_map_error(t_gamedata *gamedata, char *reason)
{
	ft_printf("Error\nINVALID MAP: %s\n", reason);
	close_game(gamedata, 0);
}

int	check_map_dimensions(char **mapdata)
{
	int	i;

	i = 0;
	while (mapdata[i] != NULL)
	{
		if (ft_strlen(mapdata[0]) != ft_strlen(mapdata[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_map_border(char **mapdata)
{
	int	i;

	i = 0;
	while (i < map_xsize(mapdata))
	{
		if (mapdata[0][i] != '1')
			return (0);
		if (mapdata[map_ysize(mapdata) - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_ysize(mapdata))
	{
		if (mapdata[i][0] != '1')
			return (0);
		if (mapdata[i][map_xsize(mapdata) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
