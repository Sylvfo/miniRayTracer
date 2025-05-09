/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:50:48 by syl               #+#    #+#             */
/*   Updated: 2025/03/14 23:22:26 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void test_camera(t_pix ***pix)
{
	(void) pix;
	t_coord *p_from = create_point(1, 3, 2);
	t_coord *p_to = create_point(4, -2, 8);
	t_coord *v_up = create_vector(1, 1, 0);
	float *m_orientation;

	t_coord *p_from = create_point(0, 0, 8);
	t_coord *p_to = create_point(0, 0, 0);
	t_coord *v_up = create_vector(0, 1, 0);
	float *m_orientation;

	m_orientation = view_camera(p_from, p_to, v_up);
	print_matrix(m_orientation);
}

void test_camera2(t_pix ***pix)
{
	constructing_camera(pix);
	
//	pixel_size(pix);
}*/
/*
void test_camera3(void)
{
	t_pix *pix;

	pix = malloc(sizeof(t_pix));

	pix->cam = malloc(sizeof(t_camera));
	constructing_camera(pix);
	pix->cam->canva_height = 201;
	pix->cam->canva_width = 101;
	pix->cam->fov = 3.1415 /2;
	pix->cam->m_transf = create_indentity_matrix_44();
	init_viewport_x_y(pix, 100, 50);
	printf("aaaa\n");
	init_camera_pix_ray(pix, pix->cam);

	printf("pix origin ");
	print_point(pix->r_original->p_origin);
	printf("pix direction ");
	print_point(pix->r_original->v_dir);	
//	pixel_size(pix);
}*/