/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:40:13 by syl               #+#    #+#             */
/*   Updated: 2025/02/12 15:22:34 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pix ***init_data_test(void)
{
	t_pix	***pix;
	t_image *ima;

	pix = NULL;
	pix = init_pix_test(pix);
	ima = init_image();
	link_pix_ima(pix, ima);
	return (pix);
}

//L1 = 1200 ??
//L2 = 1600 ??
t_pix ***init_pix_test(t_pix ***pix)
{
    int x;
	int y;

	x = 0;
    pix = (t_pix ***)malloc(1600 * sizeof(t_pix **));//1600 = canva width
    if (!pix)
        return NULL;
	while(x < 1600)//1600 = canva width
	{
		y = 0; 
		pix[x] = (t_pix **)malloc(1200 * sizeof(t_pix *)); // 1200 = canva height
        if (!pix[x])
			return NULL; //free...
		while (y < 1200) // 1200 = canva height
		{
			pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
            if (!pix[x][y])
                return NULL;//free...
			pix[x][y]->col = create_color(30, 40, 200);
			y++;
		}
		x++;
	}
    return pix;
}

void	link_pix_ima(t_pix ***pix, t_image *ima)
{
	int x;
	int y;

	x = 0;
	while (x < 1600)
	{
		y = 0;
		while (y < 1200)
		{
			pix[x][y]->ima = ima;
			y++;
		}
		x++;
	}
	return;
}