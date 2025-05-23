/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:16:28 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/09 08:38:06 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	parse_object_center(char **line, t_coord *center)
{
	return (parse_coordinates(line, &center->x, &center->y, &center->z));
}

/* ----------------------------------------------------------------------------
	Parse et valide la couleur de l'objet.
---------------------------------------------------------------------------- */
static int	parse_object_color(char **line, t_color *color)
{
	return (parse_color(line, &color->r, &color->g, &color->b));
}

/* ----------------------------------------------------------------------------
	Parse et valide une sphère.
---------------------------------------------------------------------------- */
int	validate_sphere(char *line, t_num_obj *num_obj)
{
	t_coord	center;
	float	diameter;
	t_color	color;

	if (line[0] != 's' || line[1] != 'p' || line[2] != ' ')
		return (1);
	line += 2;
	skip_whitespace((const char **)&line);
	if (parse_object_center(&line, &center))
		return (1);
	if (parse_dimension(&line, &diameter))
		return (1);
	if (parse_object_color(&line, &color) || check_only_spaces(line))
		return (1);
	num_obj->sphere++;
	return (0);
}

/* ----------------------------------------------------------------------------
	Parse et valide un cylindre.
---------------------------------------------------------------------------- */
static int	parse_cylinder_axis(char **line, t_coord *axis)
{
	return (parse_coordinates(line, &axis->x, &axis->y, &axis->z));
}

int	validate_cylinder(char *line, t_num_obj *num_obj)
{
	t_coord	center;
	t_coord	axis;
	float	diameter;
	float	height;
	t_color	color;

	if (line[0] != 'c' || line[1] != 'y' || line[2] != ' ')
		return (1);
	line += 2;
	skip_whitespace((const char **)&line);
	if (parse_object_center(&line, &center))
		return (1);
	if (parse_cylinder_axis(&line, &axis)
		|| validate_orientation_vector(axis.x, axis.y, axis.z))
		return (1);
	if (parse_dimension(&line, &diameter) || parse_dimension(&line, &height))
		return (1);
	if (parse_object_color(&line, &color) || check_only_spaces(line))
		return (1);
	num_obj->cylinder++;
	return (0);
}
