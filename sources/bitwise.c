/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:32:29 by syl               #+#    #+#             */
/*   Updated: 2025/01/24 15:49:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "minirt.h"
# include "minirt.h"

//	color = 256 * 256 * red + 256 * green + blue;
unsigned int modify_color(int color, float intensity)
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int colorback;
	
	red = (color >> 16)&255;
	green = (color >> 8)&255;
	blue = color&255;

	colorback = 0;
	red *= (1 - intensity);
	green *= (1 - intensity);
	blue *= (1 - intensity);

	colorback += (red << 16);
	colorback += (green << 8);
	colorback += blue;
//	if (colorback == 0xffffff)
//		return (0);
	
//	return (0xffffff);
	return (colorback);
}

int modify_color_rgb(int color)
{
	color -= 90;
	color += 256 *37;
	color += 256 * 256 * 119; 

	return (color);
}