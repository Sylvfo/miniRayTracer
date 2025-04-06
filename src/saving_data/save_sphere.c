/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/06 12:15:47 by syl              ###   ########.fr       */
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

	color.r = int_to_float(color.r);
	color.g = int_to_float(color.g);
	color.b = int_to_float(color.b);

	sphere = pix[0][0].obj[1][num_obj->sphere];
	if (!sphere)
		return ;
	sphere->p_coord->x = coord.x;
	sphere->p_coord->y = coord.y;
	sphere->p_coord->z = coord.z;
	//rajouté par sylvie
	sphere->p_coord->t = 1;
	sphere->diam = diameter;
	sphere->color->r = color.r;
	sphere->color->g = color.g;
	sphere->color->b = color.b;
	sphere->difuse = 0.7;
	sphere->specular = 0.2;
	num_obj->sphere++;
}
