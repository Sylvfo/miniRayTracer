/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:31:47 by syl               #+#    #+#             */
/*   Updated: 2024/12/27 22:17:11 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

t_scene *init_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	scene->sphere = (t_sphere **)malloc(4 * sizeof(t_sphere *));

	scene->sphere[0] = malloc(sizeof(t_sphere));
	scene->sphere[0]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[0]->center->x = 400;
	scene->sphere[0]->center->y = 50;
	scene->sphere[0]->center->z = 1300;
	scene->sphere[0]->radius = 140;
	scene->sphere[0]->color = 7536700;

	scene->sphere[1] = malloc(sizeof(t_sphere));
	scene->sphere[1]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[1]->center->x = 200;
	scene->sphere[1]->center->y = 50;
	scene->sphere[1]->center->z = 1300;
	scene->sphere[1]->color = 7536700;
	scene->sphere[1]->radius = 140;

	scene->sphere[2] = malloc(sizeof(t_sphere));
	scene->sphere[2]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[2]->center->x = 0;
	scene->sphere[2]->center->y = 50;
	scene->sphere[2]->center->z = 1300;
	scene->sphere[2]->color = 7536700;
	scene->sphere[2]->radius = 140;

	scene->sphere[3] = malloc(sizeof(t_sphere));
	scene->sphere[3]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[3]->center->x = -200;
	scene->sphere[3]->center->y = 50;
	scene->sphere[3]->center->z = 1250;
	scene->sphere[3]->color = 7536700;
	scene->sphere[3]->radius = 140;

	scene->sphere[4] = malloc(sizeof(t_sphere));
	scene->sphere[4]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[4]->center->x = -400;
	scene->sphere[4]->center->y = 50;
	scene->sphere[4]->center->z = 1200;
	scene->sphere[4]->color = 7536700;
	scene->sphere[4]->radius = 140;

	scene->sphere[5] = malloc(sizeof(t_sphere));
	scene->sphere[5]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[5]->center->x = -500;
	scene->sphere[5]->center->y = -75;
	scene->sphere[5]->center->z = 1100;
	scene->sphere[5]->color = 7536700;
	scene->sphere[5]->radius = 160;

	scene->sphere[6] = malloc(sizeof(t_sphere));
	scene->sphere[6]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[6]->center->x = -530;
	scene->sphere[6]->center->y = -120;
	scene->sphere[6]->center->z = 960;
	scene->sphere[6]->color = 404040;
	scene->sphere[6]->radius = 20;

	scene->sphere[7] = malloc(sizeof(t_sphere));
	scene->sphere[7]->center = malloc(sizeof(t_3dpoint));
	scene->sphere[7]->center->x = -470;
	scene->sphere[7]->center->y = -120;
	scene->sphere[7]->center->z = 960;
	scene->sphere[7]->color = 404040;
	scene->sphere[7]->radius = 20;	

	scene->light1 = init_lights();

	scene->plane = malloc(sizeof(t_plane));
	scene->plane->point = malloc(sizeof(t_3dpoint));
	scene->plane->point->x = 5;
	scene->plane->point->y = 250;
	scene->plane->point->z = 5;
	scene->plane->normal = malloc(sizeof(t_vect3d));
	scene->plane->normal->x = 1;
	scene->plane->normal->y = 5;
	scene->plane->normal->z = 1;
	normalize_vector(scene->plane->normal);
	scene->plane->color = 0x65985c;

	
	scene->ambient_light_ratio = 0.4;
//	scene->ambient_light_color = 0.5;
	return (scene);
}
	
t_spotlight *init_lights(void)
{
	t_spotlight *light1;

	light1 = malloc(sizeof(t_spotlight));
	light1->coord = malloc(sizeof(t_3dpoint));
	light1->ratio = 0.9;
	light1->coord->x = -700;
	light1->coord->y = -50;
	light1->coord->z = 800;
	return (light1);
}
