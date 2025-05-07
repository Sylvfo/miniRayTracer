/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_intersect_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:38:19 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// si t1 et / ou t2 négatifs, c est que c est derrière la camera
void main_intersections(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			intersect_pix_obj(pix[x][y]);
			y++;
		}
		x++;
	}	
}

void intersect_pix_obj(t_pix *pix)
{
	int a;
	int b;

	a = 1;
	while(pix->obj[a] != NULL)
	{
		b = 0;
		while(pix->obj[a][b] != NULL)
		{
			if (a == 1)
				intersect_sphere(pix, b);
			if (a == 2)
				intersect_plan(pix, b);
			if (a == 3)
				intersect_cylinder(pix, b);
			b++;
		}
		a++;
	}
}




/*
void main_intersections(t_pix ***pix)
{
	int	x;
	int	y;
	int a;
	int b;

	//printf("enter intersect\n");
	a = 1;
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			b = 0;
			while(pix[x][y]->obj[1][b] != NULL)
			{
				intersect_sphere(pix[x][y], b);
				b++;
			}
			b = 0;
			while(pix[x][y]->obj[2][b] != NULL)
			{
				intersect_plan(pix[x][y], b);
				b++;
			}
			b = 0;
			while(pix[x][y]->obj[3][b] != NULL)
			{
				intersect_cylinder(pix[x][y], b);
				b++;
			}
			y++;
		}
		x++;
	}	
}
*/