/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:52:27 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/21 19:03:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/* ----------------------------------------------------------------------------
	Parse une ligne du fichier de scène.
---------------------------------------------------------------------------- */
void	parse_line(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	while (*line == ' ' || *line == '\t')
		line++ ;
	if (*line == '\0' || *line == '#')
		return ;
	if (!ft_strncmp(line, "A", 1) && validate_ambient(line))
		error_exit("Invalid ambient lighting data", pix, num_obj);
	else if (!ft_strncmp(line, "L", 1) && validate_light(line, num_obj))
		error_exit("Invalid light data", pix, num_obj);
	else if (!ft_strncmp(line, "C", 1) && validate_camera(line))
		error_exit("Invalid camera data", pix, num_obj);
	else if (!ft_strncmp(line, "sp", 2) && validate_sphere(line, num_obj))
		error_exit("Invalid sphere data", pix, num_obj);
	else if (!ft_strncmp(line, "pl", 2) && validate_plane(line, num_obj))
		error_exit("Invalid plane data", pix, num_obj);
	else if (!ft_strncmp(line, "cy", 2) && validate_cylinder(line, num_obj))
		error_exit("Invalid cylinder data", pix, num_obj);
}

/* ----------------------------------------------------------------------------
Traite chaque ligne lue depuis le buffer.
---------------------------------------------------------------------------- */
void	process_buffer(char *buf, t_pix ***pix, t_num_obj *num_obj)
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
		parse_line(line, pix, num_obj);
		line += i + 1;
	}
}

/* ----------------------------------------------------------------------------
	Lit et traite un fichier de scène.
---------------------------------------------------------------------------- */
void	parse_scene_file(const char *filename, t_pix ***pix, t_num_obj *num_obj)
{
	int		fd;
	char	buf[5000];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open file", pix, num_obj);
	ret = read(fd, buf, sizeof(buf) - 1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf, pix, num_obj);
		ret = read(fd, buf, sizeof(buf) - 1);
	}
	if (ret == -1)
		error_exit("Failed to read file", pix, num_obj);
	close(fd);
}
