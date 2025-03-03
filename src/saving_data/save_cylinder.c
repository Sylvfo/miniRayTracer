/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:33:45 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 07:33:54 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

static void	set_cylinder_data(t_pix ***pix, t_coord coord, t_color color,
	int cylinder_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[3][cylinder_index]->p_coord->x = coord.x;
			(*pix)[i][j].obj[3][cylinder_index]->p_coord->y = coord.y;
			(*pix)[i][j].obj[3][cylinder_index]->p_coord->z = coord.z;
			(*pix)[i][j].obj[3][cylinder_index]->color->r = color.r;
			(*pix)[i][j].obj[3][cylinder_index]->color->g = color.g;
			(*pix)[i][j].obj[3][cylinder_index]->color->b = color.b;
			j++;
		}
		i++;
	}
}

static void	set_cylinder_orientation(t_pix ***pix, t_coord orientation,
	int cylinder_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[3][cylinder_index]->v_axe->x = orientation.x;
			(*pix)[i][j].obj[3][cylinder_index]->v_axe->y = orientation.y;
			(*pix)[i][j].obj[3][cylinder_index]->v_axe->z = orientation.z;
			j++;
		}
		i++;
	}
}

static void	set_cylinder_dimensions(t_pix ***pix, float diameter, float height,
	int cylinder_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[3][cylinder_index]->diam = diameter;
			(*pix)[i][j].obj[3][cylinder_index]->height = height;
			j++;
		}
		i++;
	}
}

void	save_cylinder(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;
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
	set_cylinder_data(pix, coord, color, num_obj->cylinder);
	set_cylinder_orientation(pix, orientation, num_obj->cylinder);
	set_cylinder_dimensions(pix, diameter, height, num_obj->cylinder);
	num_obj->cylinder++;
}
