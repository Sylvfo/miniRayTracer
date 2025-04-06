/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:48:36 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 16:39:10 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// POUR REFLEXION ET REFRACTION FAIRE DES ARRAYS....
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
			// Copier la couleur au lieu de réassigner le pointeur :
			pix[x][y]->color->r = pix[x][y]->comps->obj->color->r;
			pix[x][y]->color->g = pix[x][y]->comps->obj->color->g;
			pix[x][y]->color->b = pix[x][y]->comps->obj->color->b;
			pix[x][y]->color->rgb = pix[x][y]->comps->obj->color->rgb;
			y++;
		}
		x++;
	}
}

void closest_obj(t_pix *pix)
{
//	float closestt = INT_MAX;//il faudrait initialiser comps->closest t a INT MAX....
	int	x;
	int	y;
	
	pix->comps->obj = pix->obj[0][0];
	pix->comps->t_count = 0;
	pix->comps->closestt = INT_MAX;
	pix->comps->r_ray = copy_ray(pix->r_original);
	x = 1;
	while (x < 2) //ICI CHANGER POUR PLUS DE FORMES!!!!
	{
		y = 0;
		while (pix->hits[x][y] != NULL)
		{
			if (pix->hits[x][y]->t1 < pix->comps->closestt && pix->hits[x][y]->t1 > 0)/// ou plus grand que zero...
			{
			//	closestt = pix->hits[x][y]->t1;//aw aw
				pix->comps->closestt = pix->hits[x][y]->t1;
				pix->comps->obj = pix->obj[x][y];
				pix->comps->r_ray = copy_ray(pix->hits[x][y]->r_ray_calculs);
				pix->comps->t_count = 1;
			}
			else if (pix->hits[x][y]->t2 < pix->comps->closestt &&  pix->hits[x][y]->t2 > 0)/// ou plus grand que zero...
			{
			//	pix->comps->closestt = pix->hits[x][y]->t2;// aw aw
				pix->comps->closestt = pix->hits[x][y]->t2;
				pix->comps->obj = pix->obj[x][y];
				pix->comps->r_ray = copy_ray(pix->hits[x][y]->r_ray_calculs);
				pix->comps->t_count = 1;
			}
/*			else
			{
				pix->comps->r_ray = copy_ray(pix->r_original);
			}*/
			printf("closestt %.2f \n", pix->comps->closestt); 

			y++;
		}
		x++;
	}
}

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
			// Calculer le point d'intersection
/*			if (pix[x][y]->comps->t_count == 0)
			{
				y++;
			}*/
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
			//!!! est-ce que r_ray normé ou pas?????
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
			t_coord *temp1 = substraction(pix[x][y]->comps->p_touch, pix[x][y]->comps->obj->p_coord);
	//		pix[x][y]->comps->v_norm_parral = normalize_vector(pix[x][y]->comps->v_norm_parral);
			//cest la bonne formule avec le calcul normal at de Corentin
			t_coord *temp2 = normal_at(pix[x][y]->comps->obj, pix[x][y]->comps->p_touch);
			if (!pix[x][y]->comps->v_norm_parral)
			{
				printf("Error: Échec du calcul de la normale pour le pixel (%d, %d)\n", x, y);
				free(pix[x][y]->comps->p_touch);
				free(pix[x][y]->comps->v_eye);
				y++;
				continue;
			}
			//rajouté par syl pour calcul dessous se fasse pour deux vecteurs normées.
			pix[x][y]->comps->v_norm_parral = normalize_vector(pix[x][y]->comps->v_norm_parral);
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