NAME = so_long

FILES	= so_long.c\
		initialization/initialize_game.c\
		initialization/get_map_data.c\
		initialization/create_textures.c\
		initialization/create_gui_textures.c\
		initialization/create_digit_textures.c\
		initialization/create_player_textures.c\
		initialization/create_enemy_textures.c\
		initialization/create_background_texture.c\
		initialization/initialize_images.c\
		initialization/initialize_player.c\
		initialization/find_objects.c\
		initialization/check_valid_map.c\
		game_logic/game_logic.c\
		game_logic/get_player_dir.c\
		game_logic/check_map_collision.c\
		game_logic/gate_check.c\
		game_logic/move_objects.c\
		game_logic/move_enemies.c\
		game_logic/get_pickups.c\
		game_logic/get_collectable.c\
		game_logic/get_key.c\
		game_logic/check_win_conditions.c\
		game_logic/game_endings.c\
		game_logic/restart_game.c\
		drawing/draw_game.c\
		drawing/draw_map.c\
		drawing/draw_gates.c\
		drawing/draw_collectables.c\
		drawing/draw_keys.c\
		drawing/draw_enemies.c\
		drawing/draw_player.c\
		drawing/draw_gui.c\
		drawing/draw_sprite.c\
		drawing/reset_anims.c\
		drawing/increment_counter.c\
		misc/map_size.c\
		misc/close_game.c

c_flags = -Wall -Werror -Wextra -D IMAGE_SIZE=64 -Lmlx -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(OBJ): %.c
	gcc -Wall -Werror -Wextra -Iminilibx -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C libft
	gcc $(c_flags) -D BONUS=0 -D HEADER=0 -o $(NAME) libft/libft.a $(FILES)
	$(MAKE) -C libft fclean

bonus: $(OBJ)
	$(MAKE) -C libft
	gcc $(c_flags) -D BONUS=1 -D HEADER=64 -o $(NAME) libft/libft.a $(FILES)
	$(MAKE) -C libft fclean

fclean:
	rm -f so_long

re: fclean all

norm:
	echo "\n\n\n\n\n\n\n\n\n"
	norminette so_long.h $(FILES)

.PHONY: all clean fclean re bonus norm