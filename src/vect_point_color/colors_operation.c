/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:57:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 15:51:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief 
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
float	int_to_float(int value)
{
	if (value < 0)
		return (0.0f);
	if (value > 255)
		return (1.0f);
	return ((float)value / 255.0f);
}

/**
 * @brief convert float to byte
 * 
 * when calculation is done
 * goes with color_float_to_int(t_color *c_color)
 * 
 * A modifier rgb 0 a 1
 * 
 * @param f float
 * 
 * @return --- change in data base pix
 */
int	float_to_byte(float f)
{
	if (f <= 0.0f)
		return (0);
	if (f >= 255)
		return (255);
	return ((int)(f * 255));
}

/**
 * @brief convert float to int 24-bit RGB
 * 
 * after calcution
 * before put pix in image
 * 
 * NOT VERIFIED
 * 
 * Conversion des valeurs float (0-1.0) en entiers (0-255)
 * 
 * Combine les composantes en un seul entier 24-bit RGB
 * 
 * @param c_color a pointer to a color
 * 
 * @return --- change in data base pix
 */
void	color_float_to_int(t_color *c_color)
{
	int	r;
	int	g;
	int	b;

	if (!c_color)
		return ;
	r = float_to_byte(c_color->r);
	g = float_to_byte(c_color->g);
	b = float_to_byte(c_color->b);
	c_color->rgb = (r << 16) | (g << 8) | b;
}

void	color_int_to_rgb(int int_color, t_color *rgb)
{
	rgb->r = (int_color >> 16) & 0xFF;
	rgb->g = (int_color >> 8) & 0xFF;
	rgb->b = int_color & 0xFF;
	rgb->rgb = int_color;
	return ;
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
 * @return -- change in data base
 */
void	scalar_mult_color(t_color *c_1, float scale)
{
	if (scale < 0)
	{
		printf("negative scale \n");
		return ;
	}
	c_1->r *= scale;
	c_1->g *= scale;
	c_1->b *= scale;
	if (c_1->r > 1)
		c_1->r = 1;
	if (c_1->g > 1)
		c_1->g = 1;
	if (c_1->b > 1)
		c_1->b = 1;
}
