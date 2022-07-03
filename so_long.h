/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:17:54 by rferrero          #+#    #+#             */
/*   Updated: 2022/07/03 11:17:46 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//	minilibX 
# include <mlx.h>

//	read() close()
# include <unistd.h>

//	malloc() free()
# include <stdlib.h>

//	open()
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//	ft_printf()
# include "./utils/ft_printf/ft_printf.h"

# define XPM			64

# define UP				119
# define DOWN			115
# define LEFT			97
# define RIGHT			100

# define ESC			65307
# define X_DESTROY		17
# define X_EXPOSE		12

# define MAX_CHAR_H		29
# define MAX_CHAR_V		15

# define MAP_VALID_CHAR	'PEC10'

typedef struct s_img
{
	void		*ptr;
	int			x;
	int			y;
}	t_img;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			p;
	int			e;
	int			c;
}	t_map;

typedef struct s_player
{
	void		*ptr;
	int			x;
	int			y;
	int			moves;
}	t_player;

typedef struct s_game
{
	t_map		matrix;
	void		*mlx;
	void		*window;
	t_player	player;
	t_img		wall;
	t_img		floor;
	t_img		collectible;
	t_img		exit;
}	t_game;

//	ft_draw.c
void		ft_draw(t_game *game);
void		ft_image_draw(t_game *game, void *image, int x, int y);
void		ft_track_player(t_game *game, void *image, int i, int j);

//	ft_error.c
void		ft_error(t_game *game, int error, char *string);

//	ft_free_handler.c
void		ft_free_handler(t_game *game);
void		ft_free_map(t_game *game);

//	ft_game.c
void		ft_win(t_game *game);
void		ft_collect(t_game *game);
void		ft_game(t_game *game);

//	ft_init.c
void		ft_init(t_game *game);

//	ft_map_check.c
void		ft_is_closed(t_game *game);

//	ft_map_validation.c
void		ft_map_validation(t_game *game);

//	ft_move.c
void		ft_player_up(t_game *game);
void		ft_player_left(t_game *game);
void		ft_player_down(t_game *game);
void		ft_player_right(t_game *game);

//	ft_readmap.c
char		*ft_read_map(t_game *game, char *argv[]);

//	ft_window.c
int			ft_close_window(t_game *game);
int			ft_move_window(t_game *game);

#endif
