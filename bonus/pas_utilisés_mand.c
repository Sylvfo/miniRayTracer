/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pas_utilisés_mand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:26:24 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 10:49:05 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//	s_coord p_exemplepoint;
//	s_coord v_exemplevector;
//	s_coord vn_exemplenormedvector;
//	t_color c_exemplecolor;

/**
 * @brief add 2 colors
 * 
 * 	NOT VERIFIED
 * 
 * @param c_1 first color
 * @param c_2 second color
 * 
 * @return new color
 */
void	addition_color(t_color *c_1, t_color *c_2)
{
	c_1->r += c_2->r;
	c_1->g += c_2->g;
	c_1->b += c_2->b;
}
/*
t_color *addition_color(t_color *c_1, t_color *c_2)
{
	t_color *c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = c_1->r + c_2->r;
	c_newcolor->g = c_1->g + c_2->g;
	c_newcolor->b = c_1->b + c_2->b;
	return (c_newcolor);	
}
*/

/**
 * @brief subtr 2 colors
 * 
 * 	NOT VERIFIED
 * 
 * @param c_1 first color
 * @param c_2 second color
 * 
 * @return new color
 */
t_color	*substraction_color(t_color *c_1, t_color *c_2)
{
	t_color	*c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = c_1->r - c_2->r;
	c_newcolor->g = c_1->g - c_2->g;
	c_newcolor->b = c_1->b - c_2->b;
	return (c_newcolor);
}


/**
 * @brief multiply 2 colors
 * 
 * Hadamard product (or Schur product)
 * 	NOT VERIFIED -FONCTIONNE PAS?????
 * 
 * @param c_1 first color
 * @param c_2 secondc color
 * 
 * @return 
 */
void	multipling_color(t_color *c_1, t_color *c_2)
{
	if (!c_1 || !c_2)
	{
		printf("miss a colour \n");
		return ;
	}
	c_1->r *= c_2->r;
	c_1->g *= c_2->g;
	c_1->b *= c_2->b;
	color_float_to_int(c_1);
}

/**
 * @brief convert float to byte
 * 
 * when calculation is done
 * goes with color_float_to_int(t_color *c_color)
 * 
 * NOT VERIFIED
 * 
 * @param f float
 * 
 * @return --- change in data base pix
 */
/*
COPIE AVEC VALEUR RGB 0 a 1
int	float_to_byte(float f)
{
	if (f <= 0.0f)
		return (0);
	if (f >= 1.0f)
		return (255);
	return ((int)(f * 255.0f + 0.5f));
}*/