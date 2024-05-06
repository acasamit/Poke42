/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:41:46 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 18:42:24 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"
#define WIDTH 832
#define HEIGHT 448

int	game_init2(t_game *game, char *str)
{
	game->line_readed = 0;
	game->want_co = game->zero;
	game->wait_frames = 0;
	game->test.mooving_b = 0;
	game->map->map_path = str;
	game->map->map_file = map_reader(game->map->map_path);
	game->map->map_tab = ft_split(game->map->map_file, '\n');
	game->pikachu_number = 0;
	if (!map_is_sourrounded(game->map->map_tab,
			line_counter(game->map->map_path))
		|| !is_map_achievable(game->map->map_tab,
			line_counter(game->map->map_path), game) || game->n_exit != 1
		|| game->n_player != 1 || game->n_pika < 1)
	{
		ft_printf("Error\nYour map is not correct\n");
		end_program_error(game);
		return (0);
	}
	game->ennemy = NULL;
	game->pika = NULL;
	game->tlist = malloc(sizeof(t_texture));
	return (1);
}

void	set_loop_hook(t_game *game, mlx_t *mlx)
{
	mlx_loop_hook(mlx, update_game, game);
	mlx_loop_hook(mlx, ft_hook, game);
	mlx_loop_hook(mlx, key_hook, game);
	mlx_loop_hook(mlx, win_dialog, game);
	mlx_loop_hook(mlx, take_pika, game);
	mlx_loop_hook(mlx, win_wait, game);
	mlx_loop_hook(mlx, ft_dialog_anim, game);
	mlx_loop_hook(mlx, bike_dialog, game);
	mlx_loop_hook(mlx, ft_moovement_count, game);
	mlx_loop_hook(mlx, ft_print_moove, game);
	mlx_loop_hook(mlx, ft_escape, game);
	mlx_loop_hook(mlx, ft_escape_save, game);
	mlx_loop_hook(mlx, ft_escape_quit, game);
	mlx_loop_hook(mlx, rocket_loop, game);
	mlx_loop_hook(mlx, bike_wait, game);
	mlx_loop_hook(mlx, anim_front_step1, game);
	mlx_loop_hook(mlx, anim_front_step2, game);
	mlx_loop_hook(mlx, anim_back_step1, game);
	mlx_loop_hook(mlx, anim_back_step2, game);
	mlx_loop_hook(mlx, anim_right_step1, game);
	mlx_loop_hook(mlx, anim_right_step2, game);
	mlx_loop_hook(mlx, anim_left_step1, game);
	mlx_loop_hook(mlx, cant_leave, game);
	mlx_loop_hook(mlx, anim_left_step2, game);
	mlx_loop_hook(mlx, ft_open_fight, game);
}

void	set_loop_hook2(t_game *game, mlx_t *mlx)
{
	mlx_loop_hook(mlx, first_fight_wait, game);
	mlx_loop_hook(mlx, deploy_anim, game);
	mlx_loop_hook(mlx, save_anim, game);
	mlx_loop_hook(mlx, save_wait, game);
	mlx_loop_hook(mlx, fight_menu1, game);
	mlx_loop_hook(mlx, fight_menu2, game);
	mlx_loop_hook(mlx, fight_menu3, game);
	mlx_loop_hook(mlx, fight_menu4, game);
	mlx_loop_hook(mlx, fight_menu5, game);
	mlx_loop_hook(mlx, hp_print, game);
	mlx_loop_hook(mlx, select_attack, game);
	mlx_loop_hook(mlx, select_attack2, game);
	mlx_loop_hook(mlx, static_pp_print, game);
	mlx_loop_hook(mlx, pp_print, game);
	mlx_loop_hook(mlx, thunder, game);
	mlx_loop_hook(mlx, quick, game);
	mlx_loop_hook(mlx, bar_anim, game);
	mlx_loop_hook(mlx, ebarm, game);
	mlx_loop_hook(mlx, ebarrm, game);
	mlx_loop_hook(mlx, pbar_anim, game);
	mlx_loop_hook(mlx, pbarm, game);
	mlx_loop_hook(mlx, pbarrm, game);
	mlx_loop_hook(mlx, ebarl, game);
	mlx_loop_hook(mlx, pbarl, game);
	mlx_loop_hook(mlx, ebar_verif2, game);
}

void	set_loop_hook3(t_game *game, mlx_t *mlx)
{
	mlx_loop_hook(mlx, pbar_verif2, game);
	mlx_loop_hook(mlx, ebard, game);
	mlx_loop_hook(mlx, ectofainted, game);
	mlx_loop_hook(mlx, second_fight_wait, game);
	mlx_loop_hook(mlx, third_fight_wait, game);
	mlx_loop_hook(mlx, fourth_fight_wait, game);
	mlx_loop_hook(mlx, fifth_fight_wait, game);
	mlx_loop_hook(mlx, sixth_fight_wait, game);
	mlx_loop_hook(mlx, exp_gain, game);
	mlx_loop_hook(mlx, win_message, game);
	mlx_loop_hook(mlx, rage_message, game);
	mlx_loop_hook(mlx, money_gain, game);
	mlx_loop_hook(mlx, end_combat, game);
	mlx_loop_hook(mlx, ft_do_bar_anim, game);
	mlx_loop_hook(mlx, ft_do_pbar_anim, game);
	mlx_loop_hook(mlx, shadow, game);
	mlx_loop_hook(mlx, curse, game);
	mlx_loop_hook(mlx, ft_do_anim, game);
	mlx_loop_hook(mlx, bool_checker, game);
	game->tlist->icon = mlx_load_png("sprites/mlsc/icon.png");
	mlx_set_icon(mlx, game->tlist->icon);
}

int32_t	main(int ac, char **av)
{
	mlx_t			*mlx;
	static t_game	game = {};

	mlx = NULL;
	game_init(&game);
	if (!game_init2(&game, av[1]) || ac != 2)
		return (0);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx = mlx_init(((line_len(game.map->map_path) - 1) * 64),
			(line_counter(game.map->map_path) * 64), "Poke42", true);
	if (!mlx)
		ft_error();
	game.mlx = mlx;
	game.player_anim = ft_load_sprite(&game);
	game.rocket_anim = ft_load_rocket_sprite(&game);
	ft_load_save(&game);
	menu_load(&game);
	set_loop_hook(&game, mlx);
	set_loop_hook2(&game, mlx);
	set_loop_hook3(&game, mlx);
	mlx_loop(mlx);
	ft_lstclear(&game.ennemy, del, &game);
	ft_lstpikaclear(&game.pika, del, &game);
	end_program(&game);
	return (EXIT_SUCCESS);
}
