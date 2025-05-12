/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:04:41 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 10:18:53 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Modified signature to accept t_program_context
void	save_line(char *line, t_program_context *context)
{
	if (line[0] == 'A' || line[0] == 'L')
		save_light(line, context);
	else if (line[0] == 'C')
		save_camera(line, context);
	else if (line[0] == 's' && line[1] == 'p')
		save_sphere(line, context);
	else if (line[0] == 'p' && line[1] == 'l')
		save_plane(line, context);
	else if (line[0] == 'c' && line[1] == 'y')
		save_cylinder(line, context);
}

void	process_line(char *buf, t_program_context *context)
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
		save_line(line, context);
		line += i + 1;
	}
}

// Modified signature to accept t_program_context
void	save_scene_file(const char *filename, t_program_context *context)
{
	int		fd;
	char	buf[5000];
	int		ret;

	context->num_obj->sphere = 0;
	context->num_obj->plan = 0;
	context->num_obj->cylinder = 0;
	context->num_obj->light = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open file", context);
	ret = read(fd, buf, sizeof(buf) - 1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_line(buf, context);
		ret = read(fd, buf, sizeof(buf) - 1);
	}
	if (ret == -1)
		error_exit("Failed to read file", context);
	close(fd);
}
