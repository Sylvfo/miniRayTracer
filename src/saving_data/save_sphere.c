/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/13 14:35:16 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	set_sphere_color(t_obj *sphere, t_color *color)
{
	sphere->color->r = color->r;
	sphere->color->g = color->g;
	sphere->color->b = color->b;
}

static void	set_sphere_coord(t_obj *sphere, t_coord *coord)
{
	sphere->p_coord->x = coord->x;
	sphere->p_coord->y = coord->y;
	sphere->p_coord->z = coord->z;
	sphere->p_coord->t = 1;
}

static void	set_sphere_defaults(t_obj *sphere, float diameter)
{
	sphere->diam = diameter / 2.0f;
	sphere->radius = diameter / 2.0f; // Corrected from diameter / 4.0f
	sphere->difuse = 0.7;
	sphere->specular = 0.2;
	sphere->type = SPHERE;
}

void	save_sphere(char *line, t_program_context *context)
{
	t_coord	coord;
	t_color	color;
	float	diameter;
	t_obj	*sphere;

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
	sphere = context->pix[0][0]->obj[1][context->num_obj->sphere];
	if (!sphere)
		return ;
	set_sphere_coord(sphere, &coord);
	set_sphere_color(sphere, &color);
	set_sphere_defaults(sphere, diameter);
	context->num_obj->sphere++;
}
