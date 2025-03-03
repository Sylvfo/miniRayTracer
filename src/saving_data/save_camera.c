/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:56:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/02 21:42:48 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

void	save_camera(char *line, t_pix ***pix)
{
	t_coord	position;
	t_coord	orientation;
	float	fov;
	int		i;
	int		j;

	i = 0;
	line++;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &position.x, &position.y, &position.z);
	position.t = 1;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &orientation.x, &orientation.y, &orientation.z);
	orientation.t = 0;
	skip_whitespace((const char **)&line);
	fov = ft_strtod(line, &line);
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].cam->p_coord->x = position.x;
			(*pix)[i][j].cam->p_coord->y = position.y;
			(*pix)[i][j].cam->p_coord->z = position.z;
			(*pix)[i][j].cam->v_axe->x = orientation.x;
			(*pix)[i][j].cam->v_axe->y = orientation.y;
			(*pix)[i][j].cam->v_axe->z = orientation.z;
			(*pix)[i][j].cam->fov = fov;
			j++;
		}
		i++;
	}
}
