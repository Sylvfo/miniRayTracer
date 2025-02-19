/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:53:55 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/* ----------------------------------------------------------------------------
	Vérifie que la chaîne ne contient que des espaces.
---------------------------------------------------------------------------- */
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

/* ----------------------------------------------------------------------------
	Parse un triplet de float sous la forme x,y,z. Avance le pointeur.
---------------------------------------------------------------------------- */
int	parse_coordinates(char **line, float *x, float *y, float *z)
{
	*x = ft_strtod(*line, line);
	while (**line && **line != ',' && **line != ' ')
		(*line)++;
	if (**line != ',')
		return (1);
	(*line)++;
	*y = ft_strtod(*line, line);
	while (**line && **line != ',' && **line != ' ')
		(*line)++;
	if (**line != ',')
		return (1);
	(*line)++;
	*z = ft_strtod(*line, line);
	while (**line && **line != ' ')
		(*line)++;
	if (**line != ' ')
		return (1);
	return (0);
}

/* ----------------------------------------------------------------------------
	Parse les trois composantes de couleur (r, g, b).
	Avance le pointeur et renvoie 1 en cas d'erreur.
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
