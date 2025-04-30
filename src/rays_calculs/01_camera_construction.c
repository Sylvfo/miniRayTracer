/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_camera_construction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:52 by syl               #+#    #+#             */
/*   Updated: 2025/04/30 15:37:33 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	constructing_camera(t_pix ***pix)
{
	//calcul de la matix de transformation
	view_camera(pix[0][0]->cam);

	//calcul cam_m inverse
	inverse4x4(pix[0][0]->cam->m_transf, pix[0][0]->cam->m_inverse);
	
	printf("\n pix[0][0]->cam->m_inverse :");
	print_matrix(pix[0][0]->cam->m_inverse);
	
	//calcul de la taille des pixels
	pixel_size(pix[0][0]);

}


// creer la matrice de transformation de la camera pour pouvoir la bouger
void	view_camera(t_camera *cam)
{
	copy_coord(cam->v_forward, cam->v_axe);

	if (cam->v_axe->x == 0 && fabs(cam->v_axe->y) == 1 &&  cam->v_axe->z == 0)
		vector_fill(cam->v_up, 1, 0, 0);

//	negat_NA(cam->v_forward, cam->v_axe);
	cross_product_NA(cam->v_left, cam->v_up, cam->v_forward);
	//cross_product_NA(cam->v_left, cam->v_forward, cam->v_up);
	cross_product_NA(cam->v_true_up, cam->v_forward, cam->v_left);
	normalize_vector_NA(cam->v_true_up);
	normalize_vector_NA(cam->v_left);

	printf("\n IN CAMERA VIEWa :");
	printf("\n coord camera :");
	print_point(cam->p_coord);

	printf("\n cam->v_left :");
	print_vector(cam->v_left);

	printf("\n cam->v_forward :");
	print_vector(cam->v_forward);

	printf("\n cam->v_up :");
	print_vector(cam->v_up);

	printf("\n cam->v_true_up :");
	print_vector(cam->v_true_up);

	matrix_fill(cam->m_orient, 0, 0, cam->v_left->x);
	matrix_fill(cam->m_orient, 0, 1, cam->v_left->y);
	matrix_fill(cam->m_orient, 0, 2, cam->v_left->z);
	matrix_fill(cam->m_orient, 0, 3, 0);

	matrix_fill(cam->m_orient, 1, 0, cam->v_true_up->x);
	matrix_fill(cam->m_orient, 1, 1, cam->v_true_up->y);
	matrix_fill(cam->m_orient, 1, 2, cam->v_true_up->z);
	matrix_fill(cam->m_orient, 1, 3, 0);

	matrix_fill(cam->m_orient, 2, 0, -1 * cam->v_forward->x);
	matrix_fill(cam->m_orient, 2, 1, -1 * cam->v_forward->y);
	matrix_fill(cam->m_orient, 2, 2, -1 * cam->v_forward->z);
	matrix_fill(cam->m_orient, 2, 3, 0);

	matrix_fill(cam->m_orient, 3, 0, 0);
	matrix_fill(cam->m_orient, 3, 1, 0);
	matrix_fill(cam->m_orient, 3, 2, 0);
	matrix_fill(cam->m_orient, 3, 3, 1);

//	print_matrix(cam->m_orient);
	printf("\n cam->m_orient \n:");
	print_matrix(cam->m_orient);

/* 	float *m_scale = create_indentity_matrix_44();
	create_scaling_matrix_NA(m_scale, -1, 1, -1);
	 matrix_mult_2(cam->m_orient, m_scale);*/

	fill_translation_matrix(cam->m_transl, -1 * cam->p_coord->x,
		-1 * cam->p_coord->y, -1 * cam->p_coord->z);
	matrix_mult_3(cam->m_transf, cam->m_orient, cam->m_transl);
/*	if (!cam->m_transl)
	{
		printf("pas trans cam\n");
		exit (0);
	}
	if (!cam->m_orient)
	{
		printf("pas cam->m_orient\n");
		exit (0);
	}
	if (!cam->m_transf)
	{
		printf("pas cam->m_transf\n");
		exit (0);
	}
	printf("\n cam transl \n:");
	print_matrix(cam->m_transl);
	
	if (!cam->m_transf)
	{
		printf("pas cam->m_transf 2\n");
		exit (0);
	}
	printf("\n cam transf \n:");
	print_matrix(cam->m_transf);*/
}


// I think ok =)
void	pixel_size(t_pix *pix)
{
	float	half_view;
	float	half_height;
	float	aspect;

	half_view = tan(pix->cam->fov/2);

	printf("half view %.2f \n", half_view);
	printf("pix->cam->canva_height %.2f \n", pix->cam->canva_height);
	printf("pix->cam->canva_width %.2f \n", pix->cam->canva_width);
	aspect = pix->cam->canva_width / pix->cam->canva_height;
	printf("aspect %.2f \n", aspect);
	if (aspect >= 1)
	{
		pix->cam->half_width = half_view;
		pix->cam->half_height = half_view / aspect;
	}
	else
	{
		pix->cam->half_width = half_view * aspect;
		pix->cam->half_height = half_view;
	}
	pix->cam->pixel_size = (pix->cam->half_width * 2) / pix->cam->canva_width;
	printf("\n\n pixel size %.5f fov %.2f \n\n", pix->cam->pixel_size, pix->cam->fov);
}



/*

CAMERA FONCTIONNE
// creer la matrice de transformation de la camera pour pouvoir la bouger
void	view_camera(t_camera *cam)
{
	
	copy_coord(cam->v_forward, cam->v_axe);

	if (cam->v_axe->x == 0 && fabs(cam->v_axe->y) == 1 &&  cam->v_axe->z == 0)
		vector_fill(cam->v_up, 1, 0, 0);
//	if (fabs(cam->v_axe->x) < 1e-6 && fabs(cam->v_axe->z) < 1e-6) 
//	{
//		printf("other axe in camera \n");
//		vector_fill(cam->v_forward, 0, 0, 1);// Si la caméra regarde pile en haut/bas, chan	
//	}

//	negat_NA(cam->v_forward, cam->v_axe);
	cross_product_NA(cam->v_left, cam->v_forward, cam->v_up);
	cam->v_true_up = cross_product(cam->v_forward, cam->v_left);
	normalize_vector_NA(cam->v_true_up);
	normalize_vector_NA(cam->v_left);

	printf("\n IN CAMERA VIEWa :");
	printf("\n coord camera :");
	print_point(cam->p_coord);

	printf("\n cam->v_left :");
	print_vector(cam->v_left);

	printf("\n cam->v_forward :");
	print_vector(cam->v_forward);

	printf("\n cam->v_up :");
	print_vector(cam->v_up);

	printf("\n cam->v_true_up :");
	print_vector(cam->v_true_up);


	matrix_fill(cam->m_orient, 0, 0, cam->v_left->x);
	matrix_fill(cam->m_orient, 0, 1, cam->v_left->y);
	matrix_fill(cam->m_orient, 0, 2, cam->v_left->z);
	matrix_fill(cam->m_orient, 0, 3, 0);

	matrix_fill(cam->m_orient, 1, 0, cam->v_true_up->x);
	matrix_fill(cam->m_orient, 1, 1, cam->v_true_up->y);
	matrix_fill(cam->m_orient, 1, 2, cam->v_true_up->z);
	matrix_fill(cam->m_orient, 1, 3, 0);

	matrix_fill(cam->m_orient, 2, 0, -1 * cam->v_forward->x);
	matrix_fill(cam->m_orient, 2, 1, -1 * cam->v_forward->y);
	matrix_fill(cam->m_orient, 2, 2, -1 * cam->v_forward->z);
	matrix_fill(cam->m_orient, 2, 3, 0);

	matrix_fill(cam->m_orient, 3, 0, 0);
	matrix_fill(cam->m_orient, 3, 1, 0);
	matrix_fill(cam->m_orient, 3, 2, 0);
	matrix_fill(cam->m_orient, 3, 3, 1);

//	print_matrix(cam->m_orient);
	printf("\n cam->m_orient \n:");
	print_matrix(cam->m_orient);

 //	float *m_scale = create_indentity_matrix_44();
//	create_scaling_matrix_NA(m_scale, -1, 1, -1);
//	 matrix_mult_2(cam->m_orient, m_scale);

	fill_translation_matrix(cam->m_transl, -1 * cam->p_coord->x,
		-1 * cam->p_coord->y, -1 * cam->p_coord->z);
	if (!cam->m_transl)
	{
		printf("pas trans cam\n");
		exit (0);
	}
	if (!cam->m_orient)
	{
		printf("pas cam->m_orient\n");
		exit (0);
	}
	if (!cam->m_transf)
	{
		printf("pas cam->m_transf\n");
		exit (0);
	}
	printf("\n cam transl \n:");
	print_matrix(cam->m_transl);
	matrix_mult_3(cam->m_transf, cam->m_orient, cam->m_transl);
	if (!cam->m_transf)
	{
		printf("pas cam->m_transf 2\n");
		exit (0);
	}
	printf("\n cam transf \n:");
	print_matrix(cam->m_transf);
}

*/