/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:30:09 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 16:43:37 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_player_update(char key, t_game *game)
{
	int	x;
	int	y;

	mlx_destroy_image(game->mlx, game->player.ptr);
	if (key == 'w')
		game->player.ptr = mlx_xpm_file_to_image(game->mlx, "images/back.xpm", \
		&x, &y);
	else if (key == 'a')
		game->player.ptr = mlx_xpm_file_to_image(game->mlx, "images/left.xpm", \
		&x, &y);
	else if (key == 's')
		game->player.ptr = mlx_xpm_file_to_image(game->mlx, "images/front.xpm", \
		&x, &y);
	else if (key == 'd')
		game->player.ptr = mlx_xpm_file_to_image(game->mlx, "images/right.xpm", \
		&x, &y);
}

void	ft_player_up(t_game *game)
{
	ft_player_update('w', game);
	if (game->matrix.map[game->player.y][game->player.x] == 'E' \
		&& game->matrix.c == 0)
		ft_win(game);
	else if (game->matrix.map[game->player.y][game->player.x] == '1' \
		|| game->matrix.map[game->player.y][game->player.x] == 'E')
		game->player.y += 1;
	else
	{
		if (game->matrix.map[game->player.y][game->player.x] == 'C')
			game->matrix.c--;
		game->matrix.map[game->player.y][game->player.x] = 'P';
		game->matrix.map[game->player.y + 1][game->player.x] = '0';
		game->player.moves++;
		ft_draw(game);
	}
}

void	ft_player_left(t_game *game)
{
	ft_player_update('a', game);
	if (game->matrix.map[game->player.y][game->player.x] == 'E' \
		&& game->matrix.c == 0)
		ft_win(game);
	else if (game->matrix.map[game->player.y][game->player.x] == '1' \
		|| game->matrix.map[game->player.y][game->player.x] == 'E')
		game->player.x += 1;
	else
	{
		if (game->matrix.map[game->player.y][game->player.x] == 'C')
			game->matrix.c--;
		game->matrix.map[game->player.y][game->player.x] = 'P';
		game->matrix.map[game->player.y][game->player.x + 1] = '0';
		game->player.moves++;
		ft_draw(game);
	}
}

void	ft_player_down(t_game *game)
{
	ft_player_update('s', game);
	if (game->matrix.map[game->player.y][game->player.x] == 'E' \
		&& game->matrix.c == 0)
		ft_win(game);
	else if (game->matrix.map[game->player.y][game->player.x] == '1' \
		|| game->matrix.map[game->player.y][game->player.x] == 'E')
		game->player.y -= 1;
	else
	{
		if (game->matrix.map[game->player.y][game->player.x] == 'C')
			game->matrix.c--;
		game->matrix.map[game->player.y][game->player.x] = 'P';
		game->matrix.map[game->player.y - 1][game->player.x] = '0';
		game->player.moves++;
		ft_draw(game);
	}
}

void	ft_player_right(t_game *game)
{
	ft_player_update('d', game);
	if (game->matrix.map[game->player.y][game->player.x] == 'E' \
		&& game->matrix.c == 0)
		ft_win(game);
	else if (game->matrix.map[game->player.y][game->player.x] == '1' \
		|| game->matrix.map[game->player.y][game->player.x] == 'E')
		game->player.x -= 1;
	else
	{
		if (game->matrix.map[game->player.y][game->player.x] == 'C')
			game->matrix.c--;
		game->matrix.map[game->player.y][game->player.x] = 'P';
		game->matrix.map[game->player.y][game->player.x - 1] = '0';
		game->player.moves++;
		ft_draw(game);
	}
}
