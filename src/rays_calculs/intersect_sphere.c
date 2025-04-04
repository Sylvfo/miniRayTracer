/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/04/04 16:29:44 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// si t1 et / ou t2 négatifs, c est que c est derrière la camera
//NEWONE!!
void main_sphere(t_pix ***pix)
{
	int	x;
	int	y;
	int k;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			k = 0;
			while(pix[x][y]->obj[1][k] != NULL)
			{
				transform(pix[x][y], pix[x][y]->obj[1][k]->m_tranf);
				intersect_sphere(pix[x][y], k);
				k++;
			}
			y++;
		}
		x++;
	}
}

void intersect_sphere(t_pix *pix, int sphere_num)
{
	float discriminant;
	float a;
	float b;
	float c;
	//arguments c'est ray et sphere
//	# the vector from the sphere's center, to the ray origin
	t_coord *v_sph_camera;

	v_sph_camera = substraction(pix->r_ray->p_origin, pix->p_origin_zero);//origine sphere à zero
	a = dot_product(pix->r_ray->v_dir, pix->r_ray->v_dir);
	b = 2 * dot_product(pix->r_ray->v_dir, v_sph_camera);
//	c = dot_product(v_sph_camera, v_sph_camera) - ((pix->obj[1][sphere_num]->diam / 2) *(pix->obj[1][sphere_num]->diam / 2)); //ici à optimisier
	c = dot_product(v_sph_camera, v_sph_camera) - 1;// ICI C EST SIMPLIFIE DANS LA METHODE QU ON UTILISE radius 1
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
		pix->hits[1][sphere_num]->t_count = 0;
		pix->hits[1][sphere_num]->t1 = 0;
		pix->hits[1][sphere_num]->t2 = 0;
		return;
	}
	pix->hits[1][sphere_num]->t_count = 2;
	pix->hits[1][sphere_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	return ;
}

/*
FONCTIONNE, MAIS PREND LE CENTRE DE LA SPHERE COMME ARG. COMME ANCIEN PROJET
void intersect_sphere(t_pix *pix, int sphere_num)
{
	float discriminant;
	float a;
	float b;
	float c;
	//arguments c'est ray et sphere
//	# the vector from the sphere's center, to the ray origin
	t_coord *v_sph_camera;

	v_sph_camera = substraction(pix->r_ray->p_origin, pix->obj[1][sphere_num]->p_coord);
	a = dot_product(pix->r_ray->v_dir, pix->r_ray->v_dir);
	b = 2 * dot_product(pix->r_ray->v_dir, v_sph_camera);
//	c = dot_product(v_sph_camera, v_sph_camera) - ((pix->obj[1][sphere_num]->diam / 2) *(pix->obj[1][sphere_num]->diam / 2)); //ici à optimisier
	c = dot_product(v_sph_camera, v_sph_camera) - 1;// ICI C EST SIMPLIFIE DANS LA METHODE QU ON UTILISE
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
		pix->hits[1][sphere_num]->t_count = 0;
		pix->hits[1][sphere_num]->t1 = 0;
		pix->hits[1][sphere_num]->t2 = 0;
		return;
	}
	pix->hits[1][sphere_num]->t_count = 2;
	pix->hits[1][sphere_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	return ;
}

*/

/*
FONCTIONNE
void intersect_sphere(t_pix *pix, int sphere_num)
{
	float discriminant;
	float a;
	float b;
	float c;
	//arguments c'est ray et sphere
//	# the vector from the sphere's center, to the ray origin
	t_coord *v_sph_camera;

	v_sph_camera = substraction(pix->r_ray->p_origin, pix->obj[1][sphere_num]->p_coord);
	a = dot_product(pix->r_ray->v_dir, pix->r_ray->v_dir);
	b = 2 * dot_product(pix->r_ray->v_dir, v_sph_camera);
	c = dot_product(v_sph_camera, v_sph_camera) - ((pix->obj[1][sphere_num]->diam / 2) *(pix->obj[1][sphere_num]->diam / 2)); //ici à optimisier
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
		pix->hits[1][sphere_num]->t_count = 0;
		pix->hits[1][sphere_num]->t1 = 0;
		pix->hits[1][sphere_num]->t2 = 0;
		return;
	}
	pix->hits[1][sphere_num]->t_count = 2;
	pix->hits[1][sphere_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	return ;
	
}
 */
