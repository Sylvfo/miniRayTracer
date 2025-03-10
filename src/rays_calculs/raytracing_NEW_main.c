/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_NEW_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 18:01:28 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//BASE POUR LES CALCULS
static void	init_viewport(t_pix ***pix);
static void init_camera_pix_ray(t_pix *pix, t_camera *cam);
static void closest_obj(t_pix *pix);
void find_closest_obj(t_pix ***pix);

void raytracing(t_pix ***pix)
{
	// suite initialization...
	color_int_to_rgb(BAKGROUND_COLOR, pix[0][0]->obj[0][0]->color);
	init_viewport(pix);//a changer après
	main_sphere(pix);
	pix[0][0]->obj[0][0]->color->r = 120;
	//intersect plan
	find_closest_obj(pix);
	// canvas + ray center

	// light. 
	return;
}

void find_closest_obj(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			closest_obj(pix[x][y]);
			pix[x][y]->color = pix[x][y]->closest_obj->color;
			y++;
		}
		x++;
	}	
}

static void closest_obj(t_pix *pix)
{
	float closestt = 4874654564;
	
	pix->closest_obj = pix->obj[0][0];

	if (pix->t1 < closestt && pix->t1 > 0)/// ou plus grand que zero...
	{
		closestt = pix->t1;
		pix->closest_obj = pix->obj[1][0];
	}
	if (pix->t2 < closestt &&  pix->t2 > 0)/// ou plus grand que zero...
	{
		closestt = pix->t2;
		pix->closest_obj = pix->obj[1][0];
	}
}

/*
static void closest_obj(t_pix *pix)
{
	float closestt = INT_MAX;
	int	x;
	int	y;
	
	pix->closest_obj = pix->obj[0][0];
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (pix->hits[x][y] != NULL)
		{
			if (pix->hits[x][y]->t1 < closestt && pix->hits[x][y]->t1 > 0)/// ou plus grand que zero...
			{
				closestt = pix->hits[x][y]->t1;
				pix->closest_obj = pix->obj[x][y];
			}
			if (pix->hits[x][y]->t2 < closestt &&  pix->hits[x][y]->t2 > 0)/// ou plus grand que zero...
			{
				closestt = pix->hits[x][y]->t2;
				pix->closest_obj = pix->obj[x][y];
			}
			y++;
		}
		x++;
	}
}*/

static void init_viewport_x_y(t_pix *pix, int x, int y) //a changer après
{
	pix->vpx = pix->ima->pixel_size * x - pix->ima->half_height;
	pix->vpy = pix->ima->pixel_size * y - pix->ima->half_width;
}

static void	init_viewport(t_pix ***pix)
{
	int	x;
	int	y;
	pix[0][0]->ima->view_height = 100;
	pix[0][0]->ima->view_width = 100;
	pix[0][0]->ima->canva_width = WND_WIDTH;
	pix[0][0]->ima->canva_height = WND_HEIGHT;
	pix[0][0]->ima->pixel_size = pix[0][0]->ima->view_width / pix[0][0]->ima->canva_height;
	pix[0][0]->ima->half_height = pix[0][0]->ima->view_height / 2;
	pix[0][0]->ima->half_width = pix[0][0]->ima->view_width / 2 ;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			init_viewport_x_y(pix[x][y], x, y);
			init_camera_pix_ray(pix[x][y], pix[x][y]->cam);
			y++;
		}
		x++;
	}	
}
/*
# describe the point on the wall that the ray will target
position ← point(world_x, world_y, wall_z)
r ← ray(ray_origin, normalize(position - ray_origin))
xs ← intersect(shape, r)*/

//// ICI!!!
static void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	t_coord *v_cam_pix;
	t_coord *vn_cam_pix;
	t_coord *p_point;

	p_point = create_point(pix->vpx, pix->vpy, DIST_VIEWP_ORIGIN);
	v_cam_pix = substraction(p_point, cam->p_coord);
	vn_cam_pix = normalize_vector(v_cam_pix);
	pix->r_ray = create_ray(pix->cam->p_coord, vn_cam_pix);
/*
	v_cam_pix.x = cam->p_coord->x - pix->vpx;
	v_cam_pix.y = cam->p_coord->y - pix->vpy ;
	v_cam_pix.z = cam->p_coord->z - DIST_VIEWP_ORIGIN;
	v_cam_pix.t = 0;

	vn_cam_pix = normalize_vector(&v_cam_pix);
	try = negat(vn_cam_pix);
	pix->r_ray = create_ray(pix->cam->p_coord, try);
	*/
}
/*
static void init_camera_pix_ray(t_pix *pix, t_camera *cam)
{
	t_coord v_cam_pix;
	t_coord *vn_cam_pix;
	t_coord *try;

	v_cam_pix.x = pix->vpx - cam->p_coord->x;
	v_cam_pix.y = pix->vpy - cam->p_coord->y;
	v_cam_pix.z = DIST_VIEWP_ORIGIN - cam->p_coord->z; 
	v_cam_pix.t = 0;
	

	v_cam_pix.x = cam->p_coord->x - pix->vpx;
	v_cam_pix.y = cam->p_coord->y - pix->vpy ;
	v_cam_pix.z = cam->p_coord->z - DIST_VIEWP_ORIGIN;
	v_cam_pix.t = 0;
	
vn_cam_pix = normalize_vector(&v_cam_pix);
try = negat(vn_cam_pix);
pix->r_ray = create_ray(pix->cam->p_coord, try);
pix->r_ray = create_ray(pix->cam->p_coord, vn_cam_pix);
}
*/

/*
t_coord	*create_vector(float x, float y, float z)
{
	t_coord	*v_vector;

	v_vector = malloc(sizeof(t_coord));
	if (!v_vector)
	{
		perror("Error allocating vector\n");
		return (NULL);
	}
	v_vector->x = x;
	v_vector->y = y;
	v_vector->z = z;
	v_vector->t = 0;
	return (v_vector);
}*/

/*
//// ICI!!!
static void init_camera_pix_ray(t_pix ***pix)
{
	int	x;
	int	y;
	t_coord v_cam_pix;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			v_cam_pix.x = pix[x][y]->vpx - cam;
			v_cam_pix.y = pix[x][y]->vpy - cam;
			v_cam_pix.z = DIST_VIEWP_ORIGIN - cam z;
			v_cam_pix.t = 0;
//			pix[x][y]->vpx = x - (pix[0][0]->ima->canva_height / 2);
//			pix[x][y]->vpy = y - (pix[0][0]->ima->canva_width / 2)
			v direction....
			normalize v direction.
			t_coord	*normalize_vector(t_coord *v_1);
			pix[x][y]->v_d = create_ray(pix[0][0]->cam->p_coord, t_coord *v_direction)
			// normalized ray. 

			
			y++;
		}
		x++;
	}
}
*/


/*
//pas utilisée
void	canva_to_viewport(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			pix[x][y]->vpx = x - (pix[0][0]->ima->canva_height / 2);
			pix[x][y]->vpy = y - (pix[0][0]->ima->canva_width / 2);
			y++;
		}
		x++;
	}
}*/