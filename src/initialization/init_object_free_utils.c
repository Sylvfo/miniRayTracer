/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_free_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:45:07 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 10:45:11 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_and_null(void **ptr_addr)
{
	if (ptr_addr && *ptr_addr)
	{
		free(*ptr_addr);
		*ptr_addr = NULL;
	}
}

void	clear_obj_members(t_obj *obj_ptr)
{
	if (!obj_ptr)
		return ;
	free_and_null((void **)&obj_ptr->p_coord);
	free_and_null((void **)&obj_ptr->color);
	free_and_null((void **)&obj_ptr->v_axe);
	free_and_null((void **)&obj_ptr->m_transl);
	free_and_null((void **)&obj_ptr->m_rot);
	free_and_null((void **)&obj_ptr->m_scale);
	free_and_null((void **)&obj_ptr->m_transf);
	free_and_null((void **)&obj_ptr->m_inv);
	free_and_null((void **)&obj_ptr->v_axe_r);
	free_and_null((void **)&obj_ptr->from);
	free_and_null((void **)&obj_ptr->v_sph_camera);
}

void	free_obj_array_items(t_obj **obj_array, int count)
{
	int	i;

	i = 0;
	if (obj_array)
	{
		while (i < count && obj_array[i])
		{
			clear_obj_members(obj_array[i]);
			free_and_null((void **)&obj_array[i]);
			i++;
		}
		free(obj_array);
	}
}
