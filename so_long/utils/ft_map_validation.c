/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:16:54 by rferrero          #+#    #+#             */
/*   Updated: 2022/07/04 14:19:49 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_must_char(t_game *game)
{
	if (game->matrix.p != 1)
		ft_error(game, 3, "\nError!\nMust contain 1 player.\n");
	if (game->matrix.e < 1)
		ft_error(game, 3, "\nError!\nMust contain at least 1 exit.\n");
	if (game->matrix.c < 1)
		ft_error(game, 3, "\nError!\nMust contain at least 1 collectible.\n");
}

static void	ft_char_check(t_game *game, int i, int j)
{
	if (game->matrix.map[i][j] == 'P')
		game->matrix.p += 1;
	else if (game->matrix.map[i][j] == 'E')
		game->matrix.e += 1;
	else if (game->matrix.map[i][j] == 'C')
		game->matrix.c += 1;
	else if ((game->matrix.map[i][j] != '0') && (game->matrix.map[i][j] != '1'))
		ft_error(game, 3, "\nError!\nInvalid character in map.\n");
}

static void	ft_char_validation(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->matrix.map[i])
	{
		j = 0;
		while (game->matrix.map[i][j])
		{
			ft_char_check(game, i, j);
			j++;
		}
		i++;
	}
	ft_must_char(game);
}

static void	ft_format_validation(t_game *game)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = (int)ft_strlen(game->matrix.map[i]);
	while (game->matrix.map[i])
	{
		j = 0;
		while (game->matrix.map[i][j])
			j++;
		if (j != length)
			ft_error(game, 3, "\nError!\nMap must be rectangular.\n");
		i++;
	}
	game->matrix.width = j;
	game->matrix.height = i;
	if (game->matrix.width == game->matrix.height)
		ft_error(game, 3, "\nError!\nMap must be rectangular.\n");
	if (game->matrix.width - 1 > MAX_CHAR_H || game->matrix.height - 1 > MAX_CHAR_V)
		ft_error(game, 3, "\nError!\nMap too big for the screen.\n");
}

void	ft_map_validation(t_game *game)
{
	game->matrix.p = 0;
	game->matrix.e = 0;
	game->matrix.c = 0;
	game->matrix.width = 0;
	game->matrix.height = 0;
	ft_char_validation(game);
	ft_format_validation(game);
	ft_is_closed(game);
}
