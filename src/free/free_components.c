/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:20:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 16:40:16 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_obj(t_obj *obj)
{
	if (!obj)
		return ;
	free_coord(obj->p_coord);
	free_coord(obj->v_axe);
	free_color(obj->color);
	free(obj);
}

void	free_obj_array(t_obj **objs)
{
	int	i;

	if (!objs)
		return ;
	i = 0;
	while (objs[i])
	{
		free_obj(objs[i]);
		i++;
	}
	free(objs);
}
