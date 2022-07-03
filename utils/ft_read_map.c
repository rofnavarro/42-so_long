/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:39:22 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/29 17:10:23 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_empty_map(t_game *game, char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\0')
	{
		free(map);
		ft_error(game, 2, "\nError!\nInvalid or empty map.\n");
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] != '1')
		{
			free(map);
			ft_error(game, 2, "\nError!\nInvalid map.\n");
		}
		i++;
	}
}

char	*ft_read_map(t_game *game, char *argv[])
{
	char	*map_str;
	char	*tmp;
	int		fd;

	map_str = ft_strdup("");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		free(tmp);
		ft_error(game, 2, "\nError!\nFile broken or does not exist.\n");
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			free(tmp);
			break ;
		}
		map_str = ft_strjoin_free(map_str, tmp);
		free(tmp);
	}
	close(fd);
	ft_empty_map(game, map_str);
	return (map_str);
}
