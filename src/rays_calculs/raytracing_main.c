/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/03/14 10:57:41 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//BASE POUR LES CALCULS
static void	init_viewport(t_pix ***pix);
static void init_camera_pix_ray(t_pix *pix, t_camera *cam);

void raytracing(t_pix ***pix)
{
	//à déplacer ensuite dans init_data
	// pas sûre que tout est juste niveau unit, vecteurs normés ou pas...
	init_viewport(pix);
	// calculs matriciels pour déplacer et scale les objets. 
	set_transformation(pix[0][0]->obj);
	main_sphere(pix);
	//intersect plan
	// intersect Cylindre
	find_closest_obj(pix);
	// pas oublier de mettre les couleurs de 0 à 1.
//	main_light(pix); ICI =)
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
	pix[0][0]->ima->view_height = 1000;
	pix[0][0]->ima->view_width = 1000;
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
			pix[x][y]->p_origin_zero = create_point(0, 0, 0);
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

	pix->r_ray = malloc(sizeof(t_ray));

	float dist_viewplane = (pix->ima->view_height / 2) / tan(cam->fov / 2);//trouvé sur gpt à revoir...
	p_point = create_point(pix->vpx, pix->vpy, -dist_viewplane);//dist viewp orign donné par angle camera?? ou toujours -1???
	v_cam_pix = substraction(p_point, cam->p_coord);
	vn_cam_pix = normalize_vector(v_cam_pix);
	pix->r_original = create_ray(pix->cam->p_coord, vn_cam_pix);
}