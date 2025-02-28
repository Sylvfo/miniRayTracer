/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init_data_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:40:13 by syl               #+#    #+#             */
/*   Updated: 2025/02/28 12:49:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pix	***init_data_test(void)
{
	t_pix	***pix;
	t_image	*ima;

	pix = NULL;
	pix = init_pix_test(pix);
	ima = init_image();
	link_pix_ima(pix, ima);
	return (pix);
}

//L1 = 1200 ?? height
//L2 = 1600 ?? canva width
t_pix	***init_pix_test(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	pix = (t_pix ***)malloc(WND_WIDTH * sizeof(t_pix **));
	if (!pix)
		return (NULL);
	while (x < WND_WIDTH)
	{
		y = 0;
		pix[x] = (t_pix **)malloc(WND_HIGHT * sizeof(t_pix *));
		if (!pix[x])
			return (NULL);
		while (y < WND_HIGHT)
		{
			pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
			if (!pix[x][y])
				return (NULL);//free...
			pix[x][y]->col = create_color(255, 0, 0);
			y++;
		}
		x++;
	}
	return (pix);
}

void	link_pix_ima(t_pix ***pix, t_image *ima)
{
	int	x;
	int	y;

	x = 0;
	while (x < VIEWP_WIDTH)
	{
		y = 0;
		while (y < VIEWP_HIGHT)
		{
			pix[x][y]->ima = ima;
			y++;
		}
		x++;
	}
	return ;
}
