/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/02/28 14:15:36 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

//Docstring

//	row = m_matrix[0];
//	col = m_matrix[1];
int	main(void)
{
	t_pix	***pix;
	(void)	pix;

	if (argc != 2)
	{
		printf("Usage: %s <scene_file.rt>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	parse_scene_file(argv[1]);
	if (init_data(pix) == false)
	{
		//freetoutca
		return (EXIT_FAILURE);
	}	

//	pix = parsing;

/*	pix = init_data_test();
	pix_drawings(pix);
	pix_to_window(pix);
	image_hooks(pix[0][0]->ima);*/

//	sphere_testing();
	return (0);
}
