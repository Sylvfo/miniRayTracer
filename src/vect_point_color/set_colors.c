/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:50:21 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 10:56:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief create a new color
 * 
 * NOT VERIFIED
 * 
 * 
 * in float 0.0 to 1.0 (1 = 255)
 * 
 * @param r red int 0-255
 * @param g green 0-255
 * @param b blue 0-255
 * 
 * @return new color
 */
// si plus grand que 255?? plus petit que zero??
t_color	*create_color(int r, int g, int b)
{
	t_color	*c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = int_to_float(r);
	c_newcolor->g = int_to_float(g);
	c_newcolor->b = int_to_float(b);
	c_newcolor->rgb = 0;
	return (c_newcolor);
}

/**
 * @brief change the color already allocated
 * 
 * NOT VERIFIED
 * 
 * in float 0.0 to 1.0 (1 = 255)
 * 
 * @param r red int 0-255
 * @param g green 0-255
 * @param b blue 0-255
 * 
 * @return -- change in database
 */
void	change_color(t_color *c_color, int r, int g, int b)
{
	c_color->r = int_to_float(r);
	c_color->g = int_to_float(g);
	c_color->b = int_to_float(b);
	c_color->rgb = 0;
}
