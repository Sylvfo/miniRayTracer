/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:34:12 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 13:38:24 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static bool	init_obj_background(t_obj ***obj)
{
	if (!init_obj_struct(&obj[0][0], false))
		return (false);
	obj[0][1] = NULL;
	return (true);
}

static bool	init_obj_spheres(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!init_obj_struct(&obj[1][i], false))
			return (false);
		i++;
	}
	obj[1][count] = NULL;
	return (true);
}

static bool	init_obj_plans(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!init_obj_struct(&obj[2][i], true))
			return (false);
		i++;
	}
	obj[2][count] = NULL;
	return (true);
}

static bool	init_obj_cylinders(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!init_obj_struct(&obj[3][i], true))
			return (false);
		i++;
	}
	obj[3][count] = NULL;
	return (true);
}

bool	initialize_object_arrays(t_obj ***obj, t_num_obj *num_obj)
{
	if (!init_obj_background(obj))
		return (false);
	if (!init_obj_spheres(obj, num_obj->sphere))
		return (false);
	if (!init_obj_plans(obj, num_obj->plan))
		return (false);
	if (!init_obj_cylinders(obj, num_obj->cylinder))
		return (false);
	obj[4] = NULL;
	return (true);
}
