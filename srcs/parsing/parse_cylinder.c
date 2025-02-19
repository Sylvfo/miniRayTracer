/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:54:32 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int validate_cylinder(char *line)
{
	float x, y, z;
	float nx, ny, nz;
	float diameter, height;
	int r, g, b;

	if (line[0] != 'c' || line[1] != 'y' || line[2] != ' ')
		return (1);
	line += 3;
	if (parse_coordinates(&line, &x, &y, &z))
		return (1);
	while (*line == ' ')
		line++;
	if (parse_coordinates(&line, &nx, &ny, &nz))
		return (1);
	if (nx < -1.0f || nx > 1.0f || ny < -1.0f || ny > 1.0f || nz < -1.0f || nz > 1.0f)
		return (1);
	while (*line == ' ')
		line++;
	diameter = ft_strtod(line, &line);
	if (diameter <= 0.0f)
		return (1);
	while (*line && *line != ' ')
		line++;
	if (*line == '\0' || *(++line) == '\0')
		return (1);
	height = ft_strtod(line, &line);
	if (height <= 0.0f)
		return (1);
	while (*line && *line != ' ')
		line++;
	if (*line == '\0' || *(++line) == '\0')
		return (1);
	if (parse_color(&line, &r, &g, &b))
		return (1);
	if (check_only_spaces(line))
		return (1);
	return (0);
}
