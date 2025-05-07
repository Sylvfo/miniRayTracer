/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:39:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void intersect_cylinder(t_pix *pix, int cyl_num)
{
	float a;
	float b;
	float c;
	float discriminant;

	pix->hits[3][cyl_num]->t_count = 0;// A METTRE DANS INIT
	pix->hits[3][cyl_num]->t1 = INT_MAX;
	pix->hits[3][cyl_num]->t2 = INT_MAX;
	
	a = pix->hits[3][cyl_num]->r_dir->x * pix->hits[3][cyl_num]->r_dir->x + pix->hits[3][cyl_num]->r_dir->z * pix->hits[3][cyl_num]->r_dir->z;
	if (fabs(a) < EPSILON) // or approximately zero ray is parallel to the y axis
		return;
	b = 2 * pix->hits[3][cyl_num]->r_origin->x * pix->hits[3][cyl_num]->r_dir->x + 2 * pix->hits[3][cyl_num]->r_origin->z * pix->hits[3][cyl_num]->r_dir->z;
	c = pix->hits[3][cyl_num]->r_origin->x * pix->hits[3][cyl_num]->r_origin->x + pix->hits[3][cyl_num]->r_origin->z * pix->hits[3][cyl_num]->r_origin->z - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
		return;
	pix->hits[3][cyl_num]->t_count = 2;
	float t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	float t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	cut_cylinder(pix, cyl_num, t1, t2);

	// ici optimisation si pas touché...
	intersect_caps(pix, cyl_num);
}

void cut_cylinder(t_pix *pix, int cyl_num, float t1, float t2)
{
	float y1;
	float y2;
	float tmp;
	//SWAPP!!
	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	//cyl minimum / maximum....
	y1 = pix->hits[3][cyl_num]->r_origin->y + t1 * pix->hits[3][cyl_num]->r_dir->y;
	if (-pix->obj[3][cyl_num]->height < y1 && y1 < pix->obj[3][cyl_num]->height)
	{
		pix->hits[3][cyl_num]->t1 = t1;
		pix->hits[3][cyl_num]->t_count = 1;
	}
	y2 = pix->hits[3][cyl_num]->r_origin->y + t2 * pix->hits[3][cyl_num]->r_dir->y;
	if (-pix->obj[3][cyl_num]->height < y2 && y2 < pix->obj[3][cyl_num]->height)
	{
		pix->hits[3][cyl_num]->t2 = t2;
		pix->hits[3][cyl_num]->t_count++;
	}
}

bool	check_cap(t_pix *pix, float t, int cyl_num)
{
	float x;
	float z;

	x = pix->hits[3][cyl_num]->r_origin->x + t * pix->hits[3][cyl_num]->r_dir->x;
	z = pix->hits[3][cyl_num]->r_origin->z + t * pix->hits[3][cyl_num]->r_dir->z;
	if (x * x + z * z <= 1)
		return true;
	return false;
}

void intersect_caps(t_pix *pix, int cyl_num)
{
	float t;

	if (fabs(pix->hits[3][cyl_num]->r_dir->y) < EPSILON)
		return;
	if (pix->obj[3][cyl_num]->closed_down == true)
	{
		t = (-pix->obj[3][cyl_num]->height - pix->hits[3][cyl_num]->r_origin->y) / pix->hits[3][cyl_num]->r_dir->y;
		if (check_cap(pix, t, cyl_num) == true)
		{
			pix->hits[3][cyl_num]->t_count = 8;
			pix->hits[3][cyl_num]->t2 = t;
		}
	}
	if (pix->obj[3][cyl_num]->closed_up == true)
	{
		t = (pix->obj[3][cyl_num]->height - pix->hits[3][cyl_num]->r_origin->y) / pix->hits[3][cyl_num]->r_dir->y;
		if (check_cap(pix, t, cyl_num) == true)
		{
			pix->hits[3][cyl_num]->t_count = 9;
			pix->hits[3][cyl_num]->t1 = t;
		}
	}
}
