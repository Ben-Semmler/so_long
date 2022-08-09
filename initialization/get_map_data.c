/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:43:05 by bsemmler          #+#    #+#             */
/*   Updated: 2021/11/18 16:43:07 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>

char		*check_term(char *line);
static char	**add_new_line(char **mapdata, char *line, int count);

char	**get_map_data(char *filename)
{
	char	**mapdata;
	char	*line;
	int		count;
	int		fd;

	mapdata = malloc(sizeof(char *) * 2);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	mapdata[0] = line;
	count = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			line = check_term(line);
		mapdata = add_new_line(mapdata, line, count);
		count++;
	}
	return (mapdata);
}

char	*check_term(char *line)
{
	char	*temp;

	if (line != NULL)
	{
		if (line[ft_strlen(line) - 1] != '\n')
		{
			temp = malloc(ft_strlen(line) + 1);
			temp = ft_strdup(line);
			temp[ft_strlen(line)] = '\n';
			temp[ft_strlen(line) + 1] = 0;
			free(line);
			line = temp;
		}
	}
	return (line);
}

static char	**add_new_line(char **mapdata, char *line, int count)
{
	int		i;
	char	**tempdata;

	tempdata = mapdata;
	mapdata = malloc(sizeof(char *) * count + 1);
	i = 0;
	while (i < count)
	{
		mapdata[i] = ft_strdup(tempdata[i]);
		i++;
	}
	if (!line)
		mapdata[i] = NULL;
	else
		mapdata[i] = ft_strdup(line);
	free(tempdata);
	return (mapdata);
}
