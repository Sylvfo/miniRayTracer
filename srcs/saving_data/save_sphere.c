/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:33:45 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 07:34:33 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

static void	set_sphere_data(t_pix ***pix, t_coord coord, t_color color,
	int sphere_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[1][sphere_index]->p_coord->x = coord.x;
			(*pix)[i][j].obj[1][sphere_index]->p_coord->y = coord.y;
			(*pix)[i][j].obj[1][sphere_index]->p_coord->z = coord.z;
			(*pix)[i][j].obj[1][sphere_index]->color->r = color.r;
			(*pix)[i][j].obj[1][sphere_index]->color->g = color.g;
			(*pix)[i][j].obj[1][sphere_index]->color->b = color.b;
			j++;
		}
		i++;
	}
}

static void	set_sphere_diameter(t_pix ***pix, float diameter, int sphere_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[1][sphere_index]->diam = diameter;
			j++;
		}
		i++;
	}
}

void	save_sphere(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_color		color;
	float		diameter;

	line += 2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_float(&line, &diameter);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	set_sphere_data(pix, coord, color, num_obj->sphere);
	set_sphere_diameter(pix, diameter, num_obj->sphere);
	num_obj->sphere++;
}
