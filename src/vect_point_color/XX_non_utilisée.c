/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   XX_non_utilisée.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:53:08 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 17:20:37 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "minirt_data_struct.h"

/**
 * @brief to know the opposit of a vector
 * 
 * @param v a vector
 * 
 * @return new vector
 */
/*
t_coord *negat(t_coord *v)
{
    t_coord *result = malloc(sizeof(t_coord));
    if (!result)
        return NULL;
    result->x = -v->x;
    result->y = -v->y;
    result->z = -v->z;
    result->t = v->t; // conserver le type ou autre information
    return result;
}*/

/**
 * @brief cross product
 * 
 * You get a new vector that is perpendicular to both of the original vectors.
 * order is important
 * 
 * @param v_1 a vector
 * @param v_2 an other vector
 * 
 * @return new vector
 */
/*
t_coord	*cross_product(t_coord *v_1, t_coord *v_2)
{
	t_coord	*v_new;

	v_new = malloc(sizeof(t_coord));
	if (!v_new)
		return (NULL);
	if (is_vector(v_1) == false || is_vector(v_2) == false)
		return (0);
	v_new->x = (v_1->y * v_2->z) - (v_1->z * v_2->y);
	v_new->y = (v_1->z * v_2->x) - (v_1->x * v_2->z);
	v_new->z = (v_1->x * v_2->y) - (v_1->y * v_2->x);
	return (v_new);
}*/



/**
 * @brief normalize a vector
 * 
 * @param v_1 a vector
 * 
 * @return unit vector
 */
/*
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
}*/

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
/*t_coord	*scalar_mult(t_coord *v_1, float scale)
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
}*/

/* pareil mais malloc
t_color *multipling_color(t_color *c_1, t_color *c_2)
{
	t_color *c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = c_1->r * c_2->r;
	c_newcolor->g = c_1->g * c_2->g;
	c_newcolor->b = c_1->b * c_2->b;
	return (c_newcolor);	
}
*/

//pareil mais malloc....
/*
t_color *scalar_mult_color(t_color *c_1, float scale) 
{
	t_color *c_newcolor;

// check size scale...not neg, not too big...
	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = scale * c_1->r;
	c_newcolor->g = scale * c_1->g;
	c_newcolor->b = scale * c_1->b;
	free (c_1);///A VOIR...
	return (c_newcolor);
}
*/