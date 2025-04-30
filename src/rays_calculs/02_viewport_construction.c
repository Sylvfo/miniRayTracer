/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_viewport_construction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:11 by syl               #+#    #+#             */
/*   Updated: 2025/04/30 15:43:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void init_viewport(t_pix ***pix)
{
	int	x;
	int	y;
	// a deplacer dans init apres
	pix[0][0]->cam->view_height = 1200;// 1000;
	pix[0][0]->cam->view_width = 1200;// 1000;
	pix[0][0]->cam->p_origin_zero = create_point(0, 0, 0);
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
	
			init_viewport_x_y(pix[x][y], x, y); //ok
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);//initialise les rays. 
		//	if(pix->[x][y]->cx == 0 &&)pix->[x][y]->cy == 0)
				
			y++;
		}
		x++;
	}
}

// svp laisse les commentaires ici
//calcul les rays entre la camera et chaque pixel du viewport
// le ray n est pas encore transformé par les matrices de transformation des objets
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{	
	if (is_point(cam->p_cam_world) == false)
		printf("false in p cam world \n");
	// Point final(viewport??) transformé dans le repère monde
	matrix_point_multiplication_new(pix->p_viewport_world, pix->cam->m_inverse, pix->p_viewport);
//	matrix_multiplication_44_coord_NA(pix->p_viewport_world, pix->cam->m_inverse, pix->p_viewport);
//	pix->p_viewport_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->p_viewport);
	if (is_point(pix->p_viewport_world) == false)
		printf("false in p cam p_viewport_world \n");
	//creation du ray entre la camera et le viewport modifiés selon la caméra
	substraction_p_to_v_NA(pix->r_dir, pix->p_viewport_world, cam->p_cam_world);
//	pix->r_dir = substraction(pix->p_viewport_world, cam->p_cam_world);
	normalize_vector_NA(pix->r_dir);
//	pix->r_dir = normalize_vector(pix->r_dir);
	copy_coord(pix->r_origin, cam->p_cam_world);;
}

//calcul les rays entre la camera et chaque pixel du viewport
// le ray n est pas encore transformé par les matrices de transformation des objets
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
//	t_coord	*p_viewport; //point sur le viewport. 
	t_coord *v_direction; // vecteur direction
	t_coord *p_viewport_world;
//	float *m_inverse;
	t_coord *p_camera_world;
	
	//point sur le viewport. 
	pix->p_viewport = create_point(pix->vpx, pix->vpy, -1.0);
    // Origine de la caméra dans le repère monde
	p_camera_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->cam->p_origin_zero);
	 // Point final(viewport??) transformé dans le repère monde
	p_viewport_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->p_viewport);
	//creation du ray entre la camera et le viewport modifiés selon la caméra
	v_direction = substraction(p_viewport_world, p_camera_world);
	v_direction = normalize_vector(v_direction);
		pix->r_original = create_ray(p_camera_world, v_direction);
		printf("Pixel (%.2f, %.2f): Ray origin = (%.2f, %.2f, %.2f), dir = (%.4f, %.4f, %.4f)\n",
			pix->vpx, pix->vpy,
			pix->r_original->p_origin->x,
			pix->r_original->p_origin->y,
			pix->r_original->p_origin->z,
			pix->r_original->v_dir->x,
			pix->r_original->v_dir->y,
			pix->r_original->v_dir->z);
		
}*/

void init_viewport(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			init_viewport_x_y(pix[x][y], x, y); //ok
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);//initialise les rays. 
			y++;
		}
		x++;
	}
}


//calcul les rays entre la camera et chaque pixel du viewport
// le ray n est pas encore transformé par les matrices de transformation des objets
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{	
//	if (is_point(cam->p_cam_world) == false || is_point(pix->p_viewport) == false)
//		printf("false in p cam world \n");

	//calcul du point origin du rayon 
	//donc point focal camera transformé dans le repère monde
	//en fait la camera est à zero et le viewport à -1
	//celui là le même pour tous les rayons???
	matrix_point_multiplication_new(pix->r_origin, pix->cam->m_inverse, pix->cam->p_origin_zero);


	//calcul de la position du pixel du viewport dans le world
	matrix_point_multiplication_new(pix->p_viewport_world, pix->cam->m_inverse, pix->p_viewport);

	//calcul du vecteur de direction du rayon entre la camera et le pixel viewport world
	//
	substraction_p_to_v_NA(pix->r_dir, pix->p_viewport_world, pix->r_origin);
	normalize_vector_NA(pix->r_dir);
}


// ca c est juste
void init_viewport_x_y(t_pix *pix, int x, int y)
{
	pix->p_viewport->x = pix->cam->half_width - ((x + 0.5) * pix->cam->pixel_size);
	pix->p_viewport->y =  pix->cam->half_height - ((y + 0.5) * pix->cam->pixel_size);
}

/*
//calcul les rays entre la camera et chaque pixel du viewport
// le ray n est pas encore transformé par les matrices de transformation des objets
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{	
	if (is_point(cam->p_cam_world) == false || is_point(pix->p_viewport) == false)
		printf("false in p cam world \n");

	//cre

	// Point final(viewport??) transformé dans le repère monde
	matrix_point_multiplication_new(pix->p_viewport_world, pix->cam->m_transf, pix->p_viewport);


//	matrix_multiplication_44_coord_NA(pix->p_viewport_world, pix->cam->m_inverse, pix->p_viewport);
//	pix->p_viewport_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->p_viewport);
	if (is_point(pix->p_viewport_world) == false)
		printf("false in p cam p_viewport_world \n");
	//creation du ray entre la camera et le viewport modifiés selon la caméra
	substraction_p_to_v_NA(pix->r_dir, pix->p_viewport_world, cam->p_cam_world);
	normalize_vector_NA(pix->r_dir);


	copy_coord(pix->r_origin, cam->p_cam_world);
}
*/