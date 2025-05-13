/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:41 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/13 14:36:02 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

static void	init_obj_matrix_fields(t_obj *obj)
{
	obj->m_transl = create_indentity_matrix_44();
	obj->m_transf = create_indentity_matrix_44();
	obj->m_inv = create_matrix(4, 4);
	obj->m_scale = create_indentity_matrix_44();
	obj->m_rot = create_indentity_matrix_44();
	obj->from = create_vector(0, 1, 0);
	obj->v_axe_r = create_vector(0, 0, 0);
	obj->v_sph_camera = create_vector(0, 0, 0);
	obj->closed_up = true;
	obj->closed_down = true;
}

bool	init_obj_matrices(t_obj ***obj)
{
	int	a;
	int	b;

	a = 1;
	obj[0][0]->m_transf = create_indentity_matrix_44();
	while (obj[a] != NULL)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
			init_obj_matrix_fields(obj[a][b]);
			if (a == 3)
				obj[a][b]->p_coord->z = 0;
			b++;
		}
		a++;
	}
	return (true);
}
