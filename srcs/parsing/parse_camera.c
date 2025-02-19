/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 08:54:35 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/* ----------------------------------------------------------------------------
Valide les données de caméra contenues dans 'line'.
Format : C x,y,z 0,0,1 70
∗ view point: x,y,z
∗ orientation vector (normalisé, chaque composante dans [-1,1])
∗ FOV: horizontal field of view en degrés dans [0,180]
---------------------------------------------------------------------------- */
int	validate_camera(char *line)
{
	float	x, y, z;
	float	ox, oy, oz;
	float	fov;

	if (line[0] != 'C' || line[1] != ' ')
		return (1);
	line += 2;
	if (parse_coordinates(&line, &x, &y, &z))
		return (1);
	while (*line == ' ')
		line++;
	if (parse_coordinates(&line, &ox, &oy, &oz))
		return (1);
	if (ox < -1.0f || ox > 1.0f ||
		oy < -1.0f || oy > 1.0f ||
		oz < -1.0f || oz > 1.0f)
		return (1);
	if (ox == 0.0f && oy == 0.0f && oz == 0.0f)
		return (1); // Le vecteur d'orientation ne peut pas être nul
	while (*line == ' ')
		line++;
	fov = ft_strtod(line, &line);
	while (*line && *line != ' ')
		line++;
	if (fov <= 0.0f || fov > 180.0f)
		return (1);
	if (check_only_spaces(line))
		return (1);
	return (0);
}