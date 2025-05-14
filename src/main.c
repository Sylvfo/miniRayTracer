/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 22:31:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

void	error_exit(const char *msg, t_program_context *context)
{
	fprintf(stderr, "%s\n", msg);
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
	raytracing(context->pix);
	pix_to_window(context->pix);
	image_hooks(context);
	new_free(context->pix);
//	free_all(context);
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
