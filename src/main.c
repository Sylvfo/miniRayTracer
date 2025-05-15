/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 11:53:25 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

void	error_exit(const char *msg, t_program_context *context)
{
	(void) context;
	printf("%s\n", msg);
	//free all
	exit(EXIT_FAILURE);
}

static int	check_args(int argc, char **argv)
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

static t_program_context	*init_context(void)
{
	t_program_context	*context;

	context = malloc(sizeof(t_program_context));
	if (!context)
	{
		perror("Failed to allocate memory for program context");
		return (NULL);
	}
	ft_bzero(context, sizeof(t_program_context));
	context->num_obj = malloc(sizeof(t_num_obj));
	if (!context->num_obj)
	{
		perror("Failed to allocate memory for num_obj");
		free(context);
		return (NULL);
	}
	ft_bzero(context->num_obj, sizeof(t_num_obj));
	return (context);
}

static void	setup_window_context(t_program_context *context)
{
	context->width = WND_WIDTH;
	context->height = WND_HEIGHT;
	context->ima = context->pix[0][0]->ima;
	context->mlx_ptr = context->ima->mlx_ptr;
	context->mlx_win = context->ima->mlx_win;
}

int	main(int argc, char **argv)
{
	t_program_context	*context;

	if (check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	context = init_context();
	if (!context)
		return (EXIT_FAILURE);
	parse_scene_file(argv[1], context);
	context->pix = init_data(context->num_obj);
	if (!context->pix)
		error_exit("Failed to initialize pixel data", context);
	setup_window_context(context);
	save_scene_file(argv[1], context);
	raytracing(context->pix);
	pix_to_window(context->pix);
	image_hooks(context);
//	free_all(context);
	return (EXIT_SUCCESS);
}
