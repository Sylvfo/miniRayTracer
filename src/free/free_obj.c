/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:33:36 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 14:54:12 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Libère une structure t_obj et tous ses champs dynamiquement alloués.
*/
void	free_obj(t_obj *obj)
{
	if (!obj)
		return ;
	free(obj->p_coord);
	free(obj->color);
	free(obj->v_axe);
	free(obj->m_transl);
	free(obj->m_rot);
	free(obj->m_scale);
	free(obj->m_transf);
	free(obj->m_inv);
	free(obj->v_axe_r);
	free(obj->from);
	free(obj->v_sph_camera);
	free(obj);
}
