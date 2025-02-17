/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:26:51 by syl               #+#    #+#             */
/*   Updated: 2025/01/26 15:09:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minirt.h"

float ComputeLighting(t_pix *pix, float closestt, t_sphere *closest_sphere)
{
	t_3dpoint *P;
	t_vect3d *N;
	float intensity;

	P = malloc(sizeof(t_3dpoint));
	N = malloc(sizeof(t_vect3d));

	P = pointonline(pix, closestt);
//	N = vect_from_points(closest_sphere->center, P);
	N = vect_from_points(P, closest_sphere->center);
	//problem avec ce N!!
	normalize_vector(N);
//	print3dvect(N);
	intensity = compute_ambient(pix);
	intensity = light_intensity(P, N, pix);
//	pix->color = closest_sphere->color;
	pix->color = modify_color(closest_sphere->color, intensity);
	free (P);
	free (N);
}

float 	compute_spotlight(t_3dpoint *P, t_vect3d *N, t_pix *pix, t_spotlight *light)
{
	t_vect3d *L;
	float n_dot_l;
	float i;

	i = 0.0;
	L = malloc(sizeof(t_vect3d));
	L = vect_from_points(light->coord, P);// TROUVER P
	// ici probleme
//	L = vect_from_points(P, light->coord);

	n_dot_l =  dot_product(N, L);// TROUVER N
	if (n_dot_l > 0) 
	{
		i = -light->ratio * n_dot_l/((lenght_vector(N) * lenght_vector(L)));
	}
//	i = light->ratio * n_dot_l/(lenght_vector(N) * lenght_vector(L));
	free (L);
	return (i);
}

float light_intensity(t_3dpoint *P, t_vect3d *N, t_pix *pix)
{
	float i;
	float n_dot_l;

	i = 0.0;
	//boucle while pour différents 
	i += compute_ambient(pix);// ok
	i += compute_spotlight(P, N, pix, pix->scene->light1);
//	i = pix->scene->light1->ratio;
	
//	i += computre_directionlight 
	return (i);
}

//ok
float 	compute_ambient(t_pix *pix)
{
	float i;

	i = pix->scene->ambient_light_ratio;
	return (i);
}

