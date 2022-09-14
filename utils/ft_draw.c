/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:13:52 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 16:50:04 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_image_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, image, \
							(x * XPM), (y * XPM));
}

static void	ft_check_collectible(t_game *game, int i, int j)
{
	int	x;
	int	y;

	if (game->matrix.c == 0)
	{
		mlx_destroy_image(game->mlx, game->exit.ptr);
		game->exit.ptr = mlx_xpm_file_to_image(game->mlx, \
			"images/exit_open.xpm", &x, &y);
	}
	ft_image_draw(game, game->exit.ptr, j, i);
}

void	ft_track_player(t_game *game, void *image, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	ft_image_draw(game, image, j, i);
}

static void	ft_draw_line(t_game *game, int i, int j)
{
	if (game->matrix.map[i][j] == '1')
		ft_image_draw(game, game->wall.ptr, j, i);
	else if (game->matrix.map[i][j] == '0')
		ft_image_draw(game, game->floor.ptr, j, i);
	else if (game->matrix.map[i][j] == 'C')
		ft_image_draw(game, game->collectible.ptr, j, i);
	else if (game->matrix.map[i][j] == 'E')
		ft_check_collectible(game, i, j);
	else if (game->matrix.map[i][j] == 'P')
		ft_track_player(game, game->player.ptr, i, j);
}

void	ft_draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->matrix.map[i])
	{
		j = 0;
		while (game->matrix.map[i][j])
		{
			ft_draw_line(game, i, j);
			j++;
		}
		i++;
	}
}
