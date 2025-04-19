/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_construction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:11 by syl               #+#    #+#             */
/*   Updated: 2025/04/19 16:13:36 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void init_viewport(t_pix ***pix)
{
	int	x;
	int	y;
	// a deplacer dans init apres
	pix[0][0]->cam->view_height = 200;// 1000;
	pix[0][0]->cam->view_width = 200;// 1000;
	pix[0][0]->cam->p_origin_zero = create_point(0, 0, 0);
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

// svp laisse les commentaires ici
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
//	p_camera_world = matrix_multiplication_44_point(pix->cam->m_inverse, pix->cam->p_coord);
	p_camera_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->cam->p_origin_zero);
//	p_camera_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->cam->p_coord);
	if (is_point(p_camera_world) == false)
		printf("false in p cam world \n");
	// Point final(viewport??) transformé dans le repère monde
	p_viewport_world = matrix_multiplication_44_coord(pix->cam->m_inverse, pix->p_viewport);
	if (is_point(p_viewport_world) == false)
		printf("false in p cam p_viewport_world \n");
//	p_viewport_world = matrix_multiplication_44_point(pix->cam->m_inverse, pix->p_viewport);
	//creation du ray entre la camera et le viewport modifiés selon la caméra
	v_direction = substraction(p_viewport_world, p_camera_world);
	v_direction = normalize_vector(v_direction);

	pix->r_dir = malloc(sizeof(t_coord));
	pix->r_origin = malloc(sizeof(t_coord));
	copy_coord(pix->r_origin, p_camera_world);
	copy_coord(pix->r_dir, v_direction);
	free(p_camera_world);
	free(v_direction);
	free(p_viewport_world);
}


//calcul les coordonnées xy sur le viewport de chaque pixel
void init_viewport_x_y(t_pix *pix, int x, int y)
{
	pix->vpx = pix->cam->half_width - ((x + 0.5) * pix->cam->pixel_size);
	pix->vpy = pix->cam->half_height - ((y + 0.5) * pix->cam->pixel_size);
}

/* fonction gpt
void init_viewport_x_y(t_pix *pix, int x, int y)
{
	pix->vpx = ((x + 0.5) * pix->cam->pixel_size) - pix->cam->half_width;
	pix->vpy = pix->cam->half_height - ((y + 0.5) * pix->cam->pixel_size);
}*/