/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:04:41 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 15:43:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	save_line(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	if (line[0] == 'A' || line[0] == 'L')
		save_light(line, *pix, num_obj);
	else if (line[0] == 'C')
		save_camera(line, *pix);
	else if (line[0] == 's' && line[1] == 'p')
		save_sphere(line, *pix, num_obj);
	else if (line[0] == 'p' && line[1] == 'l')
		save_plane(line, *pix, num_obj);
	else if (line[0] == 'c' && line[1] == 'y')
		save_cylinder(line, *pix, num_obj);
}

void	process_line(char *buf, t_pix ***pix, t_num_obj *num_obj)
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
		save_line(line, pix, num_obj);
		line += i + 1;
	}
}

void	save_scene_file(const char *filename, t_pix ***pix, t_num_obj *num_obj)
{
	int		fd;
	char	buf[5000];
	int		ret;

	num_obj->sphere = 0;
	num_obj->plan = 0;
	num_obj->cylinder = 0;
	num_obj->light = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open file", pix, num_obj);
	ret = read(fd, buf, sizeof(buf) - 1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_line(buf, pix, num_obj);
		ret = read(fd, buf, sizeof(buf) - 1);
	}
	if (ret == -1)
		error_exit("Failed to read file", pix, num_obj);
	close(fd);
}
