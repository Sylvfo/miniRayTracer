/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:54:18 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int validate_sphere(char *line)
{
	float x, y, z;
	float diameter;
	int r, g, b;

	if (line[0] != 's' || line[1] != 'p' || line[2] != ' ')
		return (1);
	line += 3;
	if (parse_coordinates(&line, &x, &y, &z))
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
	if (parse_color(&line, &r, &g, &b))
		return (1);
	if (check_only_spaces(line))
		return (1);
	return (0);
}
