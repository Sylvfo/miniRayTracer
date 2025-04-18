/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+        */
/*   Created: 2025/03/07 11:21:16 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/07 14:12:39 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_pix(t_pix ***pix, int rows, int cols)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		if (pix[x])
		{
			y = 0;
			while (y < cols)
			{
				free(pix[x][y]);
				y++;
			}
			free(pix[x]);
		}
		x++;
	}
	free(pix);
}

static t_pix	**init_pix_col(int cols)
{
	t_pix	**col;
	int		y;

	y = 0;
	col = malloc(cols * sizeof(t_pix *));
	if (!col)
		return (NULL);
	while (y < cols)
	{
		col[y] = malloc(sizeof(t_pix));
		if (!col[y])
		{
			while (y > 0)
				free(col[--y]);
			free(col);
			return (NULL);
		}
		y++;
	}
	return (col);
}

t_pix	***init_pix(int rows, int cols)
{
	t_pix	***pix;
	int		x;

	x = 0;
	pix = malloc(rows * sizeof(t_pix **));
	if (!pix)
		return (NULL);
	while (x < rows)
	{
		pix[x] = init_pix_col(cols);
		if (!pix[x])
		{
			free_pix(pix, x, cols);
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

static void	assign_camera_obj_light_to_pix(t_pix ***pix, t_camera *cam,
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

	pix = init_pix(WND_WIDTH, WND_HEIGHT);
	if (!pix)
		return (NULL);
	obj = init_object(num_obj);
	if (!obj)
	{
		free_pix(pix, WND_WIDTH, WND_HEIGHT);
		return (NULL);
	}
	cam = init_camera();
	if (!cam)
	{
		free_pix(pix, WND_WIDTH, WND_HEIGHT);
		free_object(obj, num_obj);
		return (NULL);
	}
	lux = init_light(num_obj);
	if (!*lux)
	{
		free_pix(pix, WND_WIDTH, WND_HEIGHT);
		free_object(obj, num_obj);
		free(cam);
		return (false);
	}
	assign_camera_obj_light_to_pix(pix, cam, obj, lux);

	assign_hits_to_pix(pix, hits, num_obj);
	init_ima(pix); 
	return (pix);
}
