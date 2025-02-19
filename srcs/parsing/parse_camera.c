/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 13:07:31 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

static int	validate_coordinates(char **line, float *x, float *y, float *z)
{
	if (parse_coordinates(line, x, y, z))
		return (1);
	while (**line == ' ')
		(*line)++;
	return (0);
}

static int	validate_orientation_vector(float ox, float oy, float oz)
{
	if (ox < -1.0f || ox > 1.0f
		|| oy < -1.0f || oy > 1.0f
		|| oz < -1.0f || oz > 1.0f)
		return (1);
	if (ox == 0.0f && oy == 0.0f && oz == 0.0f)
		return (1);
	return (0);
}

static int	validate_fov(char **line, float *fov)
{
	*fov = ft_strtod(*line, line);
	while (**line && **line != ' ')
		(*line)++;
	if (*fov <= 0.0f || *fov > 180.0f)
		return (1);
	return (0);
}

static int	parse_camera_coordinates(char **line)
{
	float	x;
	float	y;
	float	z;

	if (validate_coordinates(line, &x, &y, &z))
		return (1);
	return (0);
}

static int	parse_camera_orientation(char **line)
{
	float	ox;
	float	oy;
	float	oz;

	if (validate_coordinates(line, &ox, &oy, &oz))
		return (1);
	if (validate_orientation_vector(ox, oy, oz))
		return (1);
	return (0);
}

static int	parse_camera_fov(char **line)
{
	float	fov;

	if (validate_fov(line, &fov))
		return (1);
	return (0);
}

int	validate_camera(char *line)
{
	if (line[0] != 'C' || line[1] != ' ')
		return (1);
	line += 2;
	if (parse_camera_coordinates(&line))
		return (1);
	if (parse_camera_orientation(&line))
		return (1);
	if (parse_camera_fov(&line))
		return (1);
	if (check_only_spaces(line))
		return (1);
	return (0);
}
