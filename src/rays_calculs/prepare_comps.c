/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_comps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:00:25 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 14:44:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


/*
void normal_at_plans(t_obj ***obj)
{
	while(obj[2][x] != NULL)
	{
		obj[2][x]->v_norm_parral_plan = 
		x++;
	}
}*/

//trier les objets dans l ordre... a la plac de find closest. 
void prepare_computation(t_pix ***pix)
{
	int x;
	int y;

	// a effacer
	struct timeval start;
	gettimeofday(&start, NULL);

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (x == 12 && y == 12)
				start = time_now(start, " start");
			//ici segfautl 	
			pix[x][y]->comps->p_touch = position(pix[x][y]->comps->r_origin, pix[x][y]->comps->r_dir, pix[x][y]->comps->closestt);
			if (!pix[x][y]->comps->p_touch)
			{
				printf("Error: Échec du calcul du point d'intersection pour le pixel (%d, %d)\n", x, y);
				y++;
				continue;
			}
			if (x == 12 && y == 12)
				start = time_now(start, " position");
			// Calculer le vecteur œil : inverse de la direction du rayon
	//		pix[x][y]->comps->v_eye = negat(pix[x][y]->comps->r_ray->v_dir);
			pix[x][y]->comps->v_eye = malloc(sizeof(t_coord));
			copy_coord(pix[x][y]->comps->v_eye, pix[x][y]->comps->r_dir);
		//	pix[x][y]->comps->v_eye = copy_coord(pix[x][y]->comps->r_dir);
		//	pix[x][y]->comps->v_eye->x = pix[x][y]->comps->r_ray->v_dir->x;
		//	pix[x][y]->comps->v_eye->y = pix[x][y]->comps->r_ray->v_dir->y;
		//	pix[x][y]->comps->v_eye->z = pix[x][y]->comps->r_ray->v_dir->z;
		//	pix[x][y]->comps->v_eye->t = 0;
			if (!pix[x][y]->comps->v_eye)
			{
				printf("Error: Échec du calcul du vecteur œil pour le pixel (%d, %d)\n", x, y);
				free(pix[x][y]->comps->p_touch);
				y++;
				continue;
			}
			if (x == 12 && y == 12)
				start = time_now(start, " v eye");
			// Calculer la normale au point d'intersection
			if (pix[x][y]->comps->obj_type == SPHERE)
			{
				//printf(".");
			//ici sylvie modifie pour tester avec un normal at plus simple
			
				pix[x][y]->comps->v_norm_parral = substraction(pix[x][y]->comps->p_touch, pix[x][y]->comps->obj->p_coord);
				pix[x][y]->comps->v_norm_parral = normalize_vector(pix[x][y]->comps->v_norm_parral);
			//	pix[x][y]->comps->v_norm_parral = normal_at(pix[x][y]->comps->obj, pix[x][y]->comps->p_touch);
			//	print_vector(pix[x][y]->comps->v_norm_parral);
			//	printf("`");
					if (!pix[x][y]->comps->v_norm_parral)
				{
					printf("Error: Échec du calcul de la normale pour le pixel (%d, %d)\n", x, y);
					free(pix[x][y]->comps->p_touch);
					free(pix[x][y]->comps->v_eye);
					y++;
					continue;
				}
			}
			// normal at plan c est pareil que l axe donné au début
			if (pix[x][y]->comps->obj_type == PLAN)
			{
			//	pix[x][y]->comps->v_norm_parral = malloc(sizeof(t_coord));
				pix[x][y]->comps->v_norm_parral = pix[x][y]->comps->obj->v_axe;
			//	printf("normal plan x: %.2f et y: %.2f \n", pix[x][y]->vpx, pix[x][y]->vpy);
		//	print_vector(pix[x][y]->comps->v_norm_parral);
				pix[x][y]->comps->v_norm_parral = malloc(sizeof(t_coord));
				pix[x][y]->comps->v_norm_parral->x = pix[x][y]->comps->obj->v_axe->x;
				pix[x][y]->comps->v_norm_parral->y = pix[x][y]->comps->obj->v_axe->y;
				pix[x][y]->comps->v_norm_parral->z = pix[x][y]->comps->obj->v_axe->z;
				pix[x][y]->comps->v_norm_parral->t = pix[x][y]->comps->obj->v_axe->t;
				pix[x][y]->comps->v_norm_parral = normalize_vector(pix[x][y]->comps->v_norm_parral);
				//print_vector(pix[x][y]->comps->v_norm_parral);
			}		
		//	if (x == 12 && y == 12)
		//		start = time_now(start, " normal at");
			// Vérifier si le rayon pénètre dans l'objet.
			// Si le produit scalaire entre la normale et le vecteur œil est négatif,
			// alors le rayon est à l'intérieur. Inverser dans ce cas la normale.
			if (pix[x][y]->comps->obj_type != NONE)
			{
				if (dot_product(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_eye) < 0)
				{
			//	printf("a");
					pix[x][y]->comps->inside = true;
					pix[x][y]->comps->v_norm_parral->x = -pix[x][y]->comps->v_norm_parral->x;
					pix[x][y]->comps->v_norm_parral->y = -pix[x][y]->comps->v_norm_parral->y;
					pix[x][y]->comps->v_norm_parral->z = -pix[x][y]->comps->v_norm_parral->z;
				}
			}
			y++;
		}
		x++;
	}
}

/* fonction prepare computation avant nettoyage
//trier les objets dans l ordre... a la plac de find closest. 
void prepare_computation(t_pix ***pix)
{
	int x;
	int y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			// On vérifie d'abord que le pixel et sa structure comps sont correctement alloués
			if (!pix[x][y] || !pix[x][y]->comps)
			{
				printf("Warning: La structure comps est manquante pour le pixel (%d, %d)\n", x, y);
				y++;
				continue;
			}
			// Vérifier si un objet a été trouvé pour ce pixel
			if (!pix[x][y]->comps->obj)
			{
				printf("Warning: Aucun objet trouvé pour le pixel (%d, %d)\n", x, y);
				y++;
				continue;
			}
			pix[x][y]->comps->p_touch = position(pix[x][y]->comps->r_ray, pix[x][y]->comps->closestt);
			printf("p_touch (point d'intersection) : x = %f, y = %f, z = %f\n",
				pix[x][y]->comps->p_touch->x,
				pix[x][y]->comps->p_touch->y,
				pix[x][y]->comps->p_touch->z);
			if (!pix[x][y]->comps->p_touch)
			{
				printf("Error: Échec du calcul du point d'intersection pour le pixel (%d, %d)\n", x, y);
				y++;
				continue;
			}
			// Calculer le vecteur œil : inverse de la direction du rayon
			pix[x][y]->comps->v_eye = negat(pix[x][y]->comps->r_ray->v_dir);
			if (!pix[x][y]->comps->v_eye)
			{
				printf("Error: Échec du calcul du vecteur œil pour le pixel (%d, %d)\n", x, y);
				free(pix[x][y]->comps->p_touch);
				y++;
				continue;
			}
			
			// Calculer la normale au point d'intersection
		//ici sylvie modifie pour tester avec un normal at plus simple
			pix[x][y]->comps->v_norm_parral = substraction(pix[x][y]->comps->p_touch, pix[x][y]->comps->obj->p_coord);
			//rajouté par syl pour calcul dessous se fasse pour deux vecteurs normées.
			pix[x][y]->comps->v_norm_parral = normalize_vector(pix[x][y]->comps->v_norm_parral) 

pix[x][y]->comps->v_norm_parral = normal_at(pix[x][y]->comps->obj, pix[x][y]->comps->p_touch);
//		t_coord *temp1 = substraction(pix[x][y]->comps->p_touch, pix[x][y]->comps->obj->p_coord);
//		pix[x][y]->comps->v_norm_parral = normalize_vector(pix[x][y]->comps->v_norm_parral);
		//cest la bonne formule avec le calcul normal at de Corentin
//		t_coord *temp2 = normal_at(pix[x][y]->comps->obj, pix[x][y]->comps->p_touch);
		if (!pix[x][y]->comps->v_norm_parral)
		{
			printf("Error: Échec du calcul de la normale pour le pixel (%d, %d)\n", x, y);
			free(pix[x][y]->comps->p_touch);
			free(pix[x][y]->comps->v_eye);
			y++;
			continue;
		}
		// Vérifier si le rayon pénètre dans l'objet.
		// Si le produit scalaire entre la normale et le vecteur œil est négatif,
		// alors le rayon est à l'intérieur. Inverser dans ce cas la normale.
		if (dot_product(pix[x][y]->comps->v_norm_parral, pix[x][y]->comps->v_eye) < 0)
		{
			pix[x][y]->comps->inside = true;
			pix[x][y]->comps->v_norm_parral->x = -pix[x][y]->comps->v_norm_parral->x;
			pix[x][y]->comps->v_norm_parral->y = -pix[x][y]->comps->v_norm_parral->y;
			pix[x][y]->comps->v_norm_parral->z = -pix[x][y]->comps->v_norm_parral->z;
		}
		else
			pix[x][y]->comps->inside = false;
		y++;
	}
	x++;
}
}
*/