/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:09:43 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/* ----------------------------------------------------------------------------
	Parse une ligne du fichier de scène.
---------------------------------------------------------------------------- */
void	parse_line(char *line)
{
	if (line[0] == 'A')
	{
		if (validate_ambient(line))
		{
			write(2, "Error\nInvalid ambient lighting data\n", 36);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 'L')
	{
		if (validate_light(line))
		{
			write(2, "Error\nInvalid light data\n", 27);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 'C')
	{
		if (validate_camera(line))
		{
			write(2, "Error\nInvalid camera data\n", 28);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 's' && line[1] == 'p')
	{
		if (validate_sphere(line))
		{
			write(2, "Error\nInvalid sphere data\n", 27);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 'p' && line[1] == 'l')
	{
		if (validate_plane(line))
		{
			write(2, "Error\nInvalid plane data\n", 26);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 'c' && line[1] == 'y')
	{
		if (validate_cylinder(line))
		{
			write(2, "Error\nInvalid cylinder data\n", 29);
			exit(EXIT_FAILURE);
		}
	}
}

/* ----------------------------------------------------------------------------
	Traite le tampon lu depuis le fichier.
---------------------------------------------------------------------------- */
static void	process_buffer(char *buf)
{
	char	*line;
	int		i;

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

/* ----------------------------------------------------------------------------
	Lit le fichier et le traite par blocs.
---------------------------------------------------------------------------- */
void	read_file(int fd)
{
	char	buf[256];
	int		ret;

	while ((ret = read(fd, buf, 255)) > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf);
	}
	if (ret == -1)
	{
		perror("Failed to read file");
		exit(EXIT_FAILURE);
	}
}

/* ----------------------------------------------------------------------------
	Ouvre et parse le fichier de scène.
---------------------------------------------------------------------------- */
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
