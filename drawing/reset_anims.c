/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_anims.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:47:39 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/20 15:47:40 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reset_anims(t_textures *textures)
{
	textures->pu_data.changed = 0;
	textures->pd_data.changed = 0;
	textures->pl_data.changed = 0;
	textures->pr_data.changed = 0;
	textures->eu_data.changed = 0;
	textures->ed_data.changed = 0;
	textures->el_data.changed = 0;
	textures->er_data.changed = 0;
	textures->c_data.changed = 0;
	textures->b_data.changed = 0;
	textures->w_data.changed = 0;
	textures->ex_data.changed = 0;
}
