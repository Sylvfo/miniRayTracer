/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:00:31 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 12:11:14 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	skip_whitespace(const char **str)
{
	while (*str && **str && ft_isspace(**str))
		(*str)++;
}

int	parse_float(char **line, float *value)
{
	if (!line || !*line || !**line)
		return (1);
	*value = ft_strtod(*line, line);
	if (!*line || !**line)
		return (1);
	while (**line == ' ')
		(*line)++;
	return (0);
}

int	parse_coordinates(char **line, float *x, float *y, float *z)
{
	if (!line || !*line || !x || !y || !z || !**line)
		return (1);
	if (parse_float(line, x))
		return (1);
	if (!**line || **line != ',')
		return (1);
	(*line)++;
	if (parse_float(line, y))
		return (1);
	if (!**line || **line != ',')
		return (1);
	(*line)++;
	if (parse_float(line, z))
		return (1);
	if (!**line)
		return (1);
	return (0);
}
