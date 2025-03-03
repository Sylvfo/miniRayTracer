/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:56:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/02 21:56:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	save_sphere(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_color		color;
	float		diameter;
	int			i;
	int			j;

	i = 0;
	line+=2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_float(&line, &diameter);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[1][num_obj->sphere]->p_coord->x = coord.x;
			(*pix)[i][j].obj[1][num_obj->sphere]->p_coord->y = coord.y;
			(*pix)[i][j].obj[1][num_obj->sphere]->p_coord->z = coord.z;
			(*pix)[i][j].obj[1][num_obj->sphere]->diam = diameter;
			(*pix)[i][j].obj[1][num_obj->sphere]->color->r = color.r;
			(*pix)[i][j].obj[1][num_obj->sphere]->color->g = color.g;
			(*pix)[i][j].obj[1][num_obj->sphere]->color->b = color.b;
			j++;
		}
		i++;
	}
	num_obj->sphere++;
}

void	save_plane(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;
	int			i;
	int			j;

	i = 0;
	line+=2;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &coord.x, &coord.y, &coord.z);
	coord.t = 1;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &orientation.x, &orientation.y, &orientation.z);
	orientation.t = 0;
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[2][num_obj->plan]->p_coord->x = coord.x;
			(*pix)[i][j].obj[2][num_obj->plan]->p_coord->y = coord.y;
			(*pix)[i][j].obj[2][num_obj->plan]->p_coord->z = coord.z;
			(*pix)[i][j].obj[2][num_obj->plan]->v_axe->x = orientation.x;
			(*pix)[i][j].obj[2][num_obj->plan]->v_axe->y = orientation.y;
			(*pix)[i][j].obj[2][num_obj->plan]->v_axe->z = orientation.z;
			(*pix)[i][j].obj[2][num_obj->plan]->color->r = color.r;
			(*pix)[i][j].obj[2][num_obj->plan]->color->g = color.g;
			(*pix)[i][j].obj[2][num_obj->plan]->color->b = color.b;
			j++;
		}
		i++;
	}
	num_obj->plan++;
}

void	save_cylinder(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_coord		coord;
	t_coord		orientation;
	t_color		color;
	float		diameter;
	float		height;
	int			i;
	int			j;

	i = 0;
	line+=2;
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
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].obj[3][num_obj->cylinder]->p_coord->x = coord.x;
			(*pix)[i][j].obj[3][num_obj->cylinder]->p_coord->y = coord.y;
			(*pix)[i][j].obj[3][num_obj->cylinder]->p_coord->z = coord.z;
			(*pix)[i][j].obj[3][num_obj->cylinder]->v_axe->x = orientation.x;
			(*pix)[i][j].obj[3][num_obj->cylinder]->v_axe->y = orientation.y;
			(*pix)[i][j].obj[3][num_obj->cylinder]->v_axe->z = orientation.z;
			(*pix)[i][j].obj[3][num_obj->cylinder]->diam = diameter;
			(*pix)[i][j].obj[3][num_obj->cylinder]->height = height;
			(*pix)[i][j].obj[3][num_obj->cylinder]->color->r = color.r;
			(*pix)[i][j].obj[3][num_obj->cylinder]->color->g = color.g;
			(*pix)[i][j].obj[3][num_obj->cylinder]->color->b = color.b;
			j++;
		}
		i++;
	}
	num_obj->cylinder++;
}

void	save_object(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	if (line[0] == 's' && line[1] == 'p')
		save_sphere(line, pix, num_obj);
	else if (line[0] == 'p' && line[1] == 'l')
		save_plane(line, pix, num_obj);
	else if (line[0] == 'c' && line[1] == 'y')
		save_cylinder(line, pix, num_obj);
}
