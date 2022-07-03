/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:18:42 by rferrero          #+#    #+#             */
/*   Updated: 2022/07/03 13:57:50 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_is_closed_h(t_game *game)
{
	int	i;
	int	j;

	i = game->matrix.height;
	j = 0;
	while (game->matrix.map[0][j])
	{
		if (game->matrix.map[0][j] != '1')
			ft_error(game, 3, "\nError!\nMap must be walls closed.\n");
		j++;
	}
	j = 0;
	while (game->matrix.map[i][j])
	{
		if (game->matrix.map[i][j] != '1')
			ft_error(game, 3, "\nError!\nMap must be walls closed.\n");
		j++;
	}
}

static void	ft_is_closed_v(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->matrix.map[i])
	{
		if (game->matrix.map[i][0] != '1')
			ft_error(game, 3, "\nError!\nMap must be walls closed.\n");
		i++;
	}
	i = 0;
	j = game->matrix.width - 1;
	while (game->matrix.map[i])
	{
		if (game->matrix.map[i][j] != '1')
			ft_error(game, 3, "\nError!\nMap must be walls closed.\n");
		i++;
	}	
}

void	ft_is_closed(t_game *game)
{
	ft_is_closed_h(game);
	ft_is_closed_v(game);
}
