/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 13:51:47 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"

/* ----------------------------------------------------------------------------
	Parse et valide le champ de vision de la caméra.
---------------------------------------------------------------------------- */
static int	parse_camera_fov(char **line, float *fov)
{
	*fov = ft_strtod(*line, line);
	return (validate_fov(*fov));
}

/* ----------------------------------------------------------------------------
	Parse et valide la caméra.
---------------------------------------------------------------------------- */
int	validate_camera(char *line)
{
	t_coord	position;
	t_coord	orientation;
	float	fov;

	if (line[0] != 'C' || line[1] != ' ')
		return (1);
	line += 2;
	if (parse_coordinates(&line, &position.x, &position.y, &position.z))
		return (1);
	if (parse_coordinates(&line, &orientation.x,
			&orientation.y, &orientation.z))
		return (1);
	if (validate_orientation_vector(orientation.x, orientation.y,
			orientation.z))
		return (1);
	if (parse_camera_fov(&line, &fov) || check_only_spaces(line))
		return (1);
	return (0);
}
