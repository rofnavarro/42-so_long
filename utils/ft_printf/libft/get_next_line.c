/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:55:40 by rferrero          #+#    #+#             */
/*   Updated: 2022/06/22 16:38:16 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_line(char *line, char **leaks, int fd);
static char	*ft_check_eof(ssize_t bytes, char *line);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leaks;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	if (!leaks)
		leaks = ft_strdup("");
	line = ft_strdup(leaks);
	free(leaks);
	leaks = NULL;
	line = ft_read_line(line, &leaks, fd);
	return (line);
}

static char	*ft_read_line(char *line, char **leaks, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return (0);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			*leaks = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr_free(line, 0, ft_strlen(line) - ft_strlen(*leaks));
			break ;
		}
	}
	return (ft_check_eof(bytes_read, line));
}

static char	*ft_check_eof(ssize_t bytes, char *line)
{
	if (!bytes && line[bytes] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
