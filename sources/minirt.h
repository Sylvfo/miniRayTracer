/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/01/24 16:09:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "librairies/libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define RAY_T_MIN 0.0001f // not to interract with the last object touched. no neg value. 1 is for safety
# define RAY_T_MAX 0.0e30f // really large floating number. So it means 1.0 × 10³⁰ (10 puissance 30) 1 suivi de 30 zeros

typedef struct s_3dpoint {
	float	x;
	float	y;
	float   z;
} t_3dpoint;

typedef struct s_vect3d { //vector
	float	x;
	float	y;
	float   z;
} t_vect3d;

typedef struct	s_sphere {
	t_3dpoint		*center;
	int				radius;
	int				color;
}				t_sphere;

typedef struct s_spotlight { //bulb??
	t_3dpoint	*coord;
	float		ratio;
//	int			color;	not in mandatory part
} t_spotlight;

typedef struct	s_plane {
	t_3dpoint		*point;
	t_vect3d		*normal; // normal, so 90° from the point
	int				color;
}	t_plane;

typedef struct	s_cyl {
	t_3dpoint		*center;
	t_vect3d		*axis;
	int				height;
	int				diam;
	int				color;
}	t_cyl;

typedef struct s_scene {
	t_sphere	**sphere;
	float		ambient_light_ratio;
	float		ambient_light_color;
	t_plane		*plane;
	t_spotlight *light1;
	//autres formes
} t_scene;

typedef struct	s_view {//global
	t_3dpoint	*cam;
	float	caneva_width;
	float	caneva_height;
	float	view_width;
	float	view_height;
	int		Vz; //dist du viewport de la camera
	t_scene		*scene;
	int 	backgroundcolor;
	// calculer rapport en canveva et view??
}				t_view;

// data struc = array of pixels. 
typedef struct	s_pix {
	int			Cx; //axe x sur le canvas
	int			Cy;  //axe y sur la canvas
	t_vect3d	*D; // vecteur entre camera et coordonnes sur viewport
	int			color;
	t_view		*global;
	t_scene		*scene;
	float		t1;
	float		t2;
//	float		light_int;
} t_pix;

typedef struct s_image {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx_ptr;
	void			*mlx_win;
	t_view			*global;
}	t_image;

//main.c

// init_data.c
void	link_pix_global(t_pix ***pix, t_view *global);
t_view	*init_global(void);
t_pix	***init_pix(t_pix ***pix, t_view *global);
t_pix	***init_data(void);

// init_scene.c
t_scene *init_scene(void);
t_spotlight *init_lights(void);

//raytracing.c
void	ray_tracing(t_pix ***pix, t_image *ima);
void	CanvasToViewport(float Cx, float Cy, t_pix *pix);
void 	IntersectRaySphere(t_pix *pix, t_sphere *sphere);
void 	TraceRay(t_pix *pix);
void	test_print(t_pix *pix, int x, int y);
void	test(t_pix *pix, int x, int y);

//init_image.c
t_image *init_image(t_view *global);
void	color_image(t_view *global, t_image *ima);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);
void 	image_hooks(t_image *ima);

//pixelPut
int	ft_keys(int keycode, t_image *ima);
int	ft_exit(t_image *ima);

//math.c
float dot_product(t_vect3d *va, t_vect3d *vb);
t_vect3d *vect_from_points(t_3dpoint *a, t_3dpoint *b);
float	lenght_vector(t_vect3d *vect);
void normalize_vector(t_vect3d *vect);
t_3dpoint *pointonline(t_pix *pix, float closestt);
t_vect3d	*substraction_point(t_3dpoint *a, t_3dpoint *b);

//light.c
float ComputeLighting(t_pix *pix, float closestt, t_sphere *closest_sphere);
float light_intensity(t_3dpoint *P, t_vect3d *N, t_pix *pix);
float 	compute_spotlight(t_3dpoint *P, t_vect3d *N, t_pix *pix, t_spotlight *light);

float 	compute_ambient(t_pix *pix);

//bitwise.c
unsigned int modify_color(int color, float intensity);

//intersect
void intersectrayplane(t_pix *pix, t_plane *plane);


//print
void print3dvect(t_vect3d *va);

#endif