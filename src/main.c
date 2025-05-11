/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:30:46 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 20:41:24 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

void	error_exit(const char *msg, t_pix ***pix, t_num_obj *num_obj)
{
	fprintf(stderr, "%s\n", msg);
	free_all(pix, WND_HEIGHT, WND_WIDTH, num_obj);
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
	//free_all(pix, WND_HEIGHT, WND_WIDTH, num_obj);
	return (EXIT_SUCCESS);
}
