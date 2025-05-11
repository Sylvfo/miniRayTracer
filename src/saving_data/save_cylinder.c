/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:39 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 15:48:40 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	parse_cylinder_params(char **line, t_cylinder_params *params)
{
	skip_whitespace((const char **)line);
	parse_coordinates(line, &params->coord.x, &params->coord.y,
		&params->coord.z);
	params->coord.t = 1;
	skip_whitespace((const char **)line);
	parse_coordinates(line, &params->orientation.x, &params->orientation.y,
		&params->orientation.z);
	params->orientation.t = 0;
	skip_whitespace((const char **)line);
	parse_float(line, &params->diameter);
	skip_whitespace((const char **)line);
	parse_float(line, &params->height);
	skip_whitespace((const char **)line);
	parse_color(line, &params->color.r, &params->color.g, &params->color.b);
	params->color.r = int_to_float(params->color.r);
	params->color.g = int_to_float(params->color.g);
	params->color.b = int_to_float(params->color.b);
}

static void	set_cylinder_obj(t_obj *cylinder, t_cylinder_params *params)
{
	cylinder->diam = params->diameter;
	cylinder->height = params->height;
	cylinder->p_coord->x = params->coord.x;
	cylinder->p_coord->y = params->coord.y;
	cylinder->p_coord->z = params->coord.z;
	cylinder->color->r = params->color.r;
	cylinder->color->g = params->color.g;
	cylinder->color->b = params->color.b;
	cylinder->v_axe->x = params->orientation.x;
	cylinder->v_axe->y = params->orientation.y;
	cylinder->v_axe->z = params->orientation.z;
	cylinder->type = CYLINDER;
	cylinder->closed_up = false;
	cylinder->closed_down = true;
}

void	save_cylinder(char *line, t_pix **pix, t_num_obj *num_obj)
{
	t_cylinder_params	params;
	t_obj				*cylinder;

	line += 2;
	parse_cylinder_params(&line, &params);
	cylinder = pix[0][0].obj[3][num_obj->cylinder];
	if (!cylinder)
		return ;
	set_cylinder_obj(cylinder, &params);
	num_obj->cylinder++;
}
