/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:33:05 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/23 10:57:09 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_game *game, int error, char *string)
{
	if (error == 1)
	{
		ft_printf("%s\n", string);
		ft_free_handler(game);
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		ft_printf("%s\n", string);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else if (error == 3)
	{
		ft_printf("%s\n", string);
		ft_free_map(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	ft_printf("%s\n", string);
	exit(EXIT_FAILURE);
}
