/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/28 12:34:06 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

/* ----------------------------------------------------------------------------
	Parse une ligne du fichier de scène.
---------------------------------------------------------------------------- */
void	parse_line(char *line)
{
	if (line[0] == 'A' && validate_ambient(line))
		error_exit("Invalid ambient lighting data");
	else if (line[0] == 'L' && validate_light(line))
		error_exit("Invalid light data");
	else if (line[0] == 'C' && validate_camera(line))
		error_exit("Invalid camera data");
	else if (line[0] == 's' && line[1] == 'p' && validate_sphere(line))
		error_exit("Invalid sphere data");
	else if (line[0] == 'p' && line[1] == 'l' && validate_plane(line))
		error_exit("Invalid plane data");
	else if (line[0] == 'c' && line[1] == 'y' && validate_cylinder(line))
		error_exit("Invalid cylinder data");
}

/* ----------------------------------------------------------------------------
	Lit et traite un fichier de scène.
---------------------------------------------------------------------------- */
void	parse_scene_file(const char *filename)
{
	int		fd;
	char	buf[256];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open file");
	ret = read(fd, buf, 255);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf);
		ret = read(fd, buf, 255);
	}
	if (ret == -1)
		error_exit("Failed to read file");
	close(fd);
}
