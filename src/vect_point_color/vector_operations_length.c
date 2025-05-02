/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_length.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:36:44 by syl               #+#    #+#             */
/*   Updated: 2025/05/02 16:16:49 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// check size scale...not neg, not too big...
/**
 * @brief to scale vector 
 * 
 * 0.5 to make it half
 * 
 * @param v_1 a vector
 * @param scale
 * 
 * @return new vector
 */
t_coord	*scalar_mult(t_coord *v_1, float scale)
{
	t_coord	*v_new;

	if (is_vector(v_1) == false)
		return (NULL);
	v_new = malloc(sizeof(t_coord));
	if (!v_new)
		return (NULL);
	v_new->x = scale * v_1->x;
	v_new->y = scale * v_1->y;
	v_new->z = scale * v_1->z;
	v_new->t = 0;
	return (v_new);
}

void	scalar_mult_NA(t_coord *result, t_coord *v_1, float scale)
{
	if (is_vector(v_1) == false)
		return ;
	result->x = scale * v_1->x;
	result->y = scale * v_1->y;
	result->z = scale * v_1->z;
	result->t = 0;
}


/**
 * @brief find the norm of a vector
 * 
 * the norm the lenght of a vector or its magnitude
 * A REVERIFIER
 * 
 * @param v_1 a vector
 * 
 * @return the norm of the vector 
 */
float	length_vector(t_coord *v_1)
{
	float	length;

	if (is_vector(v_1) == false)
		return (0);
	length = (float)sqrtf((v_1->x * v_1->x) + (v_1->y * v_1->y) + (v_1->z * v_1->z));
//	length = (float)simple_sqrt((v_1->x * v_1->x) + (v_1->y * v_1->y) + (v_1->z * v_1->z));
	return (length);
}

/**
 * @brief normalize a vector
 * 
 * @param v_1 a vector
 * 
 * @return unit vector
 */
t_coord	*normalize_vector(t_coord *v_1)
{
	t_coord	*v_new;
	t_coord *v_tmp;
	float	length;

	if (is_vector(v_1) == false)
	{
		printf("Error: Input is not a valid vector. A\n");
		return (NULL);
	}
	v_tmp = malloc(sizeof(t_coord));
	v_tmp->x = v_1->x;
	v_tmp->y = v_1->y;
	v_tmp->z = v_1->z;
	v_tmp->t = 0;
//	free(v_1);
	// Vérifier si l'entrée est un vecteur valide
	

	// Calculer la longueur du vecteur
	length = length_vector(v_tmp);
	if (length == 0)
	{
		printf("Error: Cannot normalize a zero-length vector. B\n");
		return (NULL);
	}
	// Allouer de la mémoire pour le vecteur normalisé
	v_new = malloc(sizeof(t_coord));
	if (!v_new)
	{
		printf("Error: Memory allocation failed in normalize_vector.\n");
		return (NULL);
	} 


	// Normaliser le vecteur
	length = 1.0f / length;
	v_new->x = v_tmp->x * length;
	v_new->y = v_tmp->y * length;
	v_new->z = v_tmp->z * length;
	v_new->t = 0; // Type vecteur

	// Log pour débogage
	//printf("Normalized Vector: x=%f, y=%f, z=%f\n", v_new->x, v_new->y, v_new->z);

	return (v_new);
}

void	normalize_vector_NA(t_coord *v_1)
{
	float	length;

	if (is_vector(v_1) == false)
	{
		printf("Error: Input is not a valid vector. in NA\n");
		return ;
	}
	length = length_vector(v_1);
	if (length == 0)
	{
		printf("Error: Cannot normalize a zero-length vector.\n");
		return ;
	}
	length = 1 / length;
	v_1->x = v_1->x * length;
	v_1->y = v_1->y * length;
	v_1->z = v_1->z * length;
	v_1->t = 0;
}
