/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemmler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:31:38 by bsemmler          #+#    #+#             */
/*   Updated: 2021/12/13 16:31:39 by bsemmler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_player
{
	int		x;
	int		y;
	int		steps;
	int		keys;
	char	dir;
}	t_player;

typedef struct s_collectable
{
	int	x;
	int	y;
	int	collected;
}	t_collectable;

typedef struct s_key
{
	int	x;
	int	y;
	int	collected;
}	t_key;

typedef struct s_gate
{
	int	x;
	int	y;
	int	active;
}	t_gate;

typedef struct s_enemy
{
	int		x;
	int		y;
	char	dir;
}	t_enemy;

typedef struct s_tex_data
{
	int		imgn;
	int		imgt;
	int		imgi;
	int		changed;
	t_image	*imgs;
}	t_tex_data;

typedef struct s_textures
{
	t_tex_data	pu_data;
	t_tex_data	pd_data;
	t_tex_data	pl_data;
	t_tex_data	pr_data;
	t_tex_data	eu_data;
	t_tex_data	ed_data;
	t_tex_data	el_data;
	t_tex_data	er_data;
	t_tex_data	c_data;
	t_tex_data	b_data;
	t_tex_data	w_data;
	t_tex_data	ex_data;
	t_tex_data	lex_data;
	t_tex_data	k_data;
	t_tex_data	g_data;
	t_tex_data	background;
	t_tex_data	gui_elems;
	t_tex_data	digits;
}	t_textures;

typedef struct s_gamedata
{
	int				counter;
	int				gamestate;
	void			*mlx;
	void			*win;
	t_textures		textures;
	t_player		player;
	t_collectable	*collectables;
	t_key			*keys;
	t_gate			*gates;
	t_enemy			*enemies;
	char			*mapname;
	char			**mapdata;
}	t_gamedata;

void			initialize_game(t_gamedata *gamedata, char *filename);

char			**get_map_data(char *filename);
int				map_xsize(char	**mapdata);
int				map_ysize(char	**mapdata);

t_textures		create_textures(void *mlx, char **mapdata);
t_tex_data		create_gui_textures(void *mlx);
t_tex_data		create_digit_textures(void *mlx);
void			create_player_textures(void *mlx, t_textures *textures);
void			create_enemy_textures(void *mlx, t_textures *textures);
t_tex_data		create_background_texture(void *mlx, char **mapdata);
t_image			*initialize_images(void *mlx, int n);

t_player		initialize_player(char **mapdata);

t_collectable	*find_collectables(char **mapdata);
t_key			*find_keys(char **mapdata);
t_gate			*find_gates(char **mapdata);
t_enemy			*find_enemies(char **mapdata);
int				count_objects(char *tofind, char **mapdata);

void			check_valid_map(t_gamedata *gamedata);
void			invalid_map_error(t_gamedata *gamedata, char *reason);

void			draw_game(t_gamedata *gamedata, int mode);
void			draw_map(t_gamedata *gamedata);
void			draw_gates(t_gamedata *gamedata);
void			draw_collectables(t_gamedata *gamedata);
void			draw_keys(t_gamedata *gamedata);
void			draw_enemies(t_gamedata *gamedata);
void			draw_player(t_gamedata *gamedata);
void			draw_gui(t_gamedata *gamedata);
void			reset_anims(t_textures *textures);
int				increment_counter(t_gamedata *gamedata);
void			draw_sprite(t_gamedata *gdata, t_tex_data *data, int x, int y);

int				game_logic(int keycode, t_gamedata *gamedata);
char			get_player_dir(int keycode);
int				check_map_collision(t_gamedata *gamedata, int keycode);
int				player_gate_check(t_gamedata *gamedata);
int				enemy_gate_check(t_gamedata *gamedata, t_enemy enemy);
void			move_objects(t_gamedata *gamedata, int keycode);
void			move_enemies(t_gamedata *gamedata, t_player *pstates);
void			get_pickups(t_gamedata *gamedata);
void			get_collectable(t_gamedata *gamedata);
void			get_key(t_gamedata *gamedata);
int				check_win_conditions(t_gamedata	*gamedata);
void			restart_game(t_gamedata	*gamedata);

int				close_game(t_gamedata *gamedata, int i);

void			game_lose(t_gamedata *gamedata);
void			game_win(t_gamedata *gamedata);

#endif
