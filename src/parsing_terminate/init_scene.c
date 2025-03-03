/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:30:43 by sforster          #+#    #+#             */
/*   Updated: 2025/03/03 16:38:44 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


bool	init_scene(t_pix ***pix, t_num_obj *num_obj)
{
	t_camera	*cam;
	t_obj		***obj;	
	t_light		***lux;

	printf("aaaa\n");
	cam = init_camera();
	if (cam == NULL) 
		return (false);
	obj = init_obj(num_obj);
	if (obj == NULL)
	{
		free(cam);
		return (false);
	}
	printf("b\n");
	lux = init_light(num_obj);
	if (lux == NULL)
	{
		free(cam);
		free_obj_memory(obj, 4);
		return (false);
	}
	printf("c\n");
	link_pix_scene(pix, cam, obj, lux);
	printf("d\n");
	return (true);
}

void	link_pix_scene(t_pix ***pix, t_camera *cam, t_obj ***obj, t_light ***lux)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y] != NULL)// ??
			{
				pix[x][y]->obj = obj;
				pix[x][y]->c_obj = NULL;
				pix[x][y]->cam = cam;
				pix[x][y]->lux = lux;
			}
			y++;
		}
		x++;
	}
	return ;
}


/*

bool	init_scene(t_pix ***pix, t_num_obj *num_obj)
{
	t_camera	*cam;
	t_obj		***obj;	
	t_light		***lux;

	printf("num obj sph %i light %i cy %i in sc \n",num_obj->sphere, num_obj->light, num_obj->cylinder);

	cam = init_camera();
	if (cam == NULL) 
		return (false);
	printf("a\n");
	obj = init_obj(num_obj);
	if (obj == NULL)
	{
		free(cam);
		return (false);
	}
	printf("b\n");
	lux = init_light(num_obj);
	if (lux == NULL)
	{
		free(cam);
//		free_obj_memory(obj, )revoir POURQUOI 4?????
	}
//	(void) pix;
//	(void)
	printf("c\n");
	link_pix_scene(pix, cam, obj, lux);
	printf("d\n");
	return (true);
}

void	link_pix_scene(t_pix ***pix, t_camera *cam, t_obj ***obj, t_light ***lux)
{
	int	x;
	int	y;

	(void) obj;
	(void) lux;
	(void) cam;
	(void) pix;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
		//	pix[x][y]->obj = obj;
		//	pix[x][y]->c_obj = NULL;
		//	pix[x][y]->cam = cam;
		//	pix[x][y]->lux = lux;
			y++;
		}
		x++;
	}
	return ;
}

*/