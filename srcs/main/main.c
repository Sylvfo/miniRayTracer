/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:36:51 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/02 22:09:29 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	print_spheres(t_pix ***pix, t_num_obj *num_obj)
{
	for (int i = 0; i < num_obj->sphere; i++)
	{
		printf("Sphere %d:\n", i + 1);
		printf("  Position: (%f, %f, %f)\n", (*pix)[0][0].obj[1][i]->p_coord->x, (*pix)[0][0].obj[1][i]->p_coord->y, (*pix)[0][0].obj[1][i]->p_coord->z);
		printf("  Diameter: %f\n", (*pix)[0][0].obj[1][i]->diam);
		printf("  Color: (%f, %f, %f)\n", (*pix)[0][0].obj[1][i]->color->r, (*pix)[0][0].obj[1][i]->color->g, (*pix)[0][0].obj[1][i]->color->b);
	}
}

void	print_planes(t_pix ***pix, t_num_obj *num_obj)
{
	for (int i = 0; i < num_obj->plan; i++)
	{
		printf("Plane %d:\n", i + 1);
		printf("  Position: (%f, %f, %f)\n", (*pix)[0][0].obj[2][i]->p_coord->x, (*pix)[0][0].obj[2][i]->p_coord->y, (*pix)[0][0].obj[2][i]->p_coord->z);
		printf("  Orientation: (%f, %f, %f)\n", (*pix)[0][0].obj[2][i]->v_axe->x, (*pix)[0][0].obj[2][i]->v_axe->y, (*pix)[0][0].obj[2][i]->v_axe->z);
		printf("  Color: (%f, %f, %f)\n", (*pix)[0][0].obj[2][i]->color->r, (*pix)[0][0].obj[2][i]->color->g, (*pix)[0][0].obj[2][i]->color->b);
	}
}

void	print_cylinders(t_pix ***pix, t_num_obj *num_obj)
{
	for (int i = 0; i < num_obj->cylinder; i++)
	{
		printf("Cylinder %d:\n", i + 1);
		printf("  Position: (%f, %f, %f)\n", (*pix)[0][0].obj[3][i]->p_coord->x, (*pix)[0][0].obj[3][i]->p_coord->y, (*pix)[0][0].obj[3][i]->p_coord->z);
		printf("  Orientation: (%f, %f, %f)\n", (*pix)[0][0].obj[3][i]->v_axe->x, (*pix)[0][0].obj[3][i]->v_axe->y, (*pix)[0][0].obj[3][i]->v_axe->z);
		printf("  Diameter: %f\n", (*pix)[0][0].obj[3][i]->diam);
		printf("  Height: %f\n", (*pix)[0][0].obj[3][i]->height);
		printf("  Color: (%f, %f, %f)\n", (*pix)[0][0].obj[3][i]->color->r, (*pix)[0][0].obj[3][i]->color->g, (*pix)[0][0].obj[3][i]->color->b);
	}
}

void	print_lights(t_pix ***pix, t_num_obj *num_obj)
{
	printf("Ambient Light:\n");
	printf("  Ratio: %f\n", (*pix)[0]->lux[0][0]->ratio);
	printf("  Color: (%f, %f, %f)\n", (*pix)[0]->lux[0][0]->color->r, (*pix)[0]->lux[0][0]->color->g, (*pix)[0]->lux[0][0]->color->b);

	for (int i = 0; i < num_obj->light; i++)
	{
		printf("Light %d:\n", i + 1);
		printf("  Position: (%f, %f, %f)\n", (*pix)[0]->lux[1][i]->p_coord->x, (*pix)[0]->lux[1][i]->p_coord->y, (*pix)[0]->lux[1][i]->p_coord->z);
		printf("  Ratio: %f\n", (*pix)[0]->lux[1][i]->ratio);
		printf("  Color: (%f, %f, %f)\n", (*pix)[0]->lux[1][i]->color->r, (*pix)[0]->lux[1][i]->color->g, (*pix)[0]->lux[1][i]->color->b);
	}
}

void	print_camera(t_pix ***pix)
{
	printf("Camera:\n");
	printf("  Position: (%f, %f, %f)\n", (*pix)[0][0].cam->p_coord->x, (*pix)[0][0].cam->p_coord->y, (*pix)[0][0].cam->p_coord->z);
	printf("  Orientation: (%f, %f, %f)\n", (*pix)[0][0].cam->v_axe->x, (*pix)[0][0].cam->v_axe->y, (*pix)[0][0].cam->v_axe->z);
	printf("  FOV: %f\n", (*pix)[0][0].cam->fov);
}

int	main(int argc, char **argv)
{
	t_pix		***pix;
	t_num_obj	*num_obj;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file.rt>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	num_obj = malloc(sizeof(t_num_obj));
	if (!num_obj)
	{
		perror("Failed to allocate memory for num_obj");
		return (EXIT_FAILURE);
	}
	// Allocate memory for pix
	pix = malloc(sizeof(t_pix **));
	if (!pix)
	{
		perror("Failed to allocate memory for pix");
		free(num_obj);
		return (EXIT_FAILURE);
	}
	*pix = NULL;
	parse_scene_file(argv[1], pix, num_obj, "parsing");
	if (init_data(pix, num_obj) == false)
	{
		free_all(pix);
		free(num_obj);
		return (EXIT_FAILURE);
	}
	num_obj->sphere = 0;
	num_obj->plan = 0;
	num_obj->cylinder = 0;
	num_obj->light = 0;
	parse_scene_file(argv[1], pix, num_obj, "saving");
	print_camera(pix);
	print_spheres(pix, num_obj);
	print_planes(pix, num_obj);
	print_cylinders(pix, num_obj);
	print_lights(pix, num_obj);
	free(num_obj);
	free_all(pix);
	return (EXIT_SUCCESS);
}
