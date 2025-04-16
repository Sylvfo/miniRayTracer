/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:51:07 by syl               #+#    #+#             */
/*   Updated: 2025/04/16 18:02:42 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/// les trois fonctions ici ont été faites pour les testes. 
// tout ca c est testé c est bon =).

//pas utilisée pour l instant
float	*create_translation_matrix(float x, float y, float z)
{
	float	*m_transl;

	m_transl = create_indentity_matrix_44();
	if (!m_transl)
		return (NULL);
	matrix_fill(m_transl, 0, 3, x);
	matrix_fill(m_transl, 1, 3, y);
	matrix_fill(m_transl, 2, 3, z);
	matrix_fill(m_transl, 3, 3, 1);
	return (m_transl);
}

//pas utilisée pour l instant
t_coord	*translation(t_coord *p_point, float x, float y, float z)
{
	float	*m_transl;
	t_coord	*p_newpoint;

	m_transl = create_translation_matrix(x, y, z);
	if (!m_transl)
		return (NULL);
	p_newpoint = matrix_multiplication_44_coord(m_transl, p_point);
	return (p_newpoint);
}

//pas utilisée pour l instant
t_coord	*translation_inverse(t_coord *p_point, float x, float y, float z)
{
	float	*m_transl;
	t_coord	*p_newpoint;

	m_transl = create_translation_matrix(x, y, z);
	m_transl = inverted_matrix_44(m_transl);
	if (!m_transl)
		return (NULL);
	p_newpoint = matrix_multiplication_44_coord(m_transl, p_point);
	return (p_newpoint);
}

//////////////////// ca c est fait au début du raytracing pour la matrice de chaque forme
// ah finalement non
void translation_on_identity(float *m_identity, float x, float y, float z)
{
	matrix_fill(m_identity, 0, 3, x);
	matrix_fill(m_identity, 1, 3, y);
	matrix_fill(m_identity, 2, 3, z);
	matrix_fill(m_identity, 3, 3, 1);
}
