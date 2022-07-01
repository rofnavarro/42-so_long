/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:50:20 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 16:43:15 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_game *game)
{
	int	x;
	int	y;

	game->wall.ptr = mlx_xpm_file_to_image(game->mlx, \
										"images/wall.xpm", &x, &y);
	game->floor.ptr = mlx_xpm_file_to_image(game->mlx, \
										"images/tile.xpm", &x, &y);
	game->collectible.ptr = mlx_xpm_file_to_image(game->mlx, \
										"images/book.xpm", &x, &y);
	game->exit.ptr = mlx_xpm_file_to_image(game->mlx, \
										"images/exit_door.xpm", &x, &y);
	game->player.ptr = mlx_xpm_file_to_image(game->mlx, \
										"images/right.xpm", &x, &y);
}
