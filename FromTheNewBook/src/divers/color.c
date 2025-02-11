/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:00:02 by sforster          #+#    #+#             */
/*   Updated: 2025/02/11 18:01:28 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
Scenario: Colors are (red, green, blue) tuples
Given c ← color(-0.5, 0.4, 1.7)
Then c.red = -0.5
And c.green = 0.4
And c.blue = 1.7
*/


//	s_coord p_exemplepoint;
//	s_coord v_exemplevector;
//	s_coord vn_exemplenormedvector;
//	t_color c_exemplecolor;


/**
 * @brief create a new color
 * 
 * NOT VERIFIED
 * 
 * @param r red
 * @param g green
 * @param b blue
 * 
 * @return new color
 */
t_color *coloring(float r, float g, float b)
{
	// si plus grand que 255?? plus petit que zero??
	t_color *c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = r;
	c_newcolor->g = g;
	c_newcolor->b = b;

	return(c_newcolor);
}

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
t_color *substraction_color(t_color *c_1, t_color *c_2)
{
	t_color *c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = c_1->r - c_2->r;
	c_newcolor->g = c_1->g - c_2->g;
	c_newcolor->b = c_1->b - c_2->b;
	return (c_newcolor);	
}

/**
 * @brief to scale a color 
 * 
 * 0.5 to make it half
 * 
 * NOT VERIFIED
 * 
 * @param c_1 a color
 * @param scale
 * 
 * @return new vector
 */
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
	return (c_newcolor);
}


/**
 * @brief multiply 2 colors
 * 
 * Hadamard product (or Schur product)
 * 	NOT VERIFIED
 * 
 * @param c_1 first color
 * @param c_2 secondc color
 * 
 * @return new color
 */
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
