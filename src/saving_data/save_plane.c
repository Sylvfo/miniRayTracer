/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:33:45 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/03 07:34:55 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

static void	set_plane_data(t_pix ***pix, t_coord coord, t_color color,
	int plane_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[2][plane_index]->p_coord->x = coord.x;
			(*pix)[i][j].obj[2][plane_index]->p_coord->y = coord.y;
			(*pix)[i][j].obj[2][plane_index]->p_coord->z = coord.z;
			(*pix)[i][j].obj[2][plane_index]->color->r = color.r;
			(*pix)[i][j].obj[2][plane_index]->color->g = color.g;
			(*pix)[i][j].obj[2][plane_index]->color->b = color.b;
			j++;
		}
		i++;
	}
}

static void	set_plane_orientation(t_pix ***pix, t_coord orientation,
	int plane_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[2][plane_index]->v_axe->x = orientation.x;
			(*pix)[i][j].obj[2][plane_index]->v_axe->y = orientation.y;
			(*pix)[i][j].obj[2][plane_index]->v_axe->z = orientation.z;
			j++;
		}
		i++;
	}
}

void	save_plane(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;

	line += 2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &orientation.x, &orientation.y, &orientation.z);
	orientation.t = 0;
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	set_plane_data(pix, coord, color, num_obj->plan);
	set_plane_orientation(pix, orientation, num_obj->plan);
	num_obj->plan++;
}
