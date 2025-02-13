/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:36:51 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/12 09:36:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <scene_file.rt>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	parse_scene_file(argv[1]);
	return (EXIT_SUCCESS);
}
