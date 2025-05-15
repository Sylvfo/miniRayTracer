

#include "../inc/minirt.h"

//void free_coord2(&coord);

void free_coord2(t_coord **coord)
{
	if (!*coord)
		return;
	free(*coord);
	*coord = NULL;
}

//void	free_matrix(&m_matrix)

void	free_matrix(float **m_matrix)
{
	if (!*m_matrix)
		return ;
	free (*m_matrix);
	*m_matrix = NULL;
}

void free_color2(t_color **color)
{
	if (!*color)
		free(*color);
	*color = NULL;
}


///// MAIN FONCTION /////
void free_all2(t_pix ***pix)
{
	printf("in free all2 \n");
//	if (!***pix)
//		return ;
//	free_comps2(pix);
	free_pix2(pix);


// ???	
/*	if (!**pix)
		return ;
	if (!***pix)
		return ;*/
	//free_hits_2(pix);
}

void	free_pix2(t_pix ***pix)
{
	int	x;
	int	y;

//	if (!***pix)
//		return ;
	//verifier tableau de pix...

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			if (pix[x][y]->p_viewport != NULL)
			{
				free(pix[x][y]->p_viewport);
				pix[x][y]->p_viewport = NULL;
			}
/*			if (pix[x][y]->p_viewport_world != NULL)
			{
				free(pix[x][y]->p_viewport_world);
				pix[x][y]->p_viewport_world = NULL;
			}
			if (pix[x][y]->r_origin != NULL)
			{
				free(pix[x][y]->r_origin);
				pix[x][y]->r_origin = NULL;
			}
			if (pix[x][y]->r_dir != NULL)
			{
				free(pix[x][y]->r_dir);
				pix[x][y]->r_dir = NULL;
			}*/
		//	free_coord2(pix_local[x][y]->p_viewport);
	//		free_coord2(&pix[x][y]->p_viewport_world);
		//	free_coord2(&pix[x][y]->r_origin);
		//	free_coord2(&pix[x][y]->r_dir);
			y++;
		}
		x++;
	}
}



/*
void free_comps2(t_pix ****pix)
{
	if ()
		return;

}*/





/*
void free_hits_array(t_hits ****hits)
{
	int	a;
	int	b;

	if (!***hits)
	{
		return;
	}
	//verifier tableau

	a = 0;
	while (*hits[a] != NULL)
	{
		b = 0;
		while (*hits[a][b] != NULL)
		{
			free_hits_data2(&hits[a][b]);
			b++;
		}
		a++;
	}
}

//free_hits_data(&pix[0][0]->hits)

void free_hits_data2(t_hits ***hits)
{
	if (!*hits)
		return ;
	free_coord2(&hits->r_origin);
	free_coord2(&hits->r_dir);
	free (*hits);
	*hits = NULL;
}

void free_hits_2(t_pix ****pix)
{
	int	x;
	int	y;

	if (!***pix)
		return ;
	//verifier tableau de pix...

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			free_hits_array(&pix[x][y]->hits);
			y++;
		}
		x++;
	}
}*/