/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 12:06:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// si t1 et / ou t2 négatifs, c est que c est derrière la camera
//NEWONE!!
void main_intersections(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;

	printf("enter intersect\n");
	a = 1;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			a = 1;
			while (a < 4)
			{
				b = 0;
				while(pix[x][y]->obj[a][b] != NULL)
				{
					if (a == SPHERE)
						intersect_sphere(pix[x][y], b);
					else if (a == PLAN)
						intersect_plan(pix[x][y], b);
					else if (a == CYLINDER)
						intersect_cylinder(pix[x][y], b);					
					b++;
				}
				a++;
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

//	# the vector from the sphere's center, to the ray origin
	t_coord *v_sph_camera;
	v_sph_camera = substraction(pix->hits[1][sphere_num]->r_origin, pix->cam->p_origin_zero);//origine sphere à zero
	a = dot_product(pix->hits[1][sphere_num]->r_dir, pix->hits[1][sphere_num]->r_dir);
//	print_vector(pix->hits[1][sphere_num]->r_ray_calculs->v_dir);
	b = 2 * dot_product(pix->hits[1][sphere_num]->r_dir, v_sph_camera);
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
	pix->hits[1][sphere_num]->obj_type = SPHERE;

	return ;
}