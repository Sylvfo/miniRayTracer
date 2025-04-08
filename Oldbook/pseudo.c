/*

a faire pour sphere:
coder raytracer
donnee de base
fenetre etc...

1 Place the camera and the viewport as desired
For each pixel on the canvas
2 Determine which square on the viewport corresponds to this pixel
3 Determine the color seen through that square
4 Paint the pixel with that color

1:
camera is O = (0, 0, 0) 
to calculate viewport:
Field of view = 53(degre)
distance du viewport et de la camera = 1
viewport hight = 1
viewport width = 1
*/

/*
2:
Canvas to viewport
A 2D array of pixels representing the screen or image space (in pixels).
The canvas is a 2D grid of pixels that displays the final image or rendering.
Canva coordinate of pixels: Cx Cy
canva is in pixels is an image space (or screen)

Viewport:
A 2D plane in the 3D world where the camera views the scene (in world units, e.g., meters).
he viewport is a conceptual 2D space in the world (3D space) where the camera is looking. It represents where the scene is "projected" before being mapped onto the canvas for display.
viewport in world units (like meters)
It's the part of the scene you're viewing from the camera's perspective 
a 2D plane in the 3D world
viewport coordinate (Vx , Vy , Vz)

Vx = Cx * Vw / Cw
Vy = Cy * Vh / Ch
regle de 3 pour mettre a l echelle

Vz = d (distance du viewport de la camera. Ici c est 1)


*/
/*
CanvasToViewport(x, y) {
return (x*Vw/Cw, y*Vh/Ch, d)
}

O = (0, 0, 0)
for x = -Cw/2 to Cw/2 
{
	for y = -Ch/2 to Ch/2 
	{
		D = CanvasToViewport(x, y)
		color = TraceRay(O, D, 1, inf)
		canvas.PutPixel(x, y, color)
	}
}

TraceRay(O, D, t_min, t_max) 
{
	closest_t = inf
	closest_sphere = NULL

	for sphere in scene.spheres 
	{
		t1, t2 = IntersectRaySphere(O, D, sphere)
		if t1 in [t_min, t_max] and t1 < closest_t 
		{
			closest_t = t1
			closest_sphere = sphere
		}
		if t2 in [t_min, t_max] and t2 < closest_t 
		{
			closest_t = t2
			closest_sphere = sphere
		}
		if closest_sphere == NULL {// ok
			return BACKGROUND_COLOR
		}
		return closest_sphere.color
}
*/
IntersectRaySphere(O, D, sphere) 
{

	r = sphere.radius
	CO = O - sphere.center //vector from the center of the sphere to the origin of the ray.
	a = dot(D, D)
	b = 2*dot(CO, D)
	c = dot(CO, CO) - r*r
	discriminant = b*b - 4*a*c // pl
	if discriminant < 0 //ok
	{
		return inf, inf
	}
		t1 = (-b + sqrt(discriminant)) / (2*a)
		t2 = (-b - sqrt(discriminant)) / (2*a)
	return t1, t2
}


pour determine si ca touche la sphere:
quadratique equation avec t1 t2 pour chaque rayon
soit pas de solution donc ca touche pas
soit une solution donc tengente
soit 2 solution donc le rayon entre et sort de la sphere

-revoir les couleurs. 
-plusieures spheres



LIGHTS :)


typedef struct	s_pix {
	int			Cx; //axe x sur le canvas
	int			Cy;  //axe y sur la canvas
	t_vect3d	*D; // vecteur entre camera et coordonnes sur viewport
	int			color;
	t_view		*global;
	float		t1;
	float		t2;
} t_pix;



P = O + closest_t * D
// Compute intersection
N = P - closest_sphere.center
// Compute sphere normal at intersection
N = N / length(N)
return closest_sphere.color * ComputeLighting(P, N)

ComputeLighting(P, N) 
{
	i = 0.0
//	for light in scene.Lights 
//	{
/*		if light.type == ambient 
		{
			i += light.intensity
		}*/
		else 
		{
			L = light.position - P
			n_dot_l = dot(N, L)
			if n_dot_l > 0 
			{
				i += light.intensity * n_dot_l/(length(N) * length(L))
			}
		}
//	}
	return i
}

ComputeLighting(P, N, V, s) 
{
	i = 0.0
	for light in scene.Lights 
	{
		if light.type == ambient 
		{
			i += light.intensity
		} 
		else 
		{
			if light.type == point 
			{
				L = light.position - P
			} 
			else 
			{
				L = light.direction
			}
// Diffuse
			n_dot_l = dot(N, L)
			if n_dot_l > 0 
			{
				i += light.intensity * n_dot_l/(length(N) * length(L))
			}
/*			
// Specular
¶ 			if s != -1 
			{
				R = 2 * N * dot(N, L) - L
				r_dot_v = dot(R, V)
				if r_dot_v > 0 
				{
					i += light.intensity * pow(r_dot_v/(length(R) * length(V)), s)
				}
			}
		}*/
	}
	return i
}
