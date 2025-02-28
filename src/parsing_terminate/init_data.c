/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:40:13 by syl               #+#    #+#             */
/*   Updated: 2025/02/28 14:40:05 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	init_data(t_pix	***pix)
{
	t_pix	***pix;
	t_image	*ima;

	pix = NULL;
	if (init_pix(pix))
		return (false);
	ima = init_image();

	//init camera 
	// init obj on a besoin de savoir combien
	// ini light on a besoin de savoir combien
	// init matrix memoire + mettre les matrices
	--> erreurs malloc.

	link_pix_ima(pix, ima);
	return (pix);
}

//L1 = 1200 ?? height
//L2 = 1600 ?? canva width
bool	init_pix(t_pix ***pix)
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
//			pix[x][y]->col = create_color(255, 0, 0);
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
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HIGHT)
		{
			pix[x][y]->ima = ima;
			y++;
		}
		x++;
	}
	return ;
}
