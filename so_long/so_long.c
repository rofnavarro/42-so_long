/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:39:20 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 16:15:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_args(t_game *game, int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*read_map;

	ft_check_args(&game, argc, argv);
	game.mlx = mlx_init();
	read_map = ft_read_map(&game, argv);
	game.matrix.map = ft_split(read_map, '\n');
	free(read_map);
	ft_map_validation(&game);
	game.window = mlx_new_window(game.mlx, ((game.matrix.width + 1) * XPM), \
					((game.matrix.height + 1) * XPM), "so_long - rferrero");
	ft_init(&game);
	ft_draw(&game);
	game.player.moves = 0;
	ft_game(&game);
	return (0);
}

static void	ft_check_args(t_game *game, int argc, char *argv[])
{
	int	i;

	i = 0;
	if (!argc || argc != 2)
	{
		ft_error(game, 0, "\nMust enter ONE map file.\n");
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 4] != '.' && argv[1][i - 3] != 'b'
		&& argv[1][i - 2] != 'e' && argv[i][i - 1] != 'r')
	{
		ft_error(game, 0, "\nMap must be a .ber file.\n");
	}
}
