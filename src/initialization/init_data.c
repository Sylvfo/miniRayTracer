/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:47:24 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 18:07:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static t_pix	**init_pix_row(int cols)
{
	t_pix	**row;
	int		y;
	int		k;

	row = ft_calloc(cols, sizeof(t_pix *));
	if (!row)
		return (NULL);
	y = 0;
	while (y < cols)
	{
		row[y] = malloc(sizeof(t_pix));
		if (!row[y])
		{
			k = 0;
			while (k < y)
				free(row[k++]);
			free(row);
			return (NULL);
		}
		y++;
	}
	return (row);
}

static t_pix	***init_pix_matrix(int rows, int cols, t_num_obj *num_obj)
{
	t_pix	***pix;
	int		x;

	pix = malloc(rows * sizeof(t_pix **));
	if (!pix)
		return (NULL);
	x = 0;
	while (x < rows)
	{
		pix[x] = init_pix_row(cols);
		if (!pix[x])
		{
			free_pix(pix, x, cols, num_obj);
			return (NULL);
		}
		x++;
	}
	return (pix);
}

t_color	*init_color(void)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->r = 255;
	color->g = 255;
	color->b = 255;
	color->rgb = 0;
	return (color);
}

void	assign_camera_obj_light_to_pix(t_pix ***pix, t_camera *cam,
	t_obj ***obj, t_light ***lux)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->cam = cam;
			pix[x][y]->obj = obj;
			pix[x][y]->lux = lux;
			pix[x][y]->color = init_color();
			if (!pix[x][y])
			{
				printf("PIX[%d][%d] is NULL !!\n", x, y);
			}
			else if (!pix[x][y]->cam || !pix[x][y]->obj || !pix[x][y]->lux)
			{
				printf("PIX[%d][%d] has NULL sub-pointers !!\n", x, y);
			}
			y++;
		}
		x++;
	}
}

t_pix	***init_data(t_num_obj *num_obj)
{
	t_pix		***pix;
	t_camera	*cam;
	t_obj		***obj;
	t_light		***lux;
	t_hits		***hits;

	pix = init_pix_matrix(WND_WIDTH, WND_HEIGHT, num_obj);
	if (!pix)
		return (NULL);
	obj = init_object(num_obj);
	if (!obj)
	{
		free_pix(pix, WND_WIDTH, WND_HEIGHT, num_obj);
		return (NULL);
	}
	cam = init_camera();
	if (!cam)
	{
		free_object(obj, num_obj);
		free_pix(pix, WND_WIDTH, WND_HEIGHT, num_obj);
		return (NULL);
	}
	lux = init_light(num_obj);
	if (!lux)
	{
		free_object(obj, num_obj);
		free_pix(pix, WND_WIDTH, WND_HEIGHT, num_obj);
		free(cam);
		return (NULL);
	}
	assign_camera_obj_light_to_pix(pix, cam, obj, lux);
	assign_hits_to_pix(pix, hits, num_obj);
	if (!init_scene_structures(pix))
	{
		free_pix(pix, WND_WIDTH, WND_HEIGHT, num_obj);
		return (NULL);
	}
	init_ima(pix);
	return (pix);
}
