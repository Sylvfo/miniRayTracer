/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:10:28 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 09:40:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// a voir si c est bien de faire comme ça. 
float	*create_indentity_matrix_44(void)
{
	float	*m_identity;

	m_identity = create_matrix(4, 4);
	matrix_fill(m_identity, 0, 0, 1);
	matrix_fill(m_identity, 1, 1, 1);
	matrix_fill(m_identity, 2, 2, 1);
	matrix_fill(m_identity, 3, 3, 1);
	return (m_identity);
}
