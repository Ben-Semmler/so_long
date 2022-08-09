/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:35:33 by bsemmler          #+#    #+#             */
/*   Updated: 2022/01/13 18:35:34 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_player_dir(int keycode)
{
	if (keycode == 0)
		return ('L');
	if (keycode == 2)
		return ('R');
	if (keycode == 1)
		return ('D');
	return ('U');
}
