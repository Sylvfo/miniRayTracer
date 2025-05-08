/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/05/08 17:41:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"


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

void	error_exit(const char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_pix		***pix;
	t_num_obj	*num_obj;
	
	pix = NULL;

	if (argc != 2)
	{
		printf("Usage:s %s <scene_file.rt>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	num_obj = malloc(sizeof(t_num_obj));
	if (!num_obj)
	{
		perror("Failed to allocate memory for num_obj");
		return (EXIT_FAILURE);
	}
	parse_scene_file(argv[1], num_obj);
	pix = init_data(num_obj);
	save_scene_file(argv[1], pix, num_obj);
////////////////////////////////
/*	print_camera(pix);
	print_spheres(pix, num_obj);
	print_planes(pix, num_obj);
	print_cylinders(pix, num_obj);
	print_lights(pix, num_obj);*/
////////////////////////////////
/*	float *m_test = create_matrix(4,4);
	print_matrix(m_test);
	matrix_fill(m_test, 0, 1, 1);
	matrix_fill(m_test, 0, 2, 2);
	matrix_fill(m_test, 0, 3, 3);
	matrix_fill(m_test, 1, 0, 4);
	print_matrix_44(m_test);
	float *test_id = create_indentity_matrix_44();
	print_matrix_44(test_id);
	float *test_scale = create_matrix(4, 4);
	create_scaling_matrix_NA(test_scale, 22, 23, 24);
	print_matrix_44(test_scale);
	float *test_transl = create_matrix(4, 4);
	fill_translation_matrix(test_transl, 72,73,74);
	print_matrix_44(test_transl);
	float *test_rot = create_matrix(4, 4);
	fill_translation_matrix(test_rot, 20);
	print_matrix_44(test_rot);
	exit(0);*/
////////////////////////////////////////
	raytracing(pix);
//	printf("calculs done\n");
//	printf("\n\nici pix  ");
/*	print_point(pix[100][50]->r_original->p_origin);
	printf("\nici dire  ");
	print_vector(pix[100][50]->r_original->v_dir);

	printf("\n\nici pix  ");
	print_point(pix[0][0]->r_original->p_origin);
	printf("\nici dire  ");
	print_vector(pix[0][0]->r_original->v_dir);

	printf("\n\nici pix  ");
	print_point(pix[100][50]->r_original->p_origin);
	printf("\nici dire  ");*/

//	test_normal_at();

//	pix_drawings(pix);
	pix_to_window(pix);
	image_hooks(pix[0][0]->ima);
//////////////////////////////
//	test_camera3();
//	test_normal_at(pix);
	return (EXIT_SUCCESS);
}

/*
void pix_drawings(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (y < 400)
			{
				pix[x][y]->color->r = 1;
				pix[x][y]->color->g = 0;
				pix[x][y]->color->b = 0;
			}	
			else
			{
				pix[x][y]->color->r = 0;
				pix[x][y]->color->g = 1;
				pix[x][y]->color->b = 0;
			}	
		//	color_float_to_int(pix[x][y]->color);
			y++;
		}
		x++;
	}	
}*/

