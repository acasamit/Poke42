/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/11/28 20:17:32 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX42_H
# define MLX42_H

# include "include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_co
{
	int				x;
	int				y;
}					t_co;

typedef struct s_anim
{
	mlx_image_t		*front;
	mlx_image_t		*left;
	mlx_image_t		*right;
	mlx_image_t		*back;
	mlx_image_t		*wleft;
	mlx_image_t		*wright;
	mlx_image_t		*wback1;
	mlx_image_t		*wback2;
	mlx_image_t		*wfront1;
	mlx_image_t		*wfront2;
}					t_anim;

typedef struct s_open_fight
{
	mlx_image_t		*current_frame;
	mlx_image_t		*back_img;
}					t_open_fight;

typedef struct s_first
{
	bool			first1;
	bool			first2;
	bool			first3;
	bool			first4;
}					t_first;

typedef struct s_map
{
	char			*map_file;
	char			*map_path;
	char			**map_tab;
}					t_map;

typedef struct s_menu
{
	bool			is_escape;
	bool			is_dialog;
	mlx_image_t		*dialog_str;
	mlx_image_t		*menu_res;
	mlx_image_t		*menu_save;
	mlx_image_t		*menu_quit;
}					t_menu;

typedef struct s_rocket
{
	mlx_image_t		*sprite;
	mlx_image_t		*current_anim;
	struct s_rocket	*next;
}					t_rocket;

typedef struct s_pika
{
	mlx_image_t		*sprite;
	int				index;
	struct s_pika	*next;
}					t_pika;

typedef struct s_ennemy_bool
{
	int				mooving_b;
	int				mooving_h;
	int				mooving_g;
	int				mooving_d;
}					t_ennemy_bool;

typedef struct s_fight
{
	bool			is_fighting;
	bool			is_open;
	bool			first_wait;
	bool			is_deploy;
	bool			menu;
	bool			fight;
	bool			pkmn;
	bool			item;
	bool			run;
	bool			display_bar;
	bool			thunder;
	bool			quick;
	bool			lthunder;
	bool			lquick;
	bool			ebar_to_mid;
	bool			pbar_to_mid;
	bool			ebar_to_rmid;
	bool			pbar_to_rmid;
	bool			ebar_to_low;
	bool			pbar_to_low;
	bool			ebar_to_death;
	bool			pbar_to_death;
	bool			pbar_to_full;
	bool			shadow;
	bool			curse;
	bool			pbar_verif2;
	bool			ebar_verif2;
	bool			ectofainted;
	bool			second_wait;
	bool			third_wait;
	bool			fourth_wait;
	bool			fifth_wait;
	bool			sixth_wait;
	bool			exp;
	bool			money;
	bool			rage_mess;
	bool			wmess;
	bool			end_combat;
	mlx_image_t		*p_bar;
	mlx_image_t		*e_bar;
	char			*sprite_path[4];
	bool			select_attack;
	int				tpp;
	int				qpp;
	mlx_image_t		*pp;
	mlx_image_t		*static_pp;
	int				php;
	int				ehp;
	int				battle_wait;
}					t_fight;

typedef struct s_texture
{
	mlx_texture_t	*icon;
	mlx_texture_t	*menu1;
	mlx_texture_t	*menu2;
	mlx_texture_t	*menu3;
	mlx_texture_t	*p0;
	mlx_texture_t	*p1;
	mlx_texture_t	*p2;
	mlx_texture_t	*p3;
	mlx_texture_t	*p4;
	mlx_texture_t	*p5;
	mlx_texture_t	*p6;
	mlx_texture_t	*p7;
	mlx_texture_t	*p8;
	mlx_texture_t	*p9;
	mlx_texture_t	*r0;
	mlx_texture_t	*r1;
	mlx_texture_t	*r2;
	mlx_texture_t	*r3;
	mlx_texture_t	*r4;
	mlx_texture_t	*r5;
	mlx_texture_t	*r6;
	mlx_texture_t	*r7;
	mlx_texture_t	*r8;
	mlx_texture_t	*r9;
	mlx_texture_t	*dial;
	mlx_texture_t	*tile;
	mlx_texture_t	*a;
	mlx_texture_t	*h;
	mlx_texture_t	*p;
}					t_texture;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*player_img;
	t_map			*map;
	t_anim			*player_anim;
	t_anim			*rocket_anim;
	int				moove_num;
	t_menu			*menu;
	int				wait_frames;
	int				wait_moove;
	t_rocket		*ennemy;
	t_ennemy_bool	test;
	t_fight			*fight;
	t_open_fight	*open_anim;
	int				hmframes;
	char			*anim_path;
	bool			do_anim;
	bool			do_ebar_anim;
	bool			do_pbar_anim;
	int				path_len;
	mlx_image_t		*what_img;
	t_texture		*tlist;
	t_co			zero;
	t_co			anim_co;
	t_co			want_co;
	t_co			player_co;
	t_co			sign_co;
	bool			collide_bike;
	int				pikachu_number;
	bool			win_dialog;
	bool			win_wait;
	bool			bike_dialog;
	bool			do_dialog_anim;
	bool			cant_leave;
	bool			bike_wait;
	bool			collide_pikachu;
	int				pika_index;
	mlx_image_t		*dialog_img;
	t_pika			*pika;
	int				line_readed;
	bool			save_anim;
	bool			save_wait;
	int				n_player;
	int				n_exit;
	int				n_pika;
	char			*s;
}					t_game;

t_pika				*ft_lstpikalast(t_pika *lst);
void				ft_lstpikaadd_back(t_pika **lst, t_pika *new);
void				ft_lstpikaiter(t_pika *lst, void (*f)(void *, int,
							t_game *), t_game *game);
t_rocket			*ft_lstlast(t_rocket *lst);
void				ft_lstadd_back(t_rocket **lst, t_rocket *new);
void				ft_lstiter(t_rocket *lst, void (*f)(void *, t_game *),
						t_game *game);
void				rocket_moove(mlx_image_t *img, int rand, t_game *game);
void				do_random(void *param, t_game *game);
void				rocket_loop(void *param);
void				del(void *mlx, void *img);
void				ft_lstdelone(t_rocket *lst, void (*del)(void *, void *),
						t_game *game);
void				ft_lstpikadelone(t_pika *lst, void (*del)(void *, void *),
						t_game *game);
void				ft_lstpikaclear(t_pika **lst, void (*del)(void *, void *),
						t_game *game);
void				ft_lstclear(t_rocket **lst, void (*del)(void *, void *),
						t_game *game);
int					lenn(int _n);
char				*ft_itoa(int _n);
void				update_game(void *param);
void				ft_error(void);
void				ft_putstr_fd(char *s, int fd);
void				ft_putustr_fd(unsigned char *s, int fd);
void				ft_save(t_game *game);
int					round_down_to_nearest_64(int num);
int					round_up_to_nearest_64(int num);
void				ft_fight(t_game *game, mlx_image_t *sprite);
int					abs(int value);
void				is_player_collide_rocket(void *param, t_game *game);
void				pika_function(void *param1, int index, t_game *game);
void				ft_hook(void *param);
int					line_counter(char *map_path);
int					line_len(char *map_path);
int					first_occurence(char *str, char c);
void				process_player(t_game *game, t_co xy);
void				process_rocket(t_game *game, t_co xy);
void				process_tiles(char c, t_game *game, t_co xy, int i);
int					rocket_moove0(t_game *game, mlx_image_t *img, char *map);
int					rocket_moove1(t_game *game, mlx_image_t *img, char *map);
int					rocket_moove2(t_game *game, mlx_image_t *img, char *map);
int					rocket_moove3(t_game *game, mlx_image_t *img, char *map);
int					rocket_anim_verif1(t_game *game, char *map);
int					rocket_anim_verif2(t_game *game, char *map);
int					rocket_anim_verif3(t_game *game, char *map);
int					rocket_anim_verif4(t_game *game, char *map);
int					rocket_anim_verif5(t_game *game, char *map);
int					rocket_anim_verif6(t_game *game, char *map);
int					rocket_anim_verif7(t_game *game, char *map);
int					rocket_anim_verif8(t_game *game, char *map);
void				is_pika(int i, t_game *game, t_co xy);
int					what_sprite(int fd, t_game *game);
void				map_printer(char *map_path, t_game *game);
int					is_collide(char *map, int index, t_game *game);
int					can_moove_to(int32_t x, int32_t y, char direction,
						t_game *game);
void				ft_moovement_count(void *param);
void				ft_escape_quit(void *param);
void				ft_escape_save(void *param);
void				ft_escape(void *param);
void				menu_load(t_game *game);
void				ft_print_moove(void *param);
t_anim				*ft_load_sprite(t_game *game);
t_anim				*ft_load_rocket_sprite(t_game *game);
void				ft_moove_x(char c, t_game *game);
void				ft_moove_y(char c, t_game *game);
int					is_double_press(t_game *game);
void				ft_nothing_press(t_game *game, char last_dir);
void				key_hook(void *param);
void				end_program(t_game *game);
char				*map_reader(char *map_path);
int					ft_atoi(const char *nptr);
void				ft_putnbr_fd(int n, int fd);
void				ft_load_save(t_game *game);
int					ft_is_delimiter(char c, char delim);
int					ft_strlen_mod(const char *s, char c);
char				*ft_strndup(const char *s, int n);
int					ft_wordcount(const char *s, char c);
char				**ft_split(char const *s, char c);
int					check_border_and_format(char *map, int numberoflines,
						t_game *game);
void				clean_map(char **map, int numberoflines);
int					is_there_a_collectible_path(char **map, int i, int j);
int					is_there_a_path(char **map, int i, int j);
int					is_map_achievable(char **map, int numberoflines,
						t_game *game);
int					map_is_sourrounded(char **map, int n_line);
void				game_init(t_game *game);
int					game_init2(t_game *game, char *str);
void				set_loop_hook(t_game *game, mlx_t *mlx);
void				set_loop_hook2(t_game *game, mlx_t *mlx);
void				set_loop_hook3(t_game *game, mlx_t *mlx);
void				ft_do_anim(void *param);
void				set_anim_param(t_game *game, char *path, int frame,
						mlx_image_t *image);
void				ft_open_fight(void *param);
void				first_fight_wait(void *param);
void				deploy_anim(void *param);
void				fight_menu1(void *param);
void				fight_menu2(void *param);
void				fight_menu3(void *param);
void				fight_menu4(void *param);
void				fight_menu5(void *param);
void				hp_print(void *param);
void				player_bar_init(t_game *game);
void				ennemy_bar_init(t_game *game);
void				select_attack(void *param);
void				select_attack2(void *param);
void				select_attack_utils1(t_game *game);
void				select_attack_utils2(t_game *game);
void				select_attack_utils3(t_game *game);
void				menu_utils(t_game *game);
mlx_image_t			*moove_x_utils(t_game *game, int i);
mlx_image_t			*moove_y_utils1(t_game *game, int i);
mlx_image_t			*moove_y_utils2(t_game *game, int i);
void				update_position(t_game *game, t_first *first, t_co *co);
void				bool_checker(void *param);
void				static_pp_print(void *param);
void				pp_print(void *param);
void				thunder(void *param);
void				quick(void *param);
void				bar_anim(void *param);
void				ebarm(void *param);
void				eselect_attack(t_game *game);
void				shadow(void *param);
void				pbar_anim(void *param);
void				pbarm(void *param);
void				ebarrm(void *param);
void				set_pbar_anim_param(t_game *game, char *path, int frame);
void				curse(void *param);
void				pbarrm(void *param);
void				pbar_verif2(void *param);
void				ebar_verif2(void *param);
void				ebarl(void *param);
void				pbarl(void *param);
void				ebard(void *param);
void				ectofainted(void *param);
void				second_fight_wait(void *param);
void				exp_gain(void *param);
void				third_fight_wait(void *param);
void				win_message(void *param);
void				fourth_fight_wait(void *param);
void				rage_message(void *param);
void				fifth_fight_wait(void *param);
void				money_gain(void *param);
void				bike_dialog(void *param);
void				win_dialog(void *param);
void				win_wait(void *param);
void				ft_dialog_anim(void *param);
void				set_dialog_param(t_game *game, char *path, int frame);
void				cant_leave(void *param);
void				bike_wait(void *param);
void				take_pika(void *param);
void				save_anim(void *param);
void				save_wait(void *param);
void				sixth_fight_wait(void *param);
void				end_combat(void *param);
void				ft_do_bar_anim(void *param);
void				ft_do_pbar_anim(void *param);
void				set_ebar_anim_param(t_game *game, char *path, int frame);
void				cancel_anim(t_game *game);
void				anim_front_step2(void *param);
void				anim_front_step1(void *param);
void				anim_back_step2(void *param);
void				anim_back_step1(void *param);
void				anim_right_step2(void *param);
void				anim_right_step1(void *param);
void				anim_left_step2(void *param);
void				anim_left_step1(void *param);
void				anim_right_step2(void *param);
void				anim_right_step1(void *param);
void				anim_left_step2(void *param);
void				anim_left_step1(void *param);
void				end_program_error(t_game *game);
mlx_image_t			*image_send(t_game *game, char *path);
void				free_texture(t_game *game);

#endif