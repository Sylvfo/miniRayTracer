/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:00:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 12:02:41 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Fonctions d'assistance déjà définies dans free_all.c (ou à rendre globales si nécessaire)
// static void free_coord(t_coord *coord);
// static void free_color(t_color *color);

static void	free_single_light(t_light *light_ptr)
{
	if (!light_ptr)
		return;
	if (light_ptr->p_coord)
	{
		free(light_ptr->p_coord);
		light_ptr->p_coord = NULL;
	}
	if (light_ptr->color)
	{
		free(light_ptr->color);
		light_ptr->color = NULL;
	}
	free(light_ptr);
}

static void	free_ambient_light(t_light ***light_struct)
{
	// light_struct[0] est pour la lumière ambiante, qui est light_struct[0][0]
	if (light_struct && light_struct[0] && light_struct[0][0])
	{
		free_single_light(light_struct[0][0]);
		light_struct[0][0] = NULL; // Le pointeur dans le tableau
	}
	if (light_struct && light_struct[0])
	{
		free(light_struct[0]); // Libère le tableau t_light** pour la lumière ambiante
		light_struct[0] = NULL;
	}
}

static void	free_spotlights_array(t_light ***light_struct, int count)
{
	// light_struct[1] est pour les spotlights
	if (light_struct && light_struct[1])
	{
		for (int i = 0; i < count; i++)
		{
			if (light_struct[1][i])
			{
				free_single_light(light_struct[1][i]);
				light_struct[1][i] = NULL;
			}
		}
		free(light_struct[1]); // Libère le tableau t_light** pour les spotlights
		light_struct[1] = NULL;
	}
}

void	free_light_all(t_light ***light_struct, t_num_obj *num_obj)
{
	if (!light_struct || !num_obj)
		return;

	// Libérer la lumière ambiante (light_struct[0])
	free_ambient_light(light_struct);

	// Libérer les spotlights (light_struct[1])
	free_spotlights_array(light_struct, num_obj->light);

	// Libérer la structure principale t_light***
	free(light_struct);
}
