/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:04:44 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 12:11:05 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	is_valid_dimension(float dimension)
{
	return (dimension > 0.0f);
}

int	parse_dimension(char **line, float *dimension)
{
	if (!line || !*line || !dimension || !**line)
		return (1);
	*dimension = ft_strtod(*line, line);
	if (!is_valid_dimension(*dimension) || !*line || !**line)
		return (1);
	skip_whitespace((const char **)line);
	if (!**line)
		return (1);
	return (0);
}

int	check_only_spaces(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (1);
		str++;
	}
	return (0);
}

int	validate_orientation_vector(float ox, float oy, float oz)
{
	if (ox < -1.0f || ox > 1.0f
		|| oy < -1.0f || oy > 1.0f
		|| oz < -1.0f || oz > 1.0f)
		return (1);
	if (ox == 0.0f && oy == 0.0f && oz == 0.0f)
		return (1);
	return (0);
}

int	validate_fov(float fov)
{
	return (fov <= 0.0f || fov > 180.0f);
}
