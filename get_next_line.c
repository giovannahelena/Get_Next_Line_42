/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelena- <ghelena-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:48:58 by ghelena-          #+#    #+#             */
/*   Updated: 2023/06/26 19:18:16 by ghelena-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd);
static int	lentonextline(char *file, int n);
static char	*get_line(int fd);

char	*get_next_line(int fd)
{
	char	*line;
	char	*more_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = get_line(fd);
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (return_null(line));
	if (ft_strchr(line, '\n') == NULL)
	{
		more_line = get_line(fd);
		if (more_line && *more_line != '\0')
			line = ft_strjoin(line, more_line);
		free (more_line);
		if (!line)
			return (NULL);
		if (*line == '\0')
			return (return_null(line));
	}
	return (line);
}

static char	*read_file(int fd)
{
	char	*buffer;
	char	*read_buffer;
	int		i;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 1;
	while (ft_strchr(read_buffer, '\n') == NULL && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		else if (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i = 0;
		}
		read_buffer = ft_strjoin(read_buffer, buffer);
	}
	free (buffer);
	if (*read_buffer == '\0')
		return (return_null(read_buffer));
	return (read_buffer);
}

static char	*get_line(int fd)
{
	static char	*file;
	char		*line;
	int			i;
	static int	j;
	int			len;

	i = 0;
	if (!file || *file == '\0')
	{
		file = read_file(fd);
		if (!file)
			return (NULL);
		j = 0;
	}
	len = lentonextline(file, j);
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (return_null(file));
	while (file[j] != '\0' && file[j] != '\n')
		line[i++] = file[j++];
	if (file[j] == '\n')
		line[i++] = file[j++];
	if (file[j] == '\0')
		file = return_null(file);
	return (line);
}

static int	lentonextline(char *file, int n)
{
	int	i;
	int	count;

	if (!file)
		return (0);
	i = n;
	count = 1;
	while (file[i] != '\n' && file[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}
