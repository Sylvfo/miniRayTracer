/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_definition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:48:26 by syl               #+#    #+#             */
/*   Updated: 2025/04/07 17:26:18 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void constructing_camera(t_pix ***pix)
{
	// a deplacer dans init
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	pix[0][0]->obj[0][0]->color->r = int_to_float(pix[0][0]->obj[0][0]->color->r);
	pix[0][0]->obj[0][0]->color->g = int_to_float(pix[0][0]->obj[0][0]->color->g);
	pix[0][0]->obj[0][0]->color->b = int_to_float(pix[0][0]->obj[0][0]->color->b);
	pix[0][0]->cam->canva_height = WND_HEIGHT;
	pix[0][0]->cam->canva_width = WND_WIDTH;
	pix[0][0]->cam->fov *= 3.1415 / 180;
	pix[0][0]->cam->m_transf = view_camera(pix[0][0]->cam->p_coord, pix[0][0]->cam->v_axe);
	pixel_size(pix);
}

void pixel_size(t_pix ***pix)
{
	float half_view;
	float aspect;

	half_view = tan(pix[0][0]->cam->fov / 2);
	aspect = pix[0][0]->cam->canva_height / pix[0][0]->cam->canva_width;
	if (aspect >= 1)
	{
		pix[0][0]->cam->half_width = half_view;
		pix[0][0]->cam->half_height = half_view / aspect;
	}
	if (aspect < 1)
	{
		pix[0][0]->cam->half_height = half_view;
		pix[0][0]->cam->half_width = half_view * aspect;		
	}
	printf("half_view: %f\n", half_view);
	printf("fov: %f\n", pix[0][0]->cam->fov);
	pix[0][0]->cam->pixel_size = (pix[0][0]->cam->half_width * 2) / pix[0][0]->cam->canva_height;
}

void init_viewport2(t_pix ***pix)
{
	int	x;
	int	y;
	// a deplacer dans init apres
	pix[0][0]->cam->view_height = 1200;// 1000;
	pix[0][0]->cam->view_width = 1200;// 1000;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->p_origin_zero = create_point(0, 0, 0);
			init_viewport_x_y(pix[x][y], x, y); //ok
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);//initialise les rays. 
			y++;
		}
		x++;
	}
}

//TROUVER PROBLEME ET METTRE AILLEURS
void init_viewport_x_y(t_pix *pix, int x, int y)
{
	pix->vpx = pix->cam->half_width - ((x + 0.5) * pix->cam->pixel_size);
	pix->vpy = pix->cam->half_height - ((y + 0.5) * pix->cam->pixel_size);
}

//ray_for_pixel(pix); plus joli nom
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	t_coord	*p_viewport; //point sur le viewport. 
	t_coord *v_direction; // vecteur direction
	t_coord *p_viewport_world;
	float *m_inverse;
	t_coord *p_camera_world;
	
	//point sur le viewport. 
	p_viewport = create_point(pix->vpx, pix->vpy, -1.0);
	// Obtenir la matrice inverse pour le changement de repère
	m_inverse = inverted_matrix_44(pix->cam->m_transf);
	if (!m_inverse)
	{
		printf("aieaieaie\n");
		return;
	}
    // Origine de la caméra dans le repère monde
	p_camera_world = matrix_multiplication_44_coord(m_inverse, pix->p_origin_zero);
	 // Point final(viewport??) transformé dans le repère monde
	p_viewport_world = matrix_multiplication_44_coord(m_inverse, p_viewport);
	//creation du ray entre la camera et le viewport modifiés selon la caméra
	v_direction = substraction(p_viewport_world, p_camera_world);
	v_direction = normalize_vector(v_direction);
	
	printf("Camera origin: (%f, %f, %f)\n", p_camera_world->x, p_camera_world->y, p_camera_world->z);
	printf("Ray direction: (%f, %f, %f)\n", v_direction->x, v_direction->y, v_direction->z);
	pix->r_original = create_ray(p_camera_world, v_direction);
}


/*avant correction
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	t_coord *pixl;
	float *m_inverse;
	t_coord *v_direction;
	t_coord *vn_direction;
	t_coord *p_camera_world;
	t_coord	*p_point;
	
	p_point = create_point(pix->vpx, pix->vpy, -1.0);
	m_inverse = inverted_matrix_44(pix->cam->m_transf);// !!!!!!!
	if (!m_inverse)
	{
		printf("aieaieaie\n");
		return;
	}
	pixl = matrix_multiplication_44_coord(m_inverse, p_point);
	p_camera_world = matrix_multiplication_44_coord(m_inverse, pix->p_origin_zero);
	v_direction = substraction(pixl, p_camera_world);
	vn_direction = normalize_vector(v_direction);
	printf("Camera origin: (%f, %f, %f)\n", p_camera_world->x, p_camera_world->y, p_camera_world->z);
	printf("Ray direction: (%f, %f, %f)\n", vn_direction->x, vn_direction->y, vn_direction->z);
	pix->r_original = create_ray(p_camera_world, vn_direction);
}
*/