/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/04 15:45:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	save_camera(char *line, t_pix **pix)
{
	t_coord		position;
	t_coord		orientation;
	t_camera	*cam;
	float		fov;

	line++;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &position.x, &position.y, &position.z);
	position.t = 1;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &orientation.x, &orientation.y, &orientation.z);
	orientation.t = 0;
	skip_whitespace((const char **)&line);
	fov = ft_strtod(line, &line);
	cam = pix[0][0].cam;
	cam->p_coord->x = position.x;
	cam->p_coord->y = position.y;
	cam->p_coord->z = position.z;
	cam->v_axe->x = orientation.x;
	cam->v_axe->y = orientation.y;
	cam->v_axe->z = orientation.z;
	cam->fov = fov;
}
