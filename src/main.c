/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 14:28:46 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/05/11 12:46:25 by syl              ###   ########.fr       */
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




void	error_exit(const char *msg, t_program_context *context)
{
	fprintf(stderr, "%s\n", msg);
	if (context)
	{
		if (context->pix || context->num_obj)
			free_all(context->pix, context->width,
				context->height, context->num_obj);
		context->pix = NULL;
		context->num_obj = NULL;
		if (context->mlx_ptr && context->mlx_win)
			mlx_destroy_window(context->mlx_ptr, context->mlx_win);
		free(context);
		context = NULL;
	}
	exit(EXIT_FAILURE);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <scene_file.rt>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
	{
		printf("Error: Invalid file extension. Expected .rt\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_program_context	*context;

	if (check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	context = malloc(sizeof(t_program_context));
	if (!context)
	{
		perror("Failed to allocate memory for program context");
		return (EXIT_FAILURE);
	}
	ft_bzero(context, sizeof(t_program_context));
	context->num_obj = malloc(sizeof(t_num_obj));
	if (!context->num_obj)
	{
		perror("Failed to allocate memory for num_obj");
		error_exit(NULL, context);
	}
	ft_bzero(context->num_obj, sizeof(t_num_obj));
	parse_scene_file(argv[1], NULL, context);
	context->pix = init_data(context->num_obj);
	if (!context->pix)
	{
		perror("Failed to initialize pixel data");
		error_exit(NULL, context);
	}
	context->width = WND_WIDTH;
	context->height = WND_HEIGHT;
	context->ima = context->pix[0][0]->ima;
	context->mlx_ptr = context->ima->mlx_ptr;
	context->mlx_win = context->ima->mlx_win;
	save_scene_file(argv[1], context);
	print_camera(context->pix);
	print_spheres(context->pix, context->num_obj);
	print_planes(context->pix, context->num_obj);
	print_cylinders(context->pix, context->num_obj);
	print_lights(context->pix, context->num_obj);
//	exit(0);
	raytracing(context->pix);
	pix_to_window(context->pix);
	image_hooks(context);
	return (EXIT_SUCCESS);
}

/*int	main(int argc, char **argv)
{
	t_pix		***pix;
	t_num_obj	*num_obj;

	if (check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	pix = NULL;
	num_obj = malloc(sizeof(t_num_obj));
	if (!num_obj)
	{
		perror("Failed to allocate memory for num_obj");
		return (EXIT_FAILURE);
	}
	ft_bzero(num_obj, sizeof(t_num_obj));
	parse_scene_file(argv[1], NULL, num_obj);
	pix = init_data(num_obj);
	save_scene_file(argv[1], pix, num_obj);
	raytracing(pix);
	pix_to_window(pix);
	image_hooks(pix[0][0]->ima);
	free_all(pix, WND_HEIGHT, WND_WIDTH, num_obj);
	return (EXIT_SUCCESS);
}*/
