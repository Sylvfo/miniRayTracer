

typedef struct s_pix
{
	//same for all
	t_camera	*cam; // OK
	t_obj		***obj; // OK
	t_obj		***c_obj;//scene from camera a voir apres
	t_light		***lux; // OK
	t_image		*ima; // A FAIRE PAR SYLVIE
	t_matrix	*neo; // A FAIRE PAR SYLVIE

	//in each pixel. 
	t_coord		*v_d; // vecteur entre camera et coordonnes sur viewport
	t_color		*color; // OK
	t_obj		*closest_obj;
// closest object
// 	data for calculation	
	float		t1;
	float		t2;
}	t_pix;

bool	init_data(t_pix ***pix, t_num_obj *num_obj)
{
//	if (init_pix(pix, WND_HEIGHT, WND_WIDTH) == false)
//		return (false);
	if (init_pix(pix) == false)
		return (false);
	if (init_scene(pix, num_obj) == false)
	{
		free_all(pix);
		return (false);
	}
	if (init_ima(pix) == false) // || init_matrix_ref(pix) == false)
	{
		free_all(pix);
		return (false);
	}
	return (true);
}

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
		pix[x] = (t_pix **)malloc(WND_HEIGHT * sizeof(t_pix *));
		if (!pix[x])
			return (NULL);
		while (y < WND_HEIGHT)
		{
			pix[x][y] = (t_pix *)malloc(sizeof(t_pix));
			if (!pix[x][y])
				return (NULL);//free...
			y++;
		}
		x++;
	}
	printf("y = %i \n", y);
	return (pix);
}

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
//	pix[0][0]->cam = cam;
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
				(*pix)[x][y].cam = cam;
				(*pix)[x][y].obj = obj;
				(*pix)[x][y].lux = lux;
/*				pix[x][y]->obj = obj;
				pix[x][y]->c_obj = NULL;
				pix[x][y]->cam = cam;
				pix[x][y]->lux = lux;*/
			}
			y++;
		}
		x++;
	}
	return ;
}

