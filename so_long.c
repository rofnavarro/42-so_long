/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:39:20 by rferrero          #+#    #+#             */
/*   Updated: 2022/07/04 14:19:47 by rferrero         ###   ########.fr       */
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
	game.window = mlx_new_window(game.mlx, ((game.matrix.width) * XPM), \
					((game.matrix.height) * XPM), "so_long - rferrero");
	ft_init(&game);
	ft_draw(&game);
	game.player.moves = 0;
	ft_game(&game);
	return (0);
}

static void	ft_check_args(t_game *game, int argc, char *argv[])
{
	if (!argc || argc != 2)
		ft_error(game, 0, "\nMust enter ONE map file.\n");
	else if (!ft_strchr(argv[1], '.'))
		ft_error(game, 0, "\nError\nNot a file.\n");
	else if (ft_strlen(ft_strchr(argv[1], '.') + 1) != 3)
		ft_error(game, 0, "\nError\nWrong type of file.\n");
	else if (ft_strncmp(ft_strchr(argv[1], '.') + 1, "ber", 3) != 0)
		ft_error(game, 0, "\nError\nWrong type of file.\n");
}
