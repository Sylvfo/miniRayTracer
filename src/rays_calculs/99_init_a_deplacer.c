/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_init_a_deplacer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:35:09 by sforster          #+#    #+#             */
/*   Updated: 2025/05/07 10:12:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//difficiles
//translation matrix
//inverted matrix
//matrix_multiplication_44_coord
//matrix_multiplication_44_NA...
//create_translation_matrix


bool init_a_deplacer(t_pix ***pix)
{
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	pix[0][0]->obj[0][0]->color->r = int_to_float(pix[0][0]->obj[0][0]->color->r);
	pix[0][0]->obj[0][0]->color->g = int_to_float(pix[0][0]->obj[0][0]->color->g);
	pix[0][0]->obj[0][0]->color->b = int_to_float(pix[0][0]->obj[0][0]->color->b);

	// camera
	pix[0][0]->cam->v_left = create_vector(0, 0, 0);//or init?
	pix[0][0]->cam->v_up = create_vector(0, 1, 0);
	pix[0][0]->cam->v_true_up = create_vector(0, 0, 0);
	pix[0][0]->cam->m_orient = create_indentity_matrix_44();
	pix[0][0]->cam->m_transl = create_indentity_matrix_44();
	pix[0][0]->cam->m_transf = create_indentity_matrix_44();
	pix[0][0]->cam->m_inverse = create_indentity_matrix_44();
//	pix[0][0]->cam->p_cam_world = create_point(0, 0, 0);
	pix[0][0]->cam->p_zero = create_point(0,0,0);
	pix[0][0]->cam->view_height = WND_HEIGHT;//image size
	pix[0][0]->cam->view_width = WND_WIDTH;//image size
	pix[0][0]->cam->canva_height = WND_HEIGHT;//200;//viewport size
	pix[0][0]->cam->canva_width = WND_WIDTH;//200;//viewport
	pix[0][0]->cam->fov *= 0.0174533;

	int	x;
	int	y;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->p_viewport = create_point(0,0,-1); //-1 IMPORTANT
			pix[x][y]->p_viewport_world = create_point(0,0,0);
			pix[x][y]->r_dir = malloc(sizeof(t_coord));
			pix[x][y]->r_origin = malloc(sizeof(t_coord));
			y++;
		}
		x++;
	}
	if (init_matrix_obj(pix[0][0]->obj) == false)
	{
		printf("probleme alloc obj \n");
	}
	if (init_matrix_hits(pix[0][0]->hits) == false)
	{
		printf("probleme alloc obj \n");
		return (false);
	}
	init_comps(pix);
	
//	init_lights(pix[0][0]->lux);
	return true;
}

bool 	init_matrix_obj(t_obj ***obj)
{
	int a;
	int b;

	obj[0][0]->m_transf = create_indentity_matrix_44();
	a = 1;
	while(obj[a] != NULL)// on pourra changer après pour les autres objets...
	{
		b = 0;
		while(obj[a][b] != NULL)
		{
			obj[a][b]->m_transl = create_indentity_matrix_44();
			obj[a][b]->m_transf = create_indentity_matrix_44();
			obj[a][b]->m_inv = create_matrix(4, 4);
			if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
				obj[a][b]->m_scale = create_indentity_matrix_44();
			if (obj[a][b]->obj_type == PLAN || obj[a][b]->obj_type == CYLINDER)
			{
				obj[a][b]->m_rot = create_indentity_matrix_44();
				obj[a][b]->from = create_vector(0, 1, 0);// in rotation from vector
				obj[a][b]->v_axe_r = create_vector(0, 0, 0);//in rotation rodriguez
			}
			obj[a][b]->v_sph_camera = create_vector(0, 0, 0);
			if (obj[a][b]->obj_type == SPHERE || obj[a][b]->obj_type == CYLINDER)
			{
				obj[a][b]->radius = obj[a][b]->diam / 4.0f; 
				obj[a][b]->diam = obj[a][b]->diam / 2.0f;
			}
			if (a == 3) // a retirer pc erreur pars
				obj[a][b]->p_coord->z = 0; // a retirer pc erreur pars
			obj[a][b]->closed_up = true;
			obj[a][b]->closed_down = true;
				b++;
		}
		a++;
	}
	return true;
}

bool 	init_matrix_hits(t_hits ***hits)
{
	int a;
	int b;

	a = 0;
	while(hits[a] != NULL)// on pourra changer après pour les autres objets...
	{
		b = 0;
		while(hits[a][b] != NULL)
		{
			//mneme
			hits[a][b]->r_origin = create_point(0,0,0);
			hits[a][b]->r_dir = create_vector(0,0,0);
			b++;
		}
		a++;
	}
	return true;
}


bool init_comps(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->comps->closestt = INT_MAX;
			pix[x][y]->comps->t_count = 0;
			pix[x][y]->comps->obj = pix[x][y]->obj[0][0];
			pix[x][y]->comps->obj_type = NONE;
			copy_color(pix[x][y]->comps->obj_color, pix[x][y]->obj[0][0]->color);
			pix[x][y]->comps->r_dir = malloc(sizeof(t_coord));
			pix[x][y]->comps->r_origin = malloc(sizeof(t_coord));
			copy_coord(pix[x][y]->comps->r_dir, pix[x][y]->r_dir);
			copy_coord(pix[x][y]->comps->r_origin, pix[x][y]->r_origin);
			pix[x][y]->comps->p_touch = malloc(sizeof(t_coord));
			pix[x][y]->comps->v_eye = malloc(sizeof(t_coord));
			pix[x][y]->comps->v_norm_parral = malloc(sizeof(t_coord));
			pix[x][y]->comps->v_light_to_point = create_vector(0, 0, 0);
			pix[x][y]->comps->v_sphere_to_point = create_vector(0, 0, 0);
			pix[x][y]->comps->reflect_dir = create_vector(0, 0, 0);
			pix[x][y]->comps->scalar = create_vector(0, 0, 0);
			pix[x][y]->comps->view_dir = create_vector(0, 0, 0);
//			pix[x][y]->comps->p_world = create_point(0, 0, 0);
			pix[x][y]->comps->p_space = create_point(0, 0, 0);
			pix[x][y]->comps->origin_zero = create_point(0, 0, 0);
			pix[x][y]->comps->object_normal = create_vector(0, 0, 0);
			pix[x][y]->comps->transp_inv = create_matrix(4, 4);
			pix[x][y]->comps->obj_inv = create_matrix(4, 4);
			pix[x][y]->comps->v_point_to_light = create_point(0, 0, 0);
			y++;
		}
		x++;
	}
}

bool init_lights(t_light ***lights)
{
	int a;
	int b;

	a = 0;
	while(lights[a] != NULL)// on pourra changer après pour les autres objets...
	{
		b = 0;
		while(lights[a][b] != NULL)
		{
		//	lights[a][b]->m_transf = create_indentity_matrix_44();
		//	lights[a][b]->p_world = create_point(0,0,0);
			b++;
		}
		a++;
	}
	return true;
}

/*
void	blabla(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			color_float_to_int(pix[x][y]->color);
			y++;
		}
		x++;
	}
}*/