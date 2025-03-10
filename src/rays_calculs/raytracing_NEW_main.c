/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_NEW_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 08:39:05 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//BASE POUR LES CALCULS
static void	init_viewport(t_pix ***pix);
/*
void raytracing(t_pix ***pix)
{
	// suite initialization...
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
//	init_viewport(pix);//a changer après
//	canva_to_viewport(pix);
//	init_camera_pix_ray(pix);

	intersect_sphere(t_pix ***pix);
	
	//cx et cy. origines pas zero zero

	// canvas + ray center

	//intersect ray sphere

	//intersect plan sphere+

	// light. 
	


	return;
}
/*
void	canva_to_viewport(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->vpx = x - (pix[0][0]->ima->canva_height / 2);
			pix[x][y]->vpy = y - (pix[0][0]->ima->canva_width / 2);
			y++;
		}
		x++;
	}
}

static void	init_viewport(t_pix ***pix)//a changer après
{
	pix[0][0]->ima->canva_height = 1800;
	pix[0][0]->ima->canva_width = 1000;
}



static void init_camera_pix_ray(t_pix ***pix)
{
	int	x;
	int	y;
	t_coord v_cam_pix;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->v_d = create_ray(pix[0][0]->cam->p_coord, t_coord *v_direction)

			pix[x][y]->vpx = x - (pix[0][0]->ima->canva_height / 2);
			pix[x][y]->vpy = y - (pix[0][0]->ima->canva_width / 2);
			pix[x][y]->
			t_coord	*normalize_vector(t_coord *v_1);
			y++;
		}
		x++;
	}
}

t_coord	*create_vector(float x, float y, float z)
{
	t_coord	*v_vector;

	v_vector = malloc(sizeof(t_coord));
	if (!v_vector)
	{
		perror("Error allocating vector\n");
		return (NULL);
	}
	v_vector->x = x;
	v_vector->y = y;
	v_vector->z = z;
	v_vector->t = 0;
	return (v_vector);
}*/