/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:55:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/* ----------------------------------------------------------------------------
	Valide les données de lumière contenues dans 'line'.
	Format : L x,y,z brightness R,G,B
---------------------------------------------------------------------------- */
int	validate_light(char *line)
{
	float	x, y, z;
	float	brightness;
	int		r, g, b;

	if (line[0] != 'L' || line[1] != ' ')
		return (1);
	line += 2;
	if (parse_coordinates(&line, &x, &y, &z))
		return (1);
	while (*line == ' ')
		line++;
	brightness = ft_strtod(line, &line);
	if (brightness < 0.0f || brightness > 1.0f)
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
