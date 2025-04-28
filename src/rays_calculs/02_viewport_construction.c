/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_viewport_construction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:57:11 by syl               #+#    #+#             */
/*   Updated: 2025/04/28 14:40:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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


//calcul les coordonnées xy sur le viewport de chaque pixel
void init_viewport_x_y(t_pix *pix, int x, int y)
{
	pix->p_viewport->x = pix->cam->half_width - ((x + 0.5) * pix->cam->pixel_size);
	pix->p_viewport->y =  pix->cam->half_height - ((y + 0.5) * pix->cam->pixel_size);
	////z?????
}

