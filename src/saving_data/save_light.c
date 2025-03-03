/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:56:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/02 19:41:31 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

static void	save_ambient_light(char *line, t_pix ***pix)
{
	t_color	color;
	int		i;
	int		j;
	float	ratio;

	i = 0;
	line++;
	skip_whitespace((const char **)&line);
	ratio = ft_strtod(line, &line);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].lux[0][0]->ratio = ratio;
			(*pix)[i][j].lux[0][0]->color->r = color.r;
			(*pix)[i][j].lux[0][0]->color->g = color.g;
			(*pix)[i][j].lux[0][0]->color->b = color.b;
			j++;
		}
		i++;
	}
}

static void	save_other_light(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	t_color	color;
	t_coord	position;
	int		i;
	int		j;
	float	ratio;

	i = 0;
	line++;
	skip_whitespace((const char **)&line);
	parse_coordinates(&line, &position.x, &position.y, &position.z);
	ratio = ft_strtod(line, &line);
	skip_whitespace((const char **)&line);
	parse_color(&line, &color.r, &color.g, &color.b);
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			(*pix)[i][j].lux[1][num_obj->light]->p_coord->x = position.x;
			(*pix)[i][j].lux[1][num_obj->light]->p_coord->y = position.y;
			(*pix)[i][j].lux[1][num_obj->light]->p_coord->z = position.z;
			(*pix)[i][j].lux[1][num_obj->light]->ratio = ratio;
			(*pix)[i][j].lux[1][num_obj->light]->color->r = color.r;
			(*pix)[i][j].lux[1][num_obj->light]->color->g = color.g;
			(*pix)[i][j].lux[1][num_obj->light]->color->b = color.b;
			j++;
		}
		i++;
	}
	num_obj->light++;
}

void	save_light(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	if (line[0] == 'A')
		save_ambient_light(line, pix);
	else if (line[0] == 'L')
		save_other_light(line, pix, num_obj);
}
