/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:52:27 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 09:33:09 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/* ----------------------------------------------------------------------------
	Parse une ligne du fichier de scène.
---------------------------------------------------------------------------- */
void	parse_line(char *line, t_program_context *context)
{
	while (*line == ' ' || *line == '\t')
		line++ ;
	if (*line == '\0' || *line == '#')
		return ;
	if (!ft_strncmp(line, "A", 1) && validate_ambient(line))
		error_exit("Invalid ambient lighting data", context);
	else if (!ft_strncmp(line, "L", 1)
		&& validate_light(line, context->num_obj))
		error_exit("Invalid light data", context);
	else if (!ft_strncmp(line, "C", 1) && validate_camera(line))
		error_exit("Invalid camera data", context);
	else if (!ft_strncmp(line, "sp", 2)
		&& validate_sphere(line, context->num_obj))
		error_exit("Invalid sphere data", context);
	else if (!ft_strncmp(line, "pl", 2)
		&& validate_plane(line, context->num_obj))
		error_exit("Invalid plane data", context);
	else if (!ft_strncmp(line, "cy", 2)
		&& validate_cylinder(line, context->num_obj))
		error_exit("Invalid cylinder data", context);
}

/* ----------------------------------------------------------------------------
Traite chaque ligne lue depuis le buffer.
---------------------------------------------------------------------------- */
void	process_buffer(char *buf, t_program_context *context)
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
		parse_line(line, context);
		line += i + 1;
	}
}

/* ----------------------------------------------------------------------------
	Lit et traite un fichier de scène.
---------------------------------------------------------------------------- */
void	parse_scene_file(const char *filename, t_pix ***pix,
		t_program_context *context)
{
	int		fd;
	char	buf[5000];
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open file for parsing", context);
	ret = read(fd, buf, sizeof(buf) - 1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf, context);
		ret = read(fd, buf, sizeof(buf) - 1);
	}
	if (ret == -1)
		error_exit("Failed to read file during parsing", context);
	close(fd);
}
