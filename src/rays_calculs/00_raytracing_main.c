/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/29 13:28:25 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

#include <sys/time.h>

void test_couleur(t_pix ***pix);

void raytracing(t_pix ***pix)
{
	//pour mesurer. A effacer
	struct timeval start;
	gettimeofday(&start, NULL);

	if (init_a_deplacer(pix) == false)
		exit(0);
	start = time_now(start, " init");
	//creation de la camera
	constructing_camera(pix);
	start = time_now(start, " camera");
	//creation du viewport
	init_viewport(pix);
	// calculs matriciels pour déplacer et scale les objets
	start = time_now(start, " viewport");

	printf("pix[0][0]->p_viewport %.2f, %.2f, %.2f \n", pix[0][0]->p_viewport->x, pix[0][0]->p_viewport->y, pix[0][0]->p_viewport->z);
	printf("pix[0][0]->p_viewport_word %.2f, %.2f, %.2f \n", pix[0][0]->p_viewport_world->x, pix[0][0]->p_viewport_world->y, pix[0][0]->p_viewport_world->z);


	printf("pix[WND_WIDTH][WND_HEIGHT]->p_viewport %.2f, %.2f, %.2f \n", pix[WND_WIDTH-1][WND_HEIGHT-1]->p_viewport->x, pix[WND_WIDTH-1][WND_HEIGHT-1]->p_viewport->y, pix[WND_WIDTH-1][WND_HEIGHT-1]->p_viewport->z);
	printf("pix[WND_WIDTH][WND_HEIGHT]->p_viewport_word %.2f, %.2f, %.2f \n", pix[WND_WIDTH-1][WND_HEIGHT-1]->p_viewport_world->x, pix[WND_WIDTH-1][WND_HEIGHT-1]->p_viewport_world->y, pix[WND_WIDTH-1][WND_HEIGHT-1]->p_viewport_world->z);

	printf("pix[524][324]->p_viewport %.2f, %.2f, %.2f \n", pix[524][324]->p_viewport->x, pix[524][324]->p_viewport->y, pix[524][324]->p_viewport->z);
	printf("pix[524][324]->p_viewport_word %.2f, %.2f, %.2f \n", pix[524][324]->p_viewport_world->x, pix[524][324]->p_viewport_world->y, pix[524][324]->p_viewport_world->z);
/*	# define WND_WIDTH 1050
	# define WND_HEIGHT 650*/





	matrix_transformations(pix);
	start = time_now(start, " set_transf");

	main_intersections(pix);
	//print_matrix(pix[0][0]->obj[1][2]->m_inv);
//	exit(0);
	start = time_now(start, " intersections");
	//trie les intersection selon la plus proche du viewport (et camera)
	find_closest_obj(pix);
	start = time_now(start, " closest obj");

//	test_couleur(pix);

	prepare_computation(pix);

	start = time_now(start, " prepare computation");
	
	//intersect rayons avec sphere
	new_light(pix);
	start = time_now(start, " new lights");
	return;
}


void test_couleur(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps->obj_type == SPHERE)
			{
				pix[x][y]->color->r = 0.6;
				pix[x][y]->color->g = 0;
				pix[x][y]->color->b = 0;
			}
			if (pix[x][y]->comps->obj_type == PLAN)
			{
				pix[x][y]->color->r = 0;
				pix[x][y]->color->g = 0.8;
				pix[x][y]->color->b = 0;
			}		
			y++;
		}
		x++;
	}
}