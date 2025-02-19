/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:54:38 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/* ----------------------------------------------------------------------------
	Valide les données d'ambiance contenues dans 'line'.
---------------------------------------------------------------------------- */
int	validate_ambient(char *line)
{
	float	ratio;
	int		r;
	int		g;
	int		b;

	if (line[0] != 'A' || line[1] != ' ')
		return (1);
	line += 2;
	ratio = ft_strtod(line, &line);
	while (*line && *line != ' ')
		line++;
	if (*line == '\0' || *(++line) == '\0')
		return (1);
	if (parse_color(&line, &r, &g, &b))
		return (1);
	if (check_only_spaces(line))
		return (1);
	if (ratio < 0.0f || ratio > 1.0f)
		return (1);
	return (0);
}
