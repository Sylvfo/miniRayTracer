/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/03/12 13:49:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//BASE POUR LES CALCULS
static void	init_viewport(t_pix ***pix);
static void init_camera_pix_ray(t_pix *pix, t_camera *cam);

void raytracing(t_pix ***pix)
{
	init_viewport(pix);//a changer après
	//avant la il y a le problème...
	printf("avant set \n");
	set_transformation(pix[0][0]->obj);
	printf("set ok \n");
	main_sphere(pix);
	//intersect plan
	find_closest_obj(pix);
	// light. 
	return;
}

//TROUVER PROBLEME ET METTRE AILLEURS
static void init_viewport_x_y(t_pix *pix, int x, int y) //a changer après
{
	pix->vpx = pix->ima->half_width - (pix->ima->pixel_size * (x + 0.5));
	pix->vpy = (pix->ima->half_height - (pix->ima->pixel_size * (y + 0.5))) * -1;

// celui ci fonctionne
//	pix->vpx = pix->ima->pixel_size * x - pix->ima->half_width;
//	pix->vpy = (pix->ima->pixel_size * y - pix->ima->half_height) * -1;


//	pix->vpx = pix->ima->pixel_size * x - pix->ima->half_height;
//	pix->vpy = pix->ima->pixel_size * y - pix->ima->half_width;

//	pix->vpx = x - pix->ima->half_height;
//	pix->vpy = y - pix->ima->half_width;
}

static void	init_viewport(t_pix ***pix)
{
	int	x;
	int	y;
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	pix[0][0]->ima->view_height = 100;
	pix[0][0]->ima->view_width = 100;
	pix[0][0]->ima->canva_width = WND_WIDTH;
	pix[0][0]->ima->canva_height = WND_HEIGHT;

	//unit
	pix[0][0]->ima->pixel_size = pix[0][0]->ima->view_width / pix[0][0]->ima->canva_width;

	pix[0][0]->ima->half_height = pix[0][0]->ima->canva_height / 2;
	pix[0][0]->ima->half_width = pix[0][0]->ima->canva_width / 2 ;
//	pix[0][0]->ima->half_height = pix[0][0]->ima->view_height / 2;
//	pix[0][0]->ima->half_width = pix[0][0]->ima->view_width / 2 ;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			init_viewport_x_y(pix[x][y], x, y);
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);
			pix[x][y]->p_origin = create_point(0, 0, 0);
			y++;
		}
		x++;
	}	
}

static void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	t_coord *v_cam_pix;
	t_coord *vn_cam_pix;
	t_coord *p_point;

	//p_point = create_point(pix->vpx, pix->vpy, DIST_VIEWP_ORIGIN);
	p_point = create_point(pix->vpx, pix->vpy, 200);//dist viewp orign donné par angle camera?? ou toujours -1???
	v_cam_pix = substraction(p_point, cam->p_coord);
//	vn_cam_pix = normalize_vector(v_cam_pix); //normer?
//	pix->r_ray = create_ray(pix->cam->p_coord, vn_cam_pix);// normer??
	pix->r_ray = create_ray(pix->cam->p_coord, v_cam_pix); //ray par origin...
	pix->r_original = create_ray(pix->cam->p_coord, v_cam_pix);
//	pix->r_ray = malloc(sizeof(t_ray));
}

//////////////////
