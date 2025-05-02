/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/05/02 11:04:16 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// si t1 et / ou t2 négatifs, c est que c est derrière la camera
void main_intersections(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;

	//printf("enter intersect\n");
	a = 1;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			b = 0;
			while(pix[x][y]->obj[1][b] != NULL)
			{
				intersect_sphere(pix[x][y], b);
				b++;
			}
			b = 0;
			while(pix[x][y]->obj[2][b] != NULL)
			{
				intersect_plan(pix[x][y], b);
				b++;
			}
			b = 0;
			while(pix[x][y]->obj[3][b] != NULL)
			{
				intersect_cylinder(pix[x][y], b);
				b++;
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

	substraction_p_to_v_NA(pix->obj[1][sphere_num]->v_sph_camera, pix->hits[1][sphere_num]->r_origin, pix->cam->p_origin_zero);
	a = dot_product(pix->hits[1][sphere_num]->r_dir, pix->hits[1][sphere_num]->r_dir);
	b = 2 * dot_product(pix->hits[1][sphere_num]->r_dir, pix->obj[1][sphere_num]->v_sph_camera);
	c = dot_product(pix->obj[1][sphere_num]->v_sph_camera, pix->obj[1][sphere_num]->v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
		pix->hits[1][sphere_num]->t_count = 0;
		pix->hits[1][sphere_num]->t1 = INT_MAX;
		pix->hits[1][sphere_num]->t2 = INT_MAX;
		return;
	}
	pix->hits[1][sphere_num]->t_count = 2;
	pix->hits[1][sphere_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	pix->hits[1][sphere_num]->obj_type = SPHERE;
	return ;
}


/*
// si t1 et / ou t2 négatifs, c est que c est derrière la camera
void main_intersections(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;

	//printf("enter intersect\n");
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
					if (a == 1)// (a == SPHERE)
						intersect_sphere(pix[x][y], b);
					if (a == 2)// (a == PLAN)
						intersect_plan(pix[x][y], b);
					if (a == 3)//(a == CYLINDER)
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
*/