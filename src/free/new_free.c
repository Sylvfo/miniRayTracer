/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:17:57 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 08:43:49 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void new_free(t_pix ***pix)
{
	printf("test %.2f \n",pix[0][0]->r_dir->x);
	if (!pix)
		return;
	printf("free enter2");
	if (!pix[0])
		return;
	printf("free enter3");
	if (!pix[0][0])
		return;
	printf("free enter");
//	free_hits_S(pix);
	printf("free hits");
//	free_comps_S(pix);
//	printf("free comps");
	free_lux_S(pix[0][0]);
	printf("free lux");
	free_obj_S(pix[0][0]);
	printf("free cam");
	free_camera(pix[0][0]->cam);
	pix[0][0]->cam = NULL;
//	free_image(pix[0][0]->ima);
	free_pix_S(pix);
	free(pix);
	pix = NULL;
	printf("klsfjk\n");
}

void	free_pix_S(t_pix ***pix)
{
	free_pix_inside(pix);
	free_pix_mid(pix);
	free_pix_all(pix);
}

void free_pix_mid(t_pix ***pix)
{
	int	x;

	x = 0;
	while (x < WND_WIDTH)
	{
		if (pix[x])
			free(pix[x]);
	//	pix[x] = NULL;
	}	
}

void free_pix_all(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			free(pix[x][y]);
			pix[x][y] = NULL;
			y++;
		}
		x++;
	}	
}

void free_pix_inside(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			free_coord(pix[x][y]->p_viewport);
			free_coord(pix[x][y]->p_viewport_world);
			free_coord(pix[x][y]->r_origin);
			free_coord(pix[x][y]->r_dir);
			free(pix[x][y]->color);
			y++;
		}
		x++;
	}
}

/*
void	free_obj_S(t_pix *pix)
{
	int	a;
	int	b;

	if (!pix || !pix->obj)
		return ;
	a = 0;
	while (a < 4 && pix->obj[a])
	{
		b = 0;
		while (pix->obj[a][b])
		{
			free_one_obj(pix->obj[a][b]);
			pix->obj[a][b] = NULL;
			b++;
		}
		free(pix->obj[a]);
		pix->obj[a] = NULL;
		a++;
	}
	free(pix->obj);
	pix->obj = NULL;
}*/

void free_obj_inside(t_obj ***obj)
{
	int	a;
	int	b;

	a = 0;
	while (a < 4)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
			if (obj[a][b]->m_transl)
				free(obj[a][b]->m_transl);
			free(obj[a][b]->m_rot);
			free(obj[a][b]->m_scale);
			free(obj[a][b]->m_transf);
			free(obj[a][b]->m_inv);
			free_coord(obj[a][b]->p_coord);
			free(obj[a][b]->color);
			free_coord(obj[a][b]->v_axe);
			free_coord(obj[a][b]->v_axe_r);
			free_coord(obj[a][b]->from);
			free_coord(obj[a][b]->v_axe_r);
			free_coord(obj[a][b]->v_sph_camera);
			b++;
		}
		a++;
	}	
}

void free_obj_all(t_obj ***obj)
{
	int	a;
	int	b;

	a = 0;
	while (a < 4)
	{
		free(obj[a]);
		obj[a] = NULL;
		a++;
	}
}

void free_obj_mid(t_obj ***obj)
{
	int	a;
	int	b;

	a = 0;
	while (a < 4)
	{
		b = 0;
		while (obj[a][b] != NULL)
		{
			free(obj[a][b]);
			obj[a][b] = NULL;
			b++;
		}
		a++;
	}	
}

void free_obj_S(t_pix *pix)
{
	if (pix->obj)
		free_obj_inside(pix->obj);
	if (pix->obj)
		free_obj_mid(pix->obj);
	if (pix->obj)
		free_obj_all(pix->obj);
	free(pix->obj);
	pix->obj = NULL;
}

/////////////////////////////////

void free_lux_inside(t_light ***lux)
{
	int	a;
	int	b;

	a = 0;
	while (a < 2)
	{
		b = 0;
		while (lux[a][b] != NULL)
		{
			free(lux[a][b]->p_coord);
			lux[a][b]->p_coord = NULL;
			free(lux[a][b]->color);
			lux[a][b]->color = NULL;
			b++;
		}
		a++;
	}	
}

void free_lux_all(t_light ***lux)
{
	int	a;
	int	b;

	a = 0;
	while (lux[a] != NULL)
	{
		if (lux[a])
			free(lux[a]);
		lux[a] = NULL;
		a++;
	}
}

void free_lux_mid(t_light ***lux)
{
	int	a;
	int	b;

	a = 0;
	while (lux[a] != NULL)
	{
		b = 0;
		while (lux[a][b] != NULL)
		{
			free(lux[a][b]);
			lux[a][b] = NULL;
			b++;
		}
		a++;
	}	
}

void free_lux_S(t_pix *pix)
{
	free_lux_inside(pix->lux);
	free_lux_mid(pix->lux);
	free_lux_all(pix->lux);
	free(pix->lux);
	pix->lux = NULL;
}

void free_comps_S(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->comps != NULL)
			{
				free_comps_inside(pix[x][y]->comps);
				free(pix[x][y]->comps);
				pix[x][y]->comps = NULL;
			}
			y++;
		}
		x++;
	}
}

void	free_comps_inside(t_comps *comps)
{
	free(comps->r_origin);
	free(comps->r_dir);
	free(comps->obj);
	free(comps->obj_color);
	free(comps->origin_zero);
	free(comps->object_normal);
	free(comps->p_space);
	free(comps->obj_inv);
	free(comps->p_touch);
	free(comps->v_eye);
	free(comps->v_norm_parral);
	free(comps->v_light_to_point);
	free(comps->v_sphere_to_point);
	free(comps->v_point_to_light);
	free(comps->reflect_dir);
	free(comps->scalar);
	free(comps->view_dir);
	free(comps->transp_inv);
}

void free_hits_S(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->hits != NULL)
			{
				free_hits_inside(pix[x][y]);
			//	free_hits_inside_mid(pix[x][y]);
				free_hits_all(pix[x][y]);
			}
			y++;
		}
		x++;
	}
}

void free_hits_inside(t_pix *pix)
{
	int	a;
	int	b;

	a = 0;
	while (a < 4)
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->r_dir != NULL)
			{
				free(pix->hits[a][b]->r_dir);
				pix->hits[a][b]->r_dir = NULL;
			}
			if (pix->hits[a][b]->r_origin != NULL)
			{
				free(pix->hits[a][b]->r_origin);
				pix->hits[a][b]->r_origin = NULL;
			}
			b++;
		}
		a++;
	}
}

void free_hits_inside_mid(t_pix *pix)
{
	int	a;
	int	b;

	a = 0;
	while (pix->hits[a] != NULL)
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b] != NULL)
			{
				free(pix->hits[a][b]);
				pix->hits[a][b] = NULL;
			}
			b++;
		}
		a++;
	}
}

void free_hits_all(t_pix *pix)
{
	int	a;

	a = 0;
	while (pix->hits[a] != NULL)
	{
		free(pix->hits[a]);
		pix->hits[a] = NULL;
		a++;
	}
}