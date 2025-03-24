/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:27:28 by syl               #+#    #+#             */
/*   Updated: 2025/03/24 13:45:51 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

#define TOL 0.0001

t_coord *vec_sub(t_coord *a, t_coord *b)
{
	t_coord *result = malloc(sizeof(t_coord));
	if (!result)
		return NULL;
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	result->t = a->t; // conserver le type ou l'autre information
	return result;
}

void vec_normalize(t_coord *v)
{
	float length = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
	if (length != 0)
	{
		v->x /= length;
		v->y /= length;
		v->z /= length;
	}
}

// Implémentation de vec_dot accessible externement.
float vec_dot(t_coord *a, t_coord *b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

// Retourne le vecteur "in" réfléchi autour de "normal"
t_coord *reflect(t_coord *in, t_coord *normal)
{
	float dot_value = vec_dot(in, normal);
	t_coord *result = malloc(sizeof(t_coord));
	if (!result)
		return NULL;
	result->x = in->x - normal->x * 2 * dot_value;
	result->y = in->y - normal->y * 2 * dot_value;
	result->z = in->z - normal->z * 2 * dot_value;
	result->t = in->t;
	return result;
}

// Compare deux vecteurs avec une tolérance donnée.
static int compare_coords(t_coord *a, t_coord *b, float tol)
{
	if (fabs(a->x - b->x) > tol) return 0;
	if (fabs(a->y - b->y) > tol) return 0;
	if (fabs(a->z - b->z) > tol) return 0;
	return 1;
}

// Scénario: Reflecting a vector approaching at 45°
void test_reflect_45(void)
{
	t_coord v = {1, -1, 0, 0};
	t_coord n = {0, 1, 0, 0};
	t_coord expected = {1, 1, 0, 0};
	t_coord *r = reflect(&v, &n);

	if (r == NULL)
	{
		printf("Test Reflect 45° failed: reflect() returned NULL\n");
		exit(1);
	}
	
	if (!compare_coords(r, &expected, TOL))
	{
		printf("Test Reflect 45° failed: got (%f, %f, %f), expected (%f, %f, %f)\n",
			r->x, r->y, r->z, expected.x, expected.y, expected.z);
		exit(1);
	}
	else
		printf("Test Reflect 45° passed.\n");
	free(r);
}

// Scénario: Reflecting a vector off a slanted surface
void test_reflect_slanted(void)
{
	t_coord v = {0, -1, 0, 0};
	float sqrt2_over_2 = sqrt(2) / 2;
	t_coord n = {sqrt2_over_2, sqrt2_over_2, 0, 0};
	t_coord expected = {1, 0, 0, 0};
	t_coord *r = reflect(&v, &n);
	if (r == NULL)
	{
		printf("Test Reflect slanted failed: reflect() returned NULL\n");
		exit(1);
	}
	if (!compare_coords(r, &expected, TOL))
	{
		printf("Test Reflect slanted failed: got (%f, %f, %f), expected (%f, %f, %f)\n",
			r->x, r->y, r->z, expected.x, expected.y, expected.z);
		exit(1);
	}
	else
		printf("Test Reflect slanted passed.\n");
	free(r);
}

// Fonctions de manipulation de couleurs (à adapter selon vos définitions)
t_color *color_new(float r, float g, float b)
{
	t_color *c = malloc(sizeof(t_color));
	if (!c)
		return NULL;
	c->r = r;
	c->g = g;
	c->b = b;
	c->rgb = 0;
	return c;
}

t_color *color_mult(t_color *c1, t_color *c2)
{
	t_color *result = malloc(sizeof(t_color));
	if (!result)
		return NULL;
	// Normaliser les couleurs, multiplier, puis reconvertir à 255
	result->r = ((c1->r / 255.0f) * (c2->r / 255.0f)) * 255.0f;
	result->g = ((c1->g / 255.0f) * (c2->g / 255.0f)) * 255.0f;
	result->b = ((c1->b / 255.0f) * (c2->b / 255.0f)) * 255.0f;
	result->rgb = 0;
	return result;
}

t_color *color_scale(t_color *c, float scalar)
{
	t_color *result = malloc(sizeof(t_color));
	if (!result)
		return NULL;
	result->r = c->r * scalar;
	result->g = c->g * scalar;
	result->b = c->b * scalar;
	result->rgb = 0;
	return result;
}

t_color *color_add(t_color *c1, t_color *c2)
{
	t_color *result = malloc(sizeof(t_color));
	if (!result)
		return NULL;
	result->r = c1->r + c2->r;
	result->g = c1->g + c2->g;
	result->b = c1->b + c2->b;
	result->rgb = 0;
	return result;
}

// Calcule l'intersection entre un rayon et une sphère pour la détection d'ombres
void intersect_sphere_shadow(t_obj *sphere, t_ray *ray, t_hits *hit)
{
	float discriminant;
	float a;
	float b;
	float c;
	t_coord *sphere_to_ray;
	
	// Vecteur de l'origine de la sphère (0,0,0 après transformation) à l'origine du rayon
	t_coord zero = {0, 0, 0, 1}; // Centre de la sphère transformée
	sphere_to_ray = substraction(ray->p_origin, &zero);
	
	a = dot_product(ray->v_dir, ray->v_dir);
	b = 2 * dot_product(ray->v_dir, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1; // Rayon normalisé à 1
	
	discriminant = (b * b) - (4 * a * c);
	
	if (discriminant < 0)
	{
		hit->t_count = 0;
		hit->t1 = -1;
		hit->t2 = -1;
		free(sphere_to_ray);
		return;
	}
	
	hit->t_count = 2;
	hit->t1 = (-b - sqrt(discriminant)) / (2 * a);
	hit->t2 = (-b + sqrt(discriminant)) / (2 * a);
	
	free(sphere_to_ray);
}

/*
* Vérifie si un point est dans l'ombre d'un objet
* 
* @param pix  Le pixel courant (contient tous les objets de la scène)
* @param point Le point d'intersection à vérifier
* @param light La source de lumière
* 
* @return 1 si le point est dans l'ombre, 0 sinon
*/
int is_shadowed(t_pix *pix, t_coord *point, t_light *light)
{
	// Vecteur du point vers la lumière
	t_coord *light_vector = vec_sub(light->p_coord, point);
	float distance_to_light = sqrtf(light_vector->x * light_vector->x +
								light_vector->y * light_vector->y +
								light_vector->z * light_vector->z);
	
	// Normaliser le vecteur pour en faire une direction
	vec_normalize(light_vector);
	
	// Créer un rayon depuis le point d'intersection vers la source de lumière
	t_ray *shadow_ray = malloc(sizeof(t_ray));
	if (!shadow_ray)
	{
		free(light_vector);
		return 0;
	}
	
	// Léger décalage du point de départ pour éviter l'auto-intersection
	t_coord *offset_point = malloc(sizeof(t_coord));
	if (!offset_point)
	{
		free(light_vector);
		free(shadow_ray);
		return 0;
	}

	// Offset = point + normal * EPSILON
	float epsilon_value = 0.001;
	offset_point->x = point->x + light_vector->x * epsilon_value;
	offset_point->y = point->y + light_vector->y * epsilon_value;
	offset_point->z = point->z + light_vector->z * epsilon_value;
	offset_point->t = point->t;
	
	shadow_ray->p_origin = offset_point;
	shadow_ray->v_dir = light_vector;
	
	// Teste l'intersection avec tous les objets
	int x = 0, y = 0;
	int in_shadow = 0;
	
	// Parcourir tous les objets pour vérifier les intersections
	while (x < 4 && !in_shadow)
	{
		y = 0;
		while (pix->obj[x][y] != NULL && !in_shadow)
		{
			// Éviter de tester l'objet lui-même
			if (pix->obj[x][y] != pix->comps->obj)
			{
				// Utiliser t_hits au lieu de t_hit
				t_hits *hit = malloc(sizeof(t_hits));
				if (!hit)
				{
					free(shadow_ray);
					free(light_vector);
					free(offset_point);
					return 0;
				}
				
				// Appeler la fonction appropriée pour calculer l'intersection
				// Si intersect_obj n'est pas disponible, utiliser la fonction correspondante
				hit->t1 = -1;
				hit->t2 = -1;
				hit->t_count = 0;
				
				// Selon le type d'objet, appeler la fonction d'intersection appropriée
				if (pix->obj[x][y]->diam > 0) // C'est une sphère
					intersect_sphere_shadow(pix->obj[x][y], shadow_ray, hit);
				/* else if (pix->obj[x][y]->v_axe != NULL && pix->obj[x][y]->height == 0) // C'est un plan
					intersect_plane(pix->obj[x][y], shadow_ray, hit);
				else if (pix->obj[x][y]->v_axe != NULL && pix->obj[x][y]->height > 0) // C'est un cylindre
					intersect_cylinder(pix->obj[x][y], shadow_ray, hit); */
				
				if (hit->t1 > 0 && hit->t1 < distance_to_light)
					in_shadow = 1;
				else if (hit->t2 > 0 && hit->t2 < distance_to_light)
					in_shadow = 1;
				
				free(hit);
			}
			y++;
		}
		x++;
	}
	
	free(shadow_ray);
	free(light_vector);
	free(offset_point);
	
	return in_shadow;
}

// Modifier la fonction lighting

/*
* La fonction lighting calcule la couleur finale d'un point sur une surface
* en combinant les contributions ambiante, diffuse et spéculaire.
*
* Paramètres :
*   object_color  : la couleur de base de l'objet (par exemple, s_obj->color)
*   ambient_light : la lumière ambiante (généralement uniforme dans la scène)
*   point_light   : la source de lumière ponctuelle (avec position et intensité)
*   point         : le point d'intersection sur la surface
*   eyev          : le vecteur pointant vers la caméra
*   normalv       : le vecteur normal à la surface au point d'intersection
*   pix           : le pixel actuel (nécessaire pour la détection d'ombres)
*
* Pour debug, des printf() affichent les valeurs intermédiaires.
*/
t_color *lighting(t_color *object_color, t_light *ambient_light, t_light *point_light,
				t_coord *point, t_coord *eyev, t_coord *normalv, t_pix *pix)
{
	float ambient_coeff  = ambient_light->ratio;
	float diffuse_coeff  = 0.9;
	float specular_coeff = 0.9;
	float shininess      = 200.0;

	t_color *effective_color = color_mult(object_color, point_light->color);
	printf("[Lighting] effective_color: (%f, %f, %f)\n",
			effective_color->r, effective_color->g, effective_color->b);

	t_coord *lightv = vec_sub(point_light->p_coord, point);
	vec_normalize(lightv);
	printf("[Lighting] lightv (normalized): (%f, %f, %f)\n",
			lightv->x, lightv->y, lightv->z);

	t_color *ambient = color_scale(effective_color, ambient_coeff);
	printf("[Lighting] ambient: (%f, %f, %f)\n",
			ambient->r, ambient->g, ambient->b);

	float light_dot_normal = vec_dot(lightv, normalv);
	printf("[Lighting] normalv: (%f, %f, %f)\n", normalv->x, normalv->y, normalv->z);

	t_color *diffuse;
	t_color *specular;
	
	// Vérification des ombres
	int shadowed = is_shadowed(pix, point, point_light);
	
	// Si le point est dans l'ombre ou si la lumière est derrière la surface
	if (shadowed || light_dot_normal < -0.01)
	{
		diffuse = color_new(0, 0, 0);
		specular = color_new(0, 0, 0);
		if (light_dot_normal < 0)
			printf("[Lighting] light_dot_normal < 0, diffuse et specular = black\n");
		else
			printf("[Lighting] Point in shadow, diffuse et specular = black\n");
	}
	else
	{
		diffuse = color_scale(effective_color,
					diffuse_coeff * light_dot_normal * point_light->ratio);
		printf("[Lighting] diffuse: (%f, %f, %f)\n",
				diffuse->r, diffuse->g, diffuse->b);
	
		t_coord *neg_lightv = negat(lightv);
		t_coord *reflectv = reflect(neg_lightv, normalv);
		free(neg_lightv);
		printf("[Lighting] reflectv: (%f, %f, %f)\n",
				reflectv->x, reflectv->y, reflectv->z);
	
		float reflect_dot_eye = vec_dot(reflectv, eyev);
		printf("[Lighting] reflect_dot_eye: %f\n", reflect_dot_eye);
		if (reflect_dot_eye <= 0)
		{
			specular = color_new(0, 0, 0);
			printf("[Lighting] reflect_dot_eye <= 0, specular = black\n");
		}
		else
		{
			float factor = pow(reflect_dot_eye, shininess);
			specular = color_scale(point_light->color,
					specular_coeff * factor * point_light->ratio);
			printf("[Lighting] specular: (%f, %f, %f)\n",
					specular->r, specular->g, specular->b);
		}
		free(reflectv);
	}

	t_color *result = color_add(ambient, color_add(diffuse, specular));
	printf("[Lighting] result: (%f, %f, %f)\n",
			result->r, result->g, result->b);

	free(effective_color);
	free(ambient);
	free(diffuse);
	free(specular);
	free(lightv);

	return result;
}

int test_light(void)
{
	test_reflect_45();
	test_reflect_slanted();
	printf("All reflect tests passed.\n");
	return 0;
}

static float clamp(float value)
{
	if (value < 0.0f)
		return 0.0f;
	if (value > 255.0f)
		return 255.0f;
	return value;
}

/*
* main_light est appelée dans le raytracing pour appliquer l'éclairage
* sur chaque pixel. Ici, lorsqu'un pixel possède une intersection (p_point),
* une normale (v_norm_parral) et un vecteur œil (v_eye), on utilise la fonction
* lighting pour calculer la couleur finale selon le modèle Phong.
*
* On suppose que la source de lumière complète est stockée dans
* pix[0][0]->lux[1][0] et que la lumière ambiante reste dans pix[0][0]->lux[0][0].
*/
void main_light(t_pix ***pix)
{
	int x, y;
	// Récupération des deux lumières enregistrées depuis le fichier .rt :
	t_light *ambient_light = pix[0][0]->lux[0][0];
	t_light *point_light   = pix[0][0]->lux[1][0];
	printf("[main_light] Ambient light: (%f, %f, %f), ratio: %f\n",
		ambient_light->p_coord->x, ambient_light->p_coord->y, ambient_light->p_coord->z, ambient_light->ratio);
	printf("[main_light] Spotlight light: (%f, %f, %f), ratio: %f\n",
		point_light->p_coord->x, point_light->p_coord->y, point_light->p_coord->z, point_light->ratio);

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps &&
				pix[x][y]->comps->p_point &&
				pix[x][y]->comps->v_eye &&
				pix[x][y]->comps->v_norm_parral)
			{
				printf("[main_light] Pixel (%d, %d) -> Appel de lighting\n", x, y);
				// Ajout du paramètre pix[x][y] pour la détection d'ombres
				t_color *new_color = lighting(
					pix[x][y]->color,                  // couleur de l'objet
					ambient_light,                     // lumière ambiante (A)
					point_light,                       // lumière complète (L)
					pix[x][y]->comps->p_point,         // point d'intersection
					pix[x][y]->comps->v_eye,           // vecteur vers la caméra
					pix[x][y]->comps->v_norm_parral,   // vecteur normal à la surface
					pix[x][y]                          // pixel pour la détection d'ombres
				);
				printf("[main_light] Pixel (%d, %d) -> new_color: (%f, %f, %f)\n",
					x, y, new_color->r, new_color->g, new_color->b);
				// Mise à jour de la couleur du pixel avec le résultat de lighting.
				pix[x][y]->color = new_color;
			}
			y++;
		}
		x++;
	}
}
