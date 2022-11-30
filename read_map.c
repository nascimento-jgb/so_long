/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:25:29 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/30 16:11:53 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *line, size_t lenght, size_t row)
{
	int i;

	i = 0;
	if (lenght != row)
		exit(0); // exit error about different sizes betwen lines
	while (line[i++])
	{
		if (line[i] != 0 && line[i] != 1 && line[i] != 0 && line[i] != 'C' && line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
			exit(0); //error message about invalid character
	}
}

static t_param	*get_dimensions(t_param *param)
{
	param->width = ft_strlen(param->map[0]);
	while (param->map[param->height])
		param->height++;
	param->height--;
	return (param);
}

static char get_data(int fd)
{
	char	*line;
	char	*info;
	size_t	lenght;
	size_t	row;

	line = get_next_line(fd);
	if (line == NULL)
		exit(0); // exit message about empty file
	lenght = ft_strlen(line);
	info = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			row = ft_strlen(line);
			check_line (line, lenght, row);
			info = ft_strjoin(info, line);
			free (line);
		}
	}
	return (info);
}

void	open_map(char *argv, t_param *param)
{
	int		fd;
	char	*file;
	char	*data;

	file = ft_strjoin("./maps/", argv);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(0); // exit message about failed file descriptor
	data = get_data(fd);
	param->map = ft_split(data, '\n');
	close(fd);
	free(data);
	param = get_dimensions(param);
	check_map(param); //checking the map in another file
}
