/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:28 by syl               #+#    #+#             */
/*   Updated: 2025/03/19 07:14:10 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_color	calculate_ambient_light(t_light *ambient_light, t_color *object_color)
{
	t_color	result;

	result.r = ambient_light->ratio * object_color->r * ambient_light->color->r;
	result.g = ambient_light->ratio * object_color->g * ambient_light->color->g;
	result.b = ambient_light->ratio * object_color->b * ambient_light->color->b;
	return (result);
}

/* float	dot_product(t_coord *v1, t_coord *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
} */

t_color	calculate_diffuse_light(t_light *light, t_coord *normal,
		t_coord *light_dir, t_color *object_color)
{
	t_color	result;
	float	dot;

	dot = fmax(0, dot_product(normal, light_dir));
	result.r = light->ratio * dot * object_color->r * light->color->r;
	result.g = light->ratio * dot * object_color->g * light->color->g;
	result.b = light->ratio * dot * object_color->b * light->color->b;
	return (result);
}

t_color	calculate_specular_light(t_light *light, t_coord *view_dir,
		t_coord *normal, t_coord *light_dir, float shininess)
{
	t_color	result;
	t_coord	reflected;
	float	dot;

	// Calculer la réflexion de la lumière
	reflected.x = 2 * dot_product(normal, light_dir) * normal->x - light_dir->x;
	reflected.y = 2 * dot_product(normal, light_dir) * normal->y - light_dir->y;
	reflected.z = 2 * dot_product(normal, light_dir) * normal->z - light_dir->z;

	// Calculer le produit scalaire entre la réflexion et la direction de la caméra
	dot = fmax(0, dot_product(&reflected, view_dir));
	dot = pow(dot, shininess);

	result.r = light->ratio * dot * light->color->r;
	result.g = light->ratio * dot * light->color->g;
	result.b = light->ratio * dot * light->color->b;
	return (result);
}

t_color	compute_lighting(t_pix *pix, t_coord *point,
		t_coord *normal, t_coord *view_dir)
{
	t_color	final_color = {0, 0, 0, 0};
	t_color	ambient, diffuse, specular;
	t_light	**lights = pix->lux[0]; // Liste des lumières
	int		i;

	// Lumière ambiante
	ambient = calculate_ambient_light(lights[0], pix->color);
	final_color.r += ambient.r;
	final_color.g += ambient.g;
	final_color.b += ambient.b;

	// Lumières directionnelles ou ponctuelles
	i = 1;
	while (lights[i])
	{
		t_coord	light_dir = {
			lights[i]->p_coord->x - point->x,
			lights[i]->p_coord->y - point->y,
			lights[i]->p_coord->z - point->z,
			0
		};
		// Normaliser light_dir ici si nécessaire

		diffuse = calculate_diffuse_light(lights[i], normal, &light_dir, pix->color);
		specular = calculate_specular_light(lights[i], view_dir, normal, &light_dir, 32); // Shininess = 32

		final_color.r += diffuse.r + specular.r;
		final_color.g += diffuse.g + specular.g;
		final_color.b += diffuse.b + specular.b;
		i++;
	}
	return (final_color);
}



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