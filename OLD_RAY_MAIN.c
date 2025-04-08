/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_RAY_MAIN.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:55:44 by sforster          #+#    #+#             */
/*   Updated: 2025/03/09 15:08:27 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minirt.h"

//	int 	*O; // position de la camera DATAS COMMUN
//	int 	Cw; // largeur x du canvas DATAS COMMUN
//	int 	Ch; // hauteur y du canvas DATAS COMMUN
//	int 	D[3]; // coordonnees 3D du viewport. Dans DATAS PIX
//	O = (0, 0, 0);

//pour tout le raytracing je me suis basée sur les pages 14-62 
// du livre Computer Graphics from scratch

void ray_tracing(t_pix ***pix, t_image *ima)
{
	float 	Cx; // axe x sur le canvas -> ici
	float	Cy; // axe y sur la canvas -> ici
	int		x;
	int		y;

	x = 0;
	y = 0;
	//page 15
	Cx = (pix[0][0]->global->caneva_width / 2) * -1;
	while (x < pix[0][0]->global->caneva_width)
	{
		Cy = (pix[0][0]->global->caneva_height / 2) *-1;
		while (y < pix[0][0]->global->caneva_height) // pour chaque point sur le canvas
		{
			CanvasToViewport(Cx, Cy, pix[x][y]); // trouver le view port
	//		intersectrayplane(pix[x][y], pix[x][y]->scene->plane);
			TraceRay(pix[x][y]); // trouver la couleur des points.
			mlx_pixel_put(ima->mlx_ptr, ima->mlx_win, x, y, pix[x][y]->color);
			y++;
			Cy++;
		}
		Cx++;
		y = 0;
		x++;
	}
}

void TraceRay(t_pix *pix)
{
	// find what object it intersect with
	float closestt = INT_MAX;
	t_sphere *closest_sphere; // data struc or malloc?? non c est un pointeur
	int i = 0;
	int closest_col;

	pix->color = 0;
	closest_sphere = NULL;
	closest_col = 0;
//rajouter pour plusieures spheres
	while (i < 8)
	{
		IntersectRaySphere(pix, pix->global->scene->sphere[i]);
		if (pix->t1 < closestt && pix->t1 > 1)
		{
			closestt = pix->t1;
			pix->color = pix->global->scene->sphere[i]->color;
			closest_sphere = pix->global->scene->sphere[i];
		}
		if (pix->t2 < closestt && pix->t2 > 1)
		{
			closestt = pix->t2;
			pix->color = pix->global->scene->sphere[i]->color;
			closest_sphere = pix->global->scene->sphere[i];
			//closest_col = pix->scene->plane->color;
		}
		i++;
	}
	intersectrayplane(pix, pix->scene->plane);
	if (pix->t1 < closestt && pix->t1 > 1)
	{
		closestt = pix->t1;
		pix->color = pix->scene->plane->color;
	}
		//bool function intersection
		// so if intersection == false. pix col = background
	if (pix->color == 0)//(closest_sphere == NULL)
	{
		pix->color = modify_color(pix->global->backgroundcolor, pix->scene->ambient_light_ratio);	
		return ;
	}
	if (closest_sphere != NULL)
		ComputeLighting(pix, closestt, closest_sphere);		
//	pix->color = closest_col;
	//	pix->color = closest_sphere->color;
}

void	CanvasToViewport(float Cx, float Cy, t_pix *pix)  // mettre data dedans Cx et Cy c est les points x y sur le canvas
{
	if (!pix)
        return;
	pix->Cx = Cx; // a faire au debut??
	pix->Cy = Cy; // a faire au debut???
	pix->D->x = Cx * (pix->global->view_width / pix->global->caneva_width); // Vw / Cw a calculer une fois pour tous???
	pix->D->y = Cy * (pix->global->view_height / pix->global->caneva_height); // a calculer une fois pour tous???
	pix->D->z = pix->global->Vz;
	normalize_vector(pix->D);
	return;
}

void	test(t_pix *pix, int x, int y)
{
	printf("test x %i y %i\n", x, y);
	pix->Cx = x;
	pix->Cy = y;
}

void	test_print(t_pix *pix, int x, int y)
{
	printf("test x %i y %i\n", x, y);
	printf("test2 x%i y %i \n", pix->Cx, pix->Cy);
}

/*
DATAS:
communs:
int 	*O; // position de la camera DATAS
int 	Cw; // largeur x du canvas DATAS
int 	Ch; // hauteur y du canvas DATAS
s

pour chaque pixel:
DATA PIX
	int 	Cx; // axe x sur le canvas -> ici
	int 	Cy; // axe y sur la canvas -> ici
	int 	D[3]; // coordonnees 3D du viewport. Dans DATAS?




ignore solution with t < 0 (derriere la camera)
ignore also solutions with t < 1 (entre ecran et camera)

t + c est les points le long de la ligne
il faut voir si ces points touchent la sphrere. 
*/