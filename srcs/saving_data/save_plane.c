/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:43 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/07 17:26:27 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	save_plane(char *line, t_pix **pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;
	t_obj		*plane;

	line += 2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &orientation.x, &orientation.y, &orientation.z);
	orientation.t = 0;
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	plane = pix[0][0].obj[2][num_obj->plan];
	if (!plane)
		return ;
	plane->p_coord->x = coord.x;
	plane->p_coord->y = coord.y;
	plane->p_coord->z = coord.z;
	plane->color->r = color.r;
	plane->color->g = color.g;
	plane->color->b = color.b;
	plane->v_axe->x = orientation.x;
	plane->v_axe->y = orientation.y;
	plane->v_axe->z = orientation.z;
	num_obj->plan++;
}
