/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:36:21 by syl               #+#    #+#             */
/*   Updated: 2025/02/06 17:20:48 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minirt.h"

/*
typedef	struct s_3Dcoord {
	float x;
	float y;
	float z;
	int	t;// type 0 for vector and 1 for point. //w like in the book?
}	t_3Dcoord;
*/

void print3dvect(t_3Dcoord va)
{
	printf("vx %f, vy %f, vz %f\n", va->x, va->y, va->z);
}

