/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:40:41 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/07 15:40:42 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_collectable	*find_collectables(char **mapdata)
{
	t_collectable	*data;
	int				i;
	int				ixy[2];

	i = 0;
	data = malloc(sizeof(t_collectable) * (count_objects("C", mapdata) + 1));
	ixy[1] = 0;
	while (mapdata[ixy[1]] != NULL)
	{
		ixy[0] = 0;
		while (mapdata[ixy[1]][ixy[0]] != 0)
		{
			if (mapdata[ixy[1]][ixy[0]] == 'C')
			{
				data[i].x = ixy[0];
				data[i].y = ixy[1];
				data[i].collected = 0;
				i++;
			}
			ixy[0]++;
		}
		ixy[1]++;
	}
	data[i].x = -1;
	return (data);
}

t_key	*find_keys(char **mapdata)
{
	t_key	*data;
	int		i;
	int		ixy[2];

	i = 0;
	data = malloc(sizeof(t_key) * (count_objects("K", mapdata) + 1));
	ixy[1] = 0;
	while (mapdata[ixy[1]] != NULL)
	{
		ixy[0] = 0;
		while (mapdata[ixy[1]][ixy[0]] != 0)
		{
			if (mapdata[ixy[1]][ixy[0]] == 'K')
			{
				data[i].x = ixy[0];
				data[i].y = ixy[1];
				data[i].collected = 0;
				i++;
			}
			ixy[0]++;
		}
		ixy[1]++;
	}
	data[i].x = -1;
	return (data);
}

t_gate	*find_gates(char **mapdata)
{
	t_gate	*data;
	int		i;
	int		ixy[2];

	i = 0;
	data = malloc(sizeof(t_gate) * (count_objects("G", mapdata) + 1));
	ixy[1] = 0;
	while (mapdata[ixy[1]] != NULL)
	{
		ixy[0] = 0;
		while (mapdata[ixy[1]][ixy[0]] != 0)
		{
			if (mapdata[ixy[1]][ixy[0]] == 'G')
			{
				data[i].x = ixy[0];
				data[i].y = ixy[1];
				data[i].active = 1;
				i++;
			}
			ixy[0]++;
		}
		ixy[1]++;
	}
	data[i].x = -1;
	return (data);
}

t_enemy	*find_enemies(char **mapdata)
{
	int		i[3];
	t_enemy	*enemies;

	enemies = malloc(sizeof(t_enemy) * (1 + count_objects("UDLR", mapdata)));
	i[2] = 0;
	i[1] = 0;
	while (mapdata[i[1]] != NULL)
	{
		i[0] = 0;
		while (mapdata[i[1]][i[0]] != 0)
		{
			if (mapdata[i[1]][i[0]] == 'U' || mapdata[i[1]][i[0]] == 'D'
				|| mapdata[i[1]][i[0]] == 'L' || mapdata[i[1]][i[0]] == 'R')
			{
				enemies[i[2]].x = i[0];
				enemies[i[2]].y = i[1];
				enemies[i[2]].dir = mapdata[i[1]][i[0]];
				i[2]++;
			}
			i[0]++;
		}
		i[1]++;
	}
	enemies[i[2]].x = -1;
	return (enemies);
}

int	count_objects(char *tofind, char **mapdata)
{
	int	i;
	int	ix;
	int	iy;
	int	count;

	i = 0;
	count = 0;
	while (tofind[i])
	{
		iy = 0;
		while (mapdata[iy] != NULL)
		{
			ix = 0;
			while (mapdata[iy][ix] != 0)
			{
				if (mapdata[iy][ix] == tofind[i])
					count++;
				ix++;
			}
			iy++;
		}
		i++;
	}
	return (count);
}
