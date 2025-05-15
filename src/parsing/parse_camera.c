/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:12:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 12:14:00 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	parse_camera_fov(char **line, float *fov)
{
	if (!line || !*line || !fov || !**line)
		return (1);
	*fov = ft_strtod(*line, line);
	return (validate_fov(*fov));
}

int	validate_camera(char *line)
{
	t_coord	position;
	t_coord	orientation;
	float	fov;

	if (!line || line[0] != 'C' || line[1] != ' ')
		return (1);
	line++;
	skip_whitespace((const char **)&line);
	if (!*line || parse_coordinates(&line, &position.x, &position.y, &position.z))
		return (1);
	skip_whitespace((const char **)&line);
	if (!*line || parse_coordinates(&line, &orientation.x,
			&orientation.y, &orientation.z))
		return (1);
	if (validate_orientation_vector(orientation.x,
			orientation.y, orientation.z))
		return (1);
	skip_whitespace((const char **)&line);
	if (!*line || parse_camera_fov(&line, &fov))
		return (1);
	if (check_only_spaces(line))
		return (1);
	return (0);
}
