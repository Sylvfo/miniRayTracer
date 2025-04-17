/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 12:05:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void intersect_cylinder(t_pix *pix, int cyl_num)
{
	float a;
	float b;
	float c;
	float discriminant;
	
	a = pix->hits[3][cyl_num]->r_dir->x * pix->hits[3][cyl_num]->r_dir->x + pix->hits[3][cyl_num]->r_dir->z * pix->hits[3][cyl_num]->r_dir->z;
	if (fabs(a) < EPSILON) // or approximately zero ray is parallel to the y axis
	{
	//	printf("n");
		pix->hits[3][cyl_num]->t_count = 0;// ca on peut mettre au début...
		pix->hits[3][cyl_num]->t1 = 0;
		pix->hits[3][cyl_num]->t2 = 0;
		return;
	}
	b = 2 * pix->hits[3][cyl_num]->r_origin->x * pix->hits[3][cyl_num]->r_dir->x + 2 * pix->hits[3][cyl_num]->r_origin->z * pix->hits[3][cyl_num]->r_dir->z;
	c = pix->hits[3][cyl_num]->r_origin->x * pix->hits[3][cyl_num]->r_origin->x + pix->hits[3][cyl_num]->r_origin->z * pix->hits[3][cyl_num]->r_origin->z - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
	//	printf("b");
		pix->hits[3][cyl_num]->t_count = 0;
		pix->hits[3][cyl_num]->t1 = 0;
		pix->hits[3][cyl_num]->t2 = 0;
		return;
	}
	pix->hits[3][cyl_num]->t_count = 2;
	float t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	float t2 = (-b + simple_sqrt(discriminant)) / (2*a);
//	pix->hits[3][cyl_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
//	pix->hits[3][cyl_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
//	printf("t");
	
	// pour couper le cylindre
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
	//	y0 = pix->hits[3][cyl_num]->r_origin->y + pix->hits[3][cyl_num]->t1 * pix->hits[3][cyl_num]->r_dir->y;
	y1 = pix->hits[3][cyl_num]->r_origin->y + t1 * pix->hits[3][cyl_num]->r_dir->y;
	if (0 < y1 && y1 < pix->obj[3][cyl_num]->height)
	{
		pix->hits[3][cyl_num]->t1 = t1;
		pix->hits[3][cyl_num]->t_count++;
	}
	else
	{
		pix->hits[3][cyl_num]->t_count = 0;// ca on peut mettre au début...
		pix->hits[3][cyl_num]->t1 = 0;
	}
	y2 = pix->hits[3][cyl_num]->r_origin->y + t2 * pix->hits[3][cyl_num]->r_dir->y;
	if (0 < y2 && y2 < pix->obj[3][cyl_num]->height)
	{
		pix->hits[3][cyl_num]->t2 = t2;
		pix->hits[3][cyl_num]->t_count++;
	}
	else
	{
		pix->hits[3][cyl_num]->t2 = 0;
	}
	intersect_caps(pix, cyl_num);
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

//function check_cap(ray, t)
//x ← ray.origin.x + t * ray.direction.x
//z ← ray.origin.z + t * ray.direction.z
//return (x² + z²) <= 1
//end

void intersect_caps(t_pix *pix, int cyl_num)
{
	float t;

	//if (pix->obj[3][cyl_num]->closed == false || pix->hits[3][cyl_num]->r_dir->y < EPSILON)
	if (fabs(pix->hits[3][cyl_num]->r_dir->y) < EPSILON)
		return;
	if (pix->obj[3][cyl_num]->closed_down == true)
	{
		t = (0 - pix->hits[3][cyl_num]->r_origin->y) / pix->hits[3][cyl_num]->r_dir->y;
		if (check_cap(pix, t, cyl_num) == true)
		{
			pix->hits[3][cyl_num]->t2 = t;
		}
	}
	if (pix->obj[3][cyl_num]->closed_up == true)
	{
		t = (pix->obj[3][cyl_num]->height - pix->hits[3][cyl_num]->r_origin->y) / pix->hits[3][cyl_num]->r_dir->y;
		if (check_cap(pix, t, cyl_num) == true)
		{
			pix->hits[3][cyl_num]->t1 = t;
		}
	}
}
/*
function intersect_caps(cyl, ray, xs)
# caps only matter if the cylinder is closed, and might possibly be
# intersected by the ray.
//if cyl is not closed or ray.direction.y is close to zero
//return
end if
# check for an intersection with the lower end cap by intersecting
# the ray with the plane at y=cyl.minimum
//t ← (cyl.minimum - ray.origin.y) / ray.direction.y
if check_cap(ray, t)
add intersection(t, cyl) to xs
end if
# check for an intersection with the upper end cap by intersecting
# the ray with the plane at y=cyl.maximum
t ← (cyl.maximum - ray.origin.y) / ray.direction.y
if check_cap(ray, t)
add intersection(t, cyl) to xs
end if
end function*/

/*
// pour trunquer
//xs = ()
//y0 ← ray.origin.y + t0 * ray.direction.y
if cylinder.minimum < y0 and y0 < cylinder.maximum
add intersection(t0, cylinder) to xs
end if
y1 ← ray.origin.y + t1 * ray.direction.y
if cylinder.minimum < y1 and y1 < cylinder.maximum
add intersection(t1, cylinder) to xs
end if
return xs
*/

//function local_intersect(cylinder, ray)
//a ← ray.direction.x² + ray.direction.z²
//# ray is parallel to the y axis
//return () if a is approximately zero
//b ← 2 * ray.origin.x * ray.direction.x +
//2 * ray.origin.z * ray.direction.z
//c ← ray.origin.x² + ray.origin.z² - 1
// disc ← b² - 4 * a * c
//# ray does not intersect the cylinder
//return () if disc < 0
//t0 ← (-b - √(disc)) / (2 * a)
//t1 ← (-b + √(disc)) / (2 * a)
//return ( intersection(t0, cylinder), intersection(t1, cylinder) )
//end function

/*
void intersect_sphere(t_pix *pix, int cyl_num)
{
	float discriminant;
	float a;
	float b;
	float c;
//	# the vector from the sphere's center, to the ray origin
	t_coord *v_sph_camera;
	v_sph_camera = substraction(pix->hits[1][cyl_num]->r_origin, pix->cam->p_origin_zero);//origine sphere à zero
	a = dot_product(pix->hits[1][cyl_num]->r_dir, pix->hits[1][cyl_num]->r_dir);
	b = 2 * dot_product(pix->hits[1][cyl_num]->r_dir, v_sph_camera);
	c = dot_product(v_sph_camera, v_sph_camera) - 1;// ICI C EST SIMPLIFIE DANS LA METHODE QU ON UTILISE radius 1
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0) // ca veut dire que l objet ne croise pas le point. 
	{
		pix->hits[1][cyl_num]->t_count = 0;
		pix->hits[1][cyl_num]->t1 = 0;
		pix->hits[1][cyl_num]->t2 = 0;
		return;
	}
	pix->hits[1][cyl_num]->t_count = 2;
	pix->hits[1][cyl_num]->t1 = (-b - simple_sqrt(discriminant)) / (2*a);
	pix->hits[1][cyl_num]->t2 = (-b + simple_sqrt(discriminant)) / (2*a);
	return ;
}



void intersect_plan(t_pix *pix, int plan_num)
{
	//empty set, no intersection
	// fabs mets tous les nombres en positif
	if (fabs(pix->hits[2][plan_num]->r_dir->y) < EPSILON)
	{
		pix->hits[2][plan_num]->t_count = 0;
		pix->hits[2][plan_num]->t1 = 0;
		pix->hits[2][plan_num]->t2 = 0;
		return ;
	}
	//origin.y + t * dir.y = 0 c est l équation de l intersection entre le plan et le ray
	pix->hits[2][plan_num]->t1 = -(pix->hits[2][plan_num]->r_origin->y / pix->hits[2][plan_num]->r_dir->y);
	pix->hits[2][plan_num]->t_count = 0;
}*/