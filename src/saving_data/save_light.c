/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:30 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/09 08:38:06 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	save_ambient_light(char *line, t_pix **pix)
{
	t_color	color;
	float	ratio;
	t_light	*ambient_light;

	ambient_light = pix[0][0].lux[0][0];
	if (!ambient_light)
		return ;
	line++;
	skip_whitespace((const char **)&line);
	ratio = ft_strtod(line, &line);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	ambient_light->ratio = ratio;
	ambient_light->color->r = color.r;
	ambient_light->color->g = color.g;
	ambient_light->color->b = color.b;
}

static void	save_other_light(char *line, t_pix **pix, t_num_obj *num_obj)
{
	t_color	color;
	t_coord	position;
	float	ratio;
	t_light	*other_light;

	other_light = pix[0][0].lux[1][num_obj->light];
	if (!other_light)
		return ;
	line++;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &position.x, &position.y, &position.z);
	ratio = ft_strtod(line, &line);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	other_light->p_coord->x = position.x;
	other_light->p_coord->y = position.y;
	other_light->p_coord->z = position.z;
	other_light->ratio = ratio;
	other_light->color->r = color.r;
	other_light->color->g = color.g;
	other_light->color->b = color.b;
	num_obj->light++;
}

void	save_light(char *line, t_pix **pix, t_num_obj *num_obj)
{
	if (line[0] == 'A')
		save_ambient_light(line, pix);
	else if (line[0] == 'L')
		save_other_light(line, pix, num_obj);
}
