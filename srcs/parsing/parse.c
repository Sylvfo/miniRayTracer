/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/12 09:33:08 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	validate_ambient(char *line)
{
	float	ratio;
	int		r;
	int		g;
	int		b;

	if (sscanf(line, "A %f %d,%d,%d", &ratio, &r, &g, &b) != 4)
		return (0);
	if (ratio < 0.0f || ratio > 1.0f)
		return (0);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (1);
}

void	parse_line(char *line)
{
	if (line[0] == 'A')
	{
		if (!validate_ambient(line))
		{
			write(2, "Error\nInvalid ambient lighting data\n", 36);
			exit(EXIT_FAILURE);
		}
	}
	// Ajoutez des vérifications pour les autres types d'éléments ici
}

void	read_file(int fd)
{
	char	buf[256];
	char	*line;
	int		ret;
	int		i;

	while ((ret = read(fd, buf, 255)) > 0)
	{
		buf[ret] = '\0';
		line = buf;
		while (*line)
		{
			i = 0;
			while (line[i] && line[i] != '\n')
				i++;
			line[i] = '\0';
			parse_line(line);
			line += i + 1;
		}
	}
	if (ret == -1)
	{
		perror("Failed to read file");
		exit(EXIT_FAILURE);
	}
}

void	parse_scene_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	close(fd);
}