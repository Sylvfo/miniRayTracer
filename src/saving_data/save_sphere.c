/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/09 08:38:06 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	save_sphere(char *line, t_pix **pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_color		color;
	float		diameter;
	t_obj		*sphere;

	line += 2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_float(&line, &diameter);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	sphere = pix[0][0].obj[1][num_obj->sphere];
	if (!sphere)
		return ;
	sphere->p_coord->x = coord.x;
	sphere->p_coord->y = coord.y;
	sphere->p_coord->z = coord.z;
	sphere->diam = diameter;
	sphere->color->r = color.r;
	sphere->color->g = color.g;
	sphere->color->b = color.b;
	num_obj->sphere++;
}
