/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_conditions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:34:47 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/14 16:34:49 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_win_conditions(t_gamedata	*gamedata)
{
	int	i;

	i = 0;
	while (gamedata->collectables[i].x != -1
		&& gamedata->collectables[i].collected == 1)
		i++;
	if (gamedata->collectables[i].x == -1)
		return (1);
	return (0);
}
