/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:16:28 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 12:10:56 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	parse_object_center(char **line, t_coord *center)
{
	if (!line || !*line || !center || !**line)
		return (1);
	return (parse_coordinates(line, &center->x, &center->y, &center->z));
}

static int	parse_object_color(char **line, t_color *color)
{
	if (!line || !*line || !color || !**line)
		return (1);
	return (parse_color(line, &color->r, &color->g, &color->b));
}

int	validate_sphere(char *line, t_num_obj *num_obj)
{
	t_coord	center;
	float	diameter;
	t_color	color;

	if (!line || !num_obj || line[0] != 's' || line[1] != 'p')
		return (1);
	line += 2;
	skip_whitespace((const char **)&line);
	if (!*line || parse_object_center(&line, &center))
		return (1);
	if (!*line || parse_dimension(&line, &diameter))
		return (1);
	if (!*line || parse_object_color(&line, &color) || check_only_spaces(line))
		return (1);
	num_obj->sphere++;
	return (0);
}

static int	parse_cylinder_axis(char **line, t_coord *axis)
{
	if (!line || !*line || !axis || !**line)
		return (1);
	return (parse_coordinates(line, &axis->x, &axis->y, &axis->z));
}

int	validate_cylinder(char *line, t_num_obj *num_obj)
{
	t_coord	center;
	t_coord	axis;
	float	diameter;
	float	height;
	t_color	color;

	if (!line || !num_obj || line[0] != 'c' || line[1] != 'y')
		return (1);
	line += 2;
	skip_whitespace((const char **)&line);
	if (!*line || parse_object_center(&line, &center))
		return (1);
	if (!*line || parse_cylinder_axis(&line, &axis)
		|| validate_orientation_vector(axis.x, axis.y, axis.z))
		return (1);
	if (!*line || parse_dimension(&line, &diameter))
		return (1);
	if (!*line || parse_dimension(&line, &height))
		return (1);
	if (!*line || parse_object_color(&line, &color) || check_only_spaces(line))
		return (1);
	num_obj->cylinder++;
	return (0);
}
