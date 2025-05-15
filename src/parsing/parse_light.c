/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:59:19 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 12:10:34 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	validate_ambient(char *line)
{
	float	ratio;
	t_color	color;

	if (!line || *line != 'A')
		return (1);
	line++;
	skip_whitespace((const char **)&line);
	if (!*line)
		return (1);
	ratio = ft_strtod(line, &line);
	if (!line || !*line || ratio < 0.0f || ratio > 1.0f)
		return (1);
	skip_whitespace((const char **)&line);
	if (!*line || parse_color(&line, &color.r, &color.g, &color.b)
		|| check_only_spaces(line))
		return (1);
	return (0);
}

int	validate_light(char *line, t_num_obj *num_obj)
{
	t_coord	posi;
	float	brightness;
	t_color	color;

	if (!line || !num_obj || *line != 'L')
		return (1);
	line++;
	skip_whitespace((const char **)&line);
	if (!*line || parse_coordinates(&line, &posi.x, &posi.y, &posi.z))
		return (1);
	if (!*line)
		return (1);
	brightness = ft_strtod(line, &line);
	if (!line || !*line || brightness < 0.0f || brightness > 1.0f)
		return (1);
	skip_whitespace((const char **)&line);
	if (!*line || parse_color(&line, &color.r, &color.g, &color.b)
		|| check_only_spaces(line))
		return (1);
	num_obj->light++;
	return (0);
}
