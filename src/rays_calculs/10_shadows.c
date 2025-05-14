/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:20:52 by syl               #+#    #+#             */
/*   Updated: 2025/05/14 21:35:35 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	cut_cylinder_shad(t_pix *pix, int cyl_n, float t1, float t2);

void	prepare_v_light(t_pix *pix, int lux_num)
{
	t_coord	offset_point;
	t_coord	tmp;

	scalar_mult_na(&tmp, pix->comps->v_norm_parral, EPSILON * 100);
	addition_na(&offset_point, pix->comps->p_touch, &tmp);
	substraction_p_to_v_na(pix->comps->v_light_to_point,
		pix->lux[1][lux_num]->p_coord, &offset_point);
	pix->comps->distance_light_p_touch
		= length_vector(pix->comps->v_light_to_point);
	normalize_vector_na(pix->comps->v_light_to_point);
}

bool	intersect_objects_shadow(t_pix *pix, int lux_num)
{
	int		a;
	int		b;
	bool	in_shadow;

	in_shadow = false;

	a = 0;
	while (pix->obj[a] != NULL)
	{
		b = 0;
		while (pix->obj[a][b] != NULL)
		{
			if (a == SPHERE)
				in_shadow = intersect_sphere_shadow(pix, b, lux_num);
			else if (a == PLAN)
				in_shadow = intersect_plan_shadow(pix, b, lux_num);
		//	else if (a == CYLINDER)
		//		in_shadow = intersect_cylinder_shadow(pix, b, lux_num);
			if (in_shadow)
				return (true);
			b++;
		}
		a++;
	}
	return (false);
}

bool	intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num)
{
	float	coeffs[3];
	float	discriminant;
	float	roots[2];
	float	sqrt_discr;

	substraction_p_to_v_na(pix->comps->v_sphere_to_point, pix->comps->p_touch,
		pix->obj[1][sphere_num]->p_coord);
	coeffs[0] = dot_product(pix->comps->v_light_to_point,
			pix->comps->v_light_to_point);
	coeffs[1] = 2.0f * dot_product(pix->comps->v_sphere_to_point,
			pix->comps->v_light_to_point);
	coeffs[2] = dot_product(pix->comps->v_sphere_to_point,
			pix->comps->v_sphere_to_point) - (pix->obj[1][sphere_num]->radius
			* pix->obj[1][sphere_num]->radius);
	discriminant = coeffs[1] * coeffs[1] - 4.0f * coeffs[0] * coeffs[2];
	if (discriminant < 0.0f)
		return (false);
	sqrt_discr = sqrtf(discriminant);
	roots[0] = (-coeffs[1] - sqrt_discr) / (2.0f * coeffs[0]);
	roots[1] = (-coeffs[1] + sqrt_discr) / (2.0f * coeffs[0]);
	if ((roots[0] > EPSILON && roots[0] < pix->comps->distance_light_p_touch)
		|| (roots[1] > EPSILON
			&& roots[1] < pix->comps->distance_light_p_touch))
		return (true);
	return (false);
}

bool	intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num)
{
	t_coord	p0_minus_p;
	float	denom;
	float	t;

	denom = dot_product(pix->obj[2][pln_num]->v_axe,
			pix->comps->v_light_to_point);
	if (fabs(denom) < EPSILON)
		return (false);
	p0_minus_p.x = pix->obj[2][pln_num]->p_coord->x - pix->comps->p_touch->x;
	p0_minus_p.y = pix->obj[2][pln_num]->p_coord->y - pix->comps->p_touch->y;
	p0_minus_p.z = pix->obj[2][pln_num]->p_coord->z - pix->comps->p_touch->z;
	t = dot_product(pix->obj[2][pln_num]->v_axe, &p0_minus_p) / denom;
	if (t > EPSILON && t < pix->comps->distance_light_p_touch)
		return (true);
	return (false);
}

/*
bool	intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num)
{
	(void)pix;
	(void)cyl_num;
	(void)lux_num;
	return (false);

}*/

bool	intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = pix->comps->v_light_to_point->x * pix->comps->v_light_to_point->x
		+ pix->comps->v_light_to_point->z * pix->comps->v_light_to_point->z;
	if (fabs(a) < 0.000001)// CHANGER
		return (false);
	b = 2 * pix->lux[1][lux_num]->p_coord->x * pix->comps->v_light_to_point->x
		+ 2 * pix->lux[1][lux_num]->p_coord->z * pix->comps->v_light_to_point->z;
	c = pix->lux[1][lux_num]->p_coord->x * pix->lux[1][lux_num]->p_coord->x
		+ pix->lux[1][lux_num]->p_coord->z * pix->lux[1][lux_num]->p_coord->z
		- pix->obj[3][cyl_num]->radius;//radius??
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false); // il a pas croisé
	if (cut_cylinder_shad(pix, cyl_num,  (-b - simple_sqrt(discriminant)) / (2 * a),
		(-b + simple_sqrt(discriminant)) / (2 * a)) == false)
		return (false);
	return (true);
/*	cut_cylinder(pix, cyl_n, (-b - simple_sqrt(discriminant)) / (2 * a),
		(-b + simple_sqrt(discriminant)) / (2 * a));
	if (intersect_caps_shadow(pix, cyl_n == true))
		return (true);
	return (false);*/
}

bool	cut_cylinder_shad(t_pix *pix, int cyl_n, float t1, float t2)
{
	float	y1;
	float	y2;
	float	tmp;

	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	y1 = pix->hits[3][cyl_n]->r_origin->y + t1 * pix->hits[3][cyl_n]->r_dir->y;
	if (-pix->obj[3][cyl_n]->height / 2 < y1 && y1 < pix->obj[3][cyl_n]->height / 2)
	{
		return (true);
	}
	y2 = pix->hits[3][cyl_n]->r_origin->y + t2 * pix->hits[3][cyl_n]->r_dir->y;
	if (-pix->obj[3][cyl_n]->height / 2 < y2 && y2 < pix->obj[3][cyl_n]->height / 2)
	{
		return (true);
	}
	return (false);
}

/*
bool	check_cap(t_pix *pix, float t, int cyl_n)
{
	float	x;
	float	z;

	
	x = pix->hits[3][cyl_n]->r_origin->x + t * pix->hits[3][cyl_n]->r_dir->x;
	z = pix->hits[3][cyl_n]->r_origin->z + t * pix->hits[3][cyl_n]->r_dir->z;
	if (x * x + z * z <= 1)
	{
	//	printf("+");
		return (true);
	}	
	return (false);
}


void	intersect_caps_shadow(t_pix *pix, int cyl_n)
{
	float	t;

	if (fabs(pix->hits[3][cyl_n]->r_dir->y) < EPSILON)
		return ;
	if (pix->obj[3][cyl_n]->closed_down == true)
	{
	//	printf(".");
		t = (-1 - pix->hits[3][cyl_n]->r_origin->y)
			/ pix->hits[3][cyl_n]->r_dir->y;
		if (check_cap(pix, t, cyl_n) == true && t < pix->hits[3][cyl_n]->t1 &&  t < pix->hits[3][cyl_n]->t2)
		{
			pix->hits[3][cyl_n]->t_count = 8;
			pix->hits[3][cyl_n]->t2 = t;
		//	printf("t2 %.5f, \n", pix->hits[3][cyl_n]->t2);
		}
	}
	pix->obj[3][cyl_n]->closed_up = true;
	if (pix->obj[3][cyl_n]->closed_up == true)
	{
	//	printf("u");	
		t = (1 - pix->hits[3][cyl_n]->r_origin->y)
			/ pix->hits[3][cyl_n]->r_dir->y;
		if (check_cap(pix, t, cyl_n) == true && t < pix->hits[3][cyl_n]->t1 && t < pix->hits[3][cyl_n]->t2)
		{
			pix->hits[3][cyl_n]->t_count = 9;
			pix->hits[3][cyl_n]->t1 = t;
		//	printf("t1 %.5f, \n", pix->hits[3][cyl_n]->t1);
		}
	}
}*/



/*
bool	intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num)
//void	intersect_cylinder(t_pix *pix, int cyl_n)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = pix->hits[3][cyl_n]->r_dir->x * pix->hits[3][cyl_n]->r_dir->x
		+ pix->hits[3][cyl_n]->r_dir->z * pix->hits[3][cyl_n]->r_dir->z;
	if (fabs(a) < 0.000001)// CHANGER
		return ;
	b = 2 * pix->hits[3][cyl_n]->r_origin->x * pix->hits[3][cyl_n]->r_dir->x
		+ 2 * pix->hits[3][cyl_n]->r_origin->z * pix->hits[3][cyl_n]->r_dir->z;
	c = pix->hits[3][cyl_n]->r_origin->x * pix->hits[3][cyl_n]->r_origin->x
		+ pix->hits[3][cyl_n]->r_origin->z * pix->hits[3][cyl_n]->r_origin->z
		- 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false); // il a pas croisé
	return (true);
	cut_cylinder(pix, cyl_n, (-b - simple_sqrt(discriminant)) / (2 * a),
		(-b + simple_sqrt(discriminant)) / (2 * a));
	if (intersect_caps_shadow(pix, cyl_n == true))
		return (true);
	return (false);
}*/