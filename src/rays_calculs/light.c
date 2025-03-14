/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:28 by syl               #+#    #+#             */
/*   Updated: 2025/03/14 10:57:50 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//pour l instant c est pour sphere
// il faudra modifier pour les autres formes

// je pense qu il faut modifier où est intensity (dans chaque pix??)
/*
void main_light(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			// à gérer aussi pour les différentes spheres...
			ComputeLighting(pix[x][y], pix[x][y]->closestt, pix[x][y]->obj[1][0]);

			color_float_to_int(pix[x][y]->color);
			y++;
		}
		x++;
	}	
}

void ComputeLighting(t_pix *pix, float closestt, t_obj *sphere)
{
	t_coord *P; //point
	t_coord		*v_normal; //	t_vect3d *N;
	float intensity;

	v_normal = malloc(sizeof(t_coord));// besoin allouer v_normal??
	P = position(pix->r_ray, closestt);
	v_normal = normal_at(sphere, P); // ici il faut le retravailler
	v_normal = normalize_vector(v_normal);

	intensity = compute_ambient(pix); // ca ok...
	intensity = light_intensity(P, v_normal, pix);

	pix->color = modify_color(sphere->color, intensity);//A CHANGER

	free (P);
	free (v_normal);
}

float 	compute_spotlight(t_coord *P, t_coord *N, t_pix *pix, t_light *light)
{
	t_coord *L;
	float n_dot_l;
	float i;

	i = 0.0;
	L = malloc(sizeof(t_coord));
	L = substraction(light->p_coord, P);
	n_dot_l =  dot_product(N, L);// TROUVER N
	if (n_dot_l > 0) 
	{
		i = -light->ratio * n_dot_l/((lenght_vector(N) * lenght_vector(L)));
	}
//	i = light->ratio * n_dot_l/(lenght_vector(N) * lenght_vector(L));
	free (L);
	return (i);
}

float light_intensity(t_coord *P, t_coord *N, t_pix *pix)
{
	float i;
	float n_dot_l;

	i = 0.0;
	//boucle while pour différents 
	i += compute_ambient(pix);// ok
	i += compute_spotlight(P, N, pix, pix->lux[1][0]);
//	i = pix->scene->light1->ratio;
	
//	i += computre_directionlight 
	return (i);
}

//ok dans nouveau projet
float 	compute_ambient(t_pix *pix)
{
	float i;

	i = pix->lux[0][0]->ratio; 
	return (i);
}*/