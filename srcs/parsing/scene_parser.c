/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 07:17:55 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"

/* ----------------------------------------------------------------------------
	Parse une ligne du fichier de scène.
---------------------------------------------------------------------------- */
void	parse_line(char *line, t_num_obj *num_obj)
{
	if (line[0] == 'A' && validate_ambient(line))
		error_exit("Invalid ambient lighting data");
	else if (line[0] == 'L' && validate_light(line, num_obj))
		error_exit("Invalid light data");
	else if (line[0] == 'C' && validate_camera(line))
		error_exit("Invalid camera data");
	else if (line[0] == 's' && line[1] == 'p' && validate_sphere(line, num_obj))
		error_exit("Invalid sphere data");
	else if (line[0] == 'p' && line[1] == 'l' && validate_plane(line, num_obj))
		error_exit("Invalid plane data");
	else if (line[0] == 'c' && line[1] == 'y'
		&& validate_cylinder(line, num_obj))
		error_exit("Invalid cylinder data");
}

/* ----------------------------------------------------------------------------
Traite chaque ligne lue depuis le buffer.
---------------------------------------------------------------------------- */
void	process_buffer(char *buf, t_num_obj *num_obj, const char *type,
			t_pix ***pix)
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
		if (ft_strncmp(type, "parsing", 7) == 0)
			parse_line(line, num_obj);
		else if (ft_strncmp(type, "saving", 6) == 0)
			save_line(line, pix, num_obj);
		line += i + 1;
	}
}

/* ----------------------------------------------------------------------------
	Lit et traite un fichier de scène.
---------------------------------------------------------------------------- */
void	parse_scene_file(const char *filename, t_pix ***pix, t_num_obj *num_obj,
			const char *type)
{
	int		fd;
	char	buf[5000];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open file");
	ret = read(fd, buf, sizeof(buf) - 1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf, num_obj, type, pix);
		ret = read(fd, buf, sizeof(buf) - 1);
	}
	if (ret == -1)
		error_exit("Failed to read file");
	close(fd);
}
