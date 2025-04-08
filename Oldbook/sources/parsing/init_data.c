/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:31:43 by sforster          #+#    #+#             */
/*   Updated: 2025/01/26 15:24:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minirt.h"

//fait à la sauvage. A revoir avec le parsing....

t_pix	***init_data(void)
{
	t_view 	*global;
	t_pix	***pix;

	global = NULL;
	pix = NULL;
	global = init_global();
	if (global == NULL)
		return (NULL);
	pix = init_pix(pix, global);
	if (pix == NULL)
	{
		free (global);
		return (NULL);
	}
	link_pix_global(pix, global);
	(void) global;
	return (pix);
}

t_pix ***init_pix(t_pix ***pix, t_view *global)
{
    int x;
	int y;

	x = 0;
    pix = (t_pix ***)malloc(global->caneva_width * sizeof(t_pix **));
    if (!pix)
        return NULL;
	while(x < global->caneva_width)
	{
		y = 0; 
		pix[x] = (t_pix **)malloc(global->caneva_height * sizeof(t_pix *));
        if (!pix[x])
			return NULL; //free...
		while (y < global->caneva_height)
		{
			pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
            if (!pix[x][y])
                return NULL;//free...
			pix[x][y]->D = malloc(sizeof(t_vect3d));
//			pix[x][y]->t1 = RAY_T_MAX;
 //           pix[x][y]->global = global;
			y++;
		}
		x++;
	}
    return pix;
}

t_view	*init_global(void)
{
	t_view *global;

	global = malloc(sizeof(t_view));
	if (!global)
		return (NULL);
	global->cam = malloc(sizeof(t_3dpoint));
	global->caneva_width = 1500;
	global->caneva_height = 1200;
	global->view_width = 1500; // ?????
	global->view_height = 1200; // ?????????
	global->scene = malloc(sizeof(t_scene));
	global->Vz = 400;
	global->backgroundcolor = 0x00cccc;
	//global->backgroundcolor = 29565; //1644825;
	global->cam->x = 0;
	global->cam->y = 0;
	global->cam->z = 0;
	global->scene = init_scene();
	return (global);
}

void	link_pix_global(t_pix ***pix, t_view *global)
{
	int x;
	int y;

	x = 0;
	while (x < global->caneva_width)
	{
		y = 0;
		while (y < global->caneva_height)
		{
			pix[x][y]->global = global;
			pix[x][y]->scene = global->scene;
			y++;
		}
		x++;
	}
	return;
}

/* POUR LES FREE
t_pix ***init_pix(t_pix ***pix, t_view *global)
{
    int x, y;

    pix = (t_pix ***)malloc(global->caneva_width * sizeof(t_pix **));
    if (!pix)
        return NULL;
    
    for (x = 0; x < global->caneva_width; x++)
    {
        pix[x] = (t_pix **)malloc(global->caneva_height * sizeof(t_pix *));
        if (!pix[x])
        {
            while (x > 0)
            {
                x--;
                free(pix[x]);
            }
            free(pix);
            return NULL;
        }
        for (y = 0; y < global->caneva_height; y++)
        {
            pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
            if (!pix[x][y])
            {
                while (y > 0)
                {
                    y--;
                    free(pix[x][y]);
                }
                while (x > 0)
                {
                    x--;
                    for (y = 0; y < global->caneva_height; y++)
                    {
                        free(pix[x][y]);
                    }
                    free(pix[x]);
                }
                free(pix);
                return NULL;
            }
            pix[x][y]->global = global; // Associer chaque pixel à la structure globale
        }
    }
    return pix;
}
*/