/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:49:19 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 17:10:38 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close_window(t_game *game)
{
	ft_error(game, 1, "\nError!\nGame closed by user!\n");
	return (0);
}

int	ft_move_window(t_game *game)
{
	ft_draw(game);
	return (0);
}
