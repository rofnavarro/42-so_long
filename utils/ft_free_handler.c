/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:02:44 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 16:43:59 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_img(t_game *game);

void	ft_free_handler(t_game *game)
{
	ft_free_img(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	ft_free_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->matrix.map[y])
	{
		free(game->matrix.map[y]);
		y++;
	}
	free(game->matrix.map);
}

static void	ft_free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.ptr);
	mlx_destroy_image(game->mlx, game->wall.ptr);
	mlx_destroy_image(game->mlx, game->floor.ptr);
	mlx_destroy_image(game->mlx, game->collectible.ptr);
	mlx_destroy_image(game->mlx, game->exit.ptr);
}
