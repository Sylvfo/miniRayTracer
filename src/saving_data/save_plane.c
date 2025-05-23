/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:43 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/08 11:32:00 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	parse_plane_coordinates(char **line, t_coord *coord)
{
	skip_whitespace((const char **)line);
	parse_coordinates(line, &coord->x, &coord->y, &coord->z);
	coord->t = 1;
}

static void	parse_plane_orientation(char **line, t_coord *orientation)
{
	skip_whitespace((const char **)line);
	parse_coordinates(line, &orientation->x, &orientation->y, &orientation->z);
	orientation->t = 0;
}

static void	parse_plane_color(char **line, t_color *color)
{
	skip_whitespace((const char **)line);
	parse_color(line, &color->r, &color->g, &color->b);
}

static void	update_plane_properties(t_obj *plane, t_coord *coord,
		t_coord *orientation, t_color *color)
{
	plane->p_coord->x = coord->x;
	plane->p_coord->y = coord->y;
	plane->p_coord->z = coord->z;
	//rajouté par syl
	plane->p_coord->t = 1;
	plane->color->r = color->r;
	plane->color->g = color->g;
	plane->color->b = color->b;
	plane->v_axe->x = orientation->x;
	plane->v_axe->y = orientation->y;
	plane->v_axe->z = orientation->z;
	plane->type = 2;
}

void	save_plane(char *line, t_pix **pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;
	t_obj		*plane;

	line += 2;
	parse_plane_coordinates(&line, &coord);
	parse_plane_orientation(&line, &orientation);
	parse_plane_color(&line, &color);

	color.r = int_to_float(color.r);
	color.g = int_to_float(color.g);
	color.b = int_to_float(color.b);

	plane = pix[0][0].obj[2][num_obj->plan];
	if (!plane)
		return ;
	update_plane_properties(plane, &coord, &orientation, &color);
	num_obj->plan++;
}
