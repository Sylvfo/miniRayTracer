/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:57:13 by syl               #+#    #+#             */
/*   Updated: 2025/02/12 15:14:28 by syl              ###   ########.fr       */
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
t_color *create_color(int r, int g, int b)
{
	// si plus grand que 255?? plus petit que zero??
	t_color *c_newcolor;

	c_newcolor = malloc(sizeof(t_color));
	if (!c_newcolor)
		return (NULL);
	c_newcolor->r = int_to_float(r);
	c_newcolor->g = int_to_float(g);
	c_newcolor->b = int_to_float(b);
    c_newcolor->rgb = 0;

	return(c_newcolor);
}

/**
 * @brief create a new color
 * 
 * NOT VERIFIED
 * goes with
 * 
 * in float 0.0 to 1.0 (1 = 255)
 * 
 * @param r red int 0-255
 * @param g green 0-255
 * @param b blue 0-255
 * 
 * @return new color
 */
static float int_to_float(int value)
{
    if (value < 0)
        return (0.0f);
    if (value > 255)
        return (1.0f);
    return ((float)value / 255.0f);
}


/**
 * @brief convert float to int 24-bit RGB
 * 
 * after calcution
 * before put pix in image
 * 
 * NOT VERIFIED
 * 
 * @param c_color a pointer to a color
 * 
 * @return --- change in data base pix
 */
void    color_float_to_int(t_color *c_color)
{
    int r;
    int g;
    int b;

    /* Conversion des valeurs float (0-1.0) en entiers (0-255) */
    r = float_to_byte(c_color->r);
    g = float_to_byte(c_color->g);
    b = float_to_byte(c_color->b);

    /* Combine les composantes en un seul entier 24-bit RGB */
    c_color->rgb = (r << 16) | (g << 8) | b;
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
static int	float_to_byte(float f)
{
    if (f <= 0.0f)
        return (0);
    if (f >= 1.0f)
        return (255);
    return ((int)(f * 255.0f + 0.5f));
}