/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/03/11 10:52:37 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void find_closest_obj(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			closest_obj(pix[x][y]);
			pix[x][y]->color = pix[x][y]->closest_obj->color;
			y++;
		}
		x++;
	}	
}

void closest_obj(t_pix *pix)
{
	float closestt = INT_MAX;
	int	x;
	int	y;
	
	pix->closest_obj = pix->obj[0][0];
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (pix->hits[x][y] != NULL)
		{
			if (pix->hits[x][y]->t1 < closestt && pix->hits[x][y]->t1 > 0)/// ou plus grand que zero...
			{
				closestt = pix->hits[x][y]->t1;
				pix->closest_obj = pix->obj[x][y];
			}
			if (pix->hits[x][y]->t2 < closestt &&  pix->hits[x][y]->t2 > 0)/// ou plus grand que zero...
			{
				closestt = pix->hits[x][y]->t2;
				pix->closest_obj = pix->obj[x][y];
			}
			y++;
		}
		x++;
	}
}