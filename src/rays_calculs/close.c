/*void closest_obj(t_pix *pix)
{
	int	a;
	int	b;
	
	pix->comps->obj = pix->obj[0][0];
	pix->comps->t_count = 0;
	pix->comps->closestt = INT_MAX;
	pix->comps->r_dir = malloc(sizeof(t_coord));
	pix->comps->r_origin = malloc(sizeof(t_coord));
	pix->comps->obj_type = NONE;
	a = 1;
	while (a < 4) //ICI CHANGER POUR PLUS DE FORMES!!!!
	{
		b = 0;
		while (pix->hits[a][b] != NULL)
		{
			if (pix->hits[a][b]->t1 < pix->comps->closestt && pix->hits[a][b]->t1 > 0)/// ou plus grand que zero...
			{
				pix->comps->closestt = pix->hits[a][b]->t1;
				pix->comps->obj = pix->obj[a][b];
				pix->comps->r_dir = malloc(sizeof(t_coord));
				pix->comps->r_origin = malloc(sizeof(t_coord));
				copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
				copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
				pix->comps->t_count = 1;
				pix->comps->obj_type = pix->hits[a][b]->obj_type;
			}
			//rajouter si t2 est plus petit que t1?
			else if (pix->hits[a][b]->t2 < pix->comps->closestt &&  pix->hits[a][b]->t2 > 0)// && pix->hits[x][y]->t2 > pix->hits[x][y]->t1)/// ou plus grand que zero...
			{
				// pour l instant on entre jamais là dedans.... a voir quand on est dans une forme...
				// si si dans les cylindres....
				//printf(",");
				pix->comps->closestt = pix->hits[a][b]->t2;
				pix->comps->obj = pix->obj[a][b];
				pix->comps->r_dir = malloc(sizeof(t_coord));
				pix->comps->r_origin = malloc(sizeof(t_coord));
				copy_coord(pix->comps->r_dir, pix->hits[a][b]->r_dir);
				copy_coord(pix->comps->r_origin, pix->hits[a][b]->r_origin);
				pix->comps->t_count = 1;
				pix->comps->obj_type = pix->hits[a][b]->obj_type;
			}
			// si rien touche...
			else
			{
				pix->comps->r_dir = malloc(sizeof(t_coord));
				pix->comps->r_origin = malloc(sizeof(t_coord));
				copy_coord(pix->comps->r_dir, pix->r_dir);
				copy_coord(pix->comps->r_origin, pix->r_origin);
			}
		//	printf("closestt %.2f \n", pix->comps->closestt); 
			b++;
		}
		a++;
	}
}*/
