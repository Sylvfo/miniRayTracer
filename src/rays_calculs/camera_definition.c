/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_definition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:48:26 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 12:15:47 by syl              ###   ########.fr       */
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
//	pix[0][0]->cam->m_transf = create_indentity_matrix_44();
	//fonction pour creer la matrice de transformatoin
	pix[0][0]->cam->m_transf = view_camera(pix[0][0]->cam->p_coord, pix[0][0]->cam->v_axe);
//	print_matrix(pix[0][0]->cam->m_transf);
	//fonction pour calculer la taille des pixels
	pixel_size(pix);
//	printf("pixel : %.2f \n", pix[0][0]->cam->pixel_size);
}

//Verifie ensemble gooood
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
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);
	//		ray_for_pixel(pix);
			y++;
		}
		x++;
	}
}

//TROUVER PROBLEME ET METTRE AILLEURS
void init_viewport_x_y(t_pix *pix, int x, int y) //a changer après
{

//	pix->vpy = - (pix->cam->half_height - (y + 0.5) * pix->cam->pixel_size);
//	pix->vpy = (pix->cam->half_height - (y + 0.5) * pix->cam->pixel_size);	
	pix->vpx = pix->cam->half_width - ((x + 0.5) * pix->cam->pixel_size);
	pix->vpy = pix->cam->half_height - ((y + 0.5) * pix->cam->pixel_size);
//	printf("Pixel (%d, %d) -> vpx: %f, vpy: %f\n", x, y, pix->vpx, pix->vpy);
}

//ray_for_pixel(pix); plus joli nom
void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	t_coord *pixl;
	float *m_inverse;
	t_coord *v_direction;
	t_coord *vn_direction;
	t_coord *p_origin;
	t_coord	*p_point;
	
	p_point = create_point(pix->vpx, pix->vpy, -1);//toujours 1 ???
	m_inverse = inverted_matrix_44(pix->cam->m_transf);// !!!!!!!
	if (!m_inverse)
	{
		printf("aieaieaie\n");
		return;
	}
	pixl = matrix_multiplication_44_coord(m_inverse, p_point);
	p_origin = matrix_multiplication_44_coord(m_inverse, pix->p_origin_zero);
	v_direction = substraction(pixl, p_origin);
	vn_direction = normalize_vector(v_direction);
//	pix->r_ray = malloc(sizeof(t_ray));
	pix->r_original = create_ray(p_origin, vn_direction);
}
