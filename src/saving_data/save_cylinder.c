/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/07 17:56:57 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	save_cylinder(char *line, t_pix **pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;
	t_obj		*cylinder;
	float		diameter;
	float		height;

	line += 2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &orientation.x, &orientation.y, &orientation.z);
	orientation.t = 0;
	skip_whitespace((const char **)&line);
	parse_float(&line, &diameter);
	skip_whitespace((const char **)&line);
	parse_float(&line, &height);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	cylinder = pix[0][0].obj[3][num_obj->cylinder];
	if (!cylinder)
		return ;
	cylinder->diam = diameter;
	cylinder->height = height;
	cylinder->p_coord->x = coord.x;
	cylinder->p_coord->y = coord.y;
	cylinder->p_coord->y = coord.y;
	cylinder->color->r = color.r;
	cylinder->color->g = color.g;
	cylinder->color->b = color.b;
	cylinder->v_axe->x = orientation.x;
	cylinder->v_axe->y = orientation.y;
	cylinder->v_axe->z = orientation.z;
	num_obj->cylinder++;
}
