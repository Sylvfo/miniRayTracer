/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:40:13 by syl               #+#    #+#             */
/*   Updated: 2025/02/28 14:40:05 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_parsing.h"

void	free_all(t_pix ***pix)
{
	int	i;

	if (pix && *pix)
	{
		i = 0;
		while ((*pix)[i] != NULL)
		{
			if ((*pix)[i]->cam)
				free((*pix)[i]->cam);
			if ((*pix)[i]->obj)
				free_obj_memory((*pix)[i]->obj, 4);
			if ((*pix)[i]->lux)
				free_light_memory((*pix)[i]->lux, 2);
			free((*pix)[i]);
			i++;
		}
		free(*pix);
	}
}

void	init_pix(t_pix ***pix, int rows, int cols)
{
	int	i;
	int	j;

	*pix = malloc(rows * sizeof(t_pix *));
	if (!*pix)
		return ;
	i = 0;
	while (i < rows)
	{
		(*pix)[i] = malloc(cols * sizeof(t_pix));
		if (!(*pix)[i])
		{
			j = 0;
			while (j < i)
			{
				free((*pix)[j]);
				j++;
			}
			free(*pix);
			*pix = NULL;
			return ;
		}
		i++;
	}
}

bool	init_row(t_pix *row, t_num_obj *num_obj)
{
	row->cam = init_camera();
	if (!row->cam)
		return (false);
	row->obj = init_obj(num_obj);
	if (!row->obj)
	{
		free(row->cam);
		return (false);
	}
	row->lux = init_light(num_obj);
	if (!row->lux)
	{
		free(row->cam);
		free_obj_memory(row->obj, 4);
		return (false);
	}
	return (true);
}

bool	init_data(t_pix ***pix, t_num_obj *num_obj)
{
	int	i;
	int	j;

	init_pix(pix, WND_HEIGHT, WND_WIDTH);
	if (!*pix)
		return (false);
	i = 0;
	while (i < WND_HEIGHT)
	{
		j = 0;
		while (j < WND_WIDTH)
		{
			if (!init_row(&(*pix)[i][j], num_obj))
			{
				free_all(pix);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

/* bool	init_data(t_pix	***pix)
{
	t_pix	***pix;
	t_image	*ima;

	pix = NULL;
	if (init_pix(pix))
		return (false);
	ima = init_image();

	//init camera 
	// init obj on a besoin de savoir combien
	// ini light on a besoin de savoir combien
	// init matrix memoire + mettre les matrices
	--> erreurs malloc.

	link_pix_ima(pix, ima);
	return (pix);
}

//L1 = 1200 ?? height
//L2 = 1600 ?? canva width
bool	init_pix(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	pix = (t_pix ***)malloc(WND_WIDTH * sizeof(t_pix **));
	if (!pix)
		return (NULL);
	while (x < WND_WIDTH)
	{
		y = 0;
		pix[x] = (t_pix **)malloc(WND_HEIGHT * sizeof(t_pix *));
		if (!pix[x])
			return (NULL);
		while (y < WND_HEIGHT)
		{
			pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
			if (!pix[x][y])
				return (NULL);//free...
//			pix[x][y]->col = create_color(255, 0, 0);
			y++;
		}
		x++;
	}
	return (pix);
}

void	link_pix_ima(t_pix ***pix, t_image *ima)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->ima = ima;
			y++;
		}
		x++;
	}
	return ;
}
 */