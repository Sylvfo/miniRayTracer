/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:04:31 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/21 19:18:24 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	parse_one_color(char **line, float *value)
{
	skip_whitespace((const char **)line);
	*value = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	skip_whitespace((const char **)line);
	return (0);
}

static int	expect_comma(char **line)
{
	if (**line != ',')
		return (1);
	(*line)++;
	skip_whitespace((const char **)line);
	return (0);
}

int	parse_color(char **line, float *r, float *g, float *b)
{
	if (parse_one_color(line, r) || expect_comma(line))
		return (1);
	if (parse_one_color(line, g) || expect_comma(line))
		return (1);
	if (parse_one_color(line, b))
		return (1);
	if (**line == ',')
		return (1);
	if (*r < 0 || *r > 255 || *g < 0 || *g > 255 || *b < 0 || *b > 255)
		return (1);
	return (0);
}
