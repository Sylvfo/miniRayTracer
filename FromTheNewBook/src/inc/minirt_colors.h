/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_colors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:22 by sforster          #+#    #+#             */
/*   Updated: 2025/02/11 17:46:58 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_COLOR_H
# define MINIRT_COLOR_H

typedef struct s_color{
	float r;
	float g;
	float b;
} t_color;

/*
If a color is especially bright
or dark somewhere in your scene, it may go through multiple transformations
before reaching your virtual “eye,” dropping it to less than 0 or increasing it
to greater than 1 at any point along the way. Limiting the color prematurely
can make parts of your scene too bright or dark in the final image.

typedef struct s_color{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} t_color;
*/

# endif
