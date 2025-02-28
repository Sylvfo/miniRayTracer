/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/28 12:33:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

void	skip_whitespace(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

/* ----------------------------------------------------------------------------
	Parse une valeur float et avance le pointeur.
---------------------------------------------------------------------------- */
int	parse_float(char **line, float *value)
{
	*value = ft_strtod(*line, line);
	while (**line == ' ')
		(*line)++;
	return (0);
}

/* ----------------------------------------------------------------------------
	Parse un triplet de float sous la forme x,y,z et avance le pointeur.
---------------------------------------------------------------------------- */
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

/* ----------------------------------------------------------------------------
	Parse les trois composantes de couleur (r, g, b) et avance le pointeur.
---------------------------------------------------------------------------- */
int	parse_color(char **line, int *r, int *g, int *b)
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
