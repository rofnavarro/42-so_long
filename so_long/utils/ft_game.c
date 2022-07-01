/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:35:22 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 17:20:15 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_win(t_game *game)
{
	if (game->matrix.map[game->player.y][game->player.x] == 'E' && \
		game->matrix.c == 0)
	{
		ft_printf("\nCongratulations!\nYou finished!\n");
		ft_free_handler(game);
		exit(EXIT_SUCCESS);
	}
}

void	ft_collect(t_game *game)
{
	if (game->matrix.map[(game->player.y)][(game->player.x)] != 'C')
		return ;
	else
	{
		game->matrix.map[(game->player.y)][(game->player.x)] = '0';
		game->matrix.c--;
	}
}

static int	ft_key_input(int key, t_game *game)
{
	if (key == UP)
	{
		game->player.y -= 1;
		ft_player_up(game);
	}
	else if (key == LEFT)
	{
		game->player.x -= 1;
		ft_player_left(game);
	}
	else if (key == DOWN)
	{
		game->player.y += 1;
		ft_player_down(game);
	}
	else if (key == RIGHT)
	{
		game->player.x += 1;
		ft_player_right(game);
	}
	ft_putstr_fd("\rMoves: ", 1);
	ft_putnbr_fd(game->player.moves, 1);
	ft_collect(game);
	ft_win(game);
}

static int	ft_esc(int key, t_game *game)
{
	if (key == ESC)
		ft_close_window(game);
	else
		ft_key_input(key, game);
}

void	ft_game(t_game *game)
{
	mlx_hook(game->window, 2, 1L << 0, ft_esc, game);
	mlx_hook(game->window, X_DESTROY, (0L), ft_close_window, game);
	mlx_hook(game->window, X_EXPOSE, (1L << 15), ft_move_window, game);
	mlx_loop(game->mlx);
}
