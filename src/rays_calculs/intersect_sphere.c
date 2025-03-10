/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 17:56:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//The sphere() function should return a unique value each time it is invoked.
//New function

// si t1 et / ou t2 négatifs, c est que c est derrière la camera

//NEWONE!!
//from the test... to change a bit
void main_sphere(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
	//		p_camera = create_point(0, 2, -5);//camera A MODIFIER
	//		v_vect = create_vector(0, 0, 1);// entre camera et point A MODIFIER
	//		pix[x][y]->r_ray = create_ray(p_camera, v_vect);
			intersect_sphere(pix[x][y], 0);//faire une autre boucle avec les spheres. 
		//	intersect_sphere(pix[x][y], 1);
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

	v_sph_camera = substraction(pix->r_ray->p_origin, pix->obj[1][sphere_num]->p_coord);
	a = dot_product(pix->r_ray->v_dir, pix->r_ray->v_dir);
	b = 2 * dot_product(pix->r_ray->v_dir, v_sph_camera);
	c = dot_product(v_sph_camera, v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
//		pix->hits[1][sphere_num]->t_count = 0;
//		pix->hits[1][sphere_num]->t1 = 0;
//		pix->hits[1][sphere_num]->t2 = 0;
		pix->t_count = 0;
		pix->t1 = 0;// INT_MAX;//necessaire?? ancienne methode
		pix->t2 = 0;// INT_MAX;//necessaire?? ancienne methode
		return;
	}
//	pix->hits[1][sphere_num]->t_count = 2;
//	pix->hits[1][sphere_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
//	pix->hits[1][sphere_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	pix->t_count = 2;
	pix->t1 = (-b - sqrt(discriminant)) / (2*a);
	pix->t2 =(-b + sqrt(discriminant)) / (2*a);
	return ;
	
}

/*
void intersection
{
	//value of the intersection
	//the object that was intersected
	
}*/