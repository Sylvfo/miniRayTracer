/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/21 13:27:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"

/* ----------------------------------------------------------------------------
	Valide les données d'ambiance contenues dans 'line'.
---------------------------------------------------------------------------- */
int	validate_ambient(char *line)
{
	float	ratio;
	t_color	color;

	if (line[0] != 'A' || line[1] != ' ')
		return (1);
	line++;
	skip_whitespace((const char **)&line);
	ratio = ft_strtod(line, &line);
	if (ratio < 0.0f || ratio > 1.0f)
		return (1);
	skip_whitespace((const char **)&line);
	if (parse_color(&line, &color.r, &color.g, &color.b)
		|| check_only_spaces(line))
		return (1);
	return (0);
}

/* ----------------------------------------------------------------------------
	Valide les données de lumière contenues dans 'line'.
---------------------------------------------------------------------------- */
int	validate_light(char *line)
{
	t_coord	position;
	float	brightness;
	t_color	color;

	if (line[0] != 'L' || line[1] != ' ')
		return (1);
	line++;
	skip_whitespace((const char **)&line);
	if (parse_coordinates(&line, &position.x, &position.y, &position.z))
		return (1);
	brightness = ft_strtod(line, &line);
	if (brightness < 0.0f || brightness > 1.0f)
		return (1);
	skip_whitespace((const char **)&line);
	if (parse_color(&line, &color.r, &color.g, &color.b)
		|| check_only_spaces(line))
		return (1);
	return (0);
}
