/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:00:31 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/29 16:50:10 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	skip_whitespace(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

int	parse_float(char **line, float *value)
{
	*value = ft_strtod(*line, line);
	while (**line == ' ')
		(*line)++;
	return (0);
}

int	parse_coordinates(char **line, float *x, float *y, float *z)
{
	if (parse_float(line, x))
		return (1);
	if (**line != ',')
		return (1);
	(*line)++;
	if (parse_float(line, y))
		return (1);
	if (**line != ',')
		return (1);
	(*line)++;
	if (parse_float(line, z))
		return (1);
	return (0);
}

int	parse_color(char **line, float *r, float *g, float *b)
{
	*r = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line != ',')
		return (1);
	(*line)++;
	*g = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line != ',')
		return (1);
	(*line)++;
	*b = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line == ',')
		return (1);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (1);
	return (0);
}

int	parse_dimension(char **line, float *dimension)
{
	*dimension = ft_strtod(*line, line);
	if (*dimension <= 0.0f)
		return (1);
	while (**line == ' ')
		(*line)++;
	return (0);
}

int	check_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
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
