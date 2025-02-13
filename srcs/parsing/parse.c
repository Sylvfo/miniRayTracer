/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:33:08 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/13 14:56:37 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

/* ----------------------------------------------------------------------------
	Vérifie que la chaîne ne contient que des espaces.
---------------------------------------------------------------------------- */
static int	check_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

/* ----------------------------------------------------------------------------
	Parse un triplet de float sous la forme x,y,z. Avance le pointeur.
---------------------------------------------------------------------------- */
static int	parse_coordinates(char **line, float *x, float *y, float *z)
{
	*x = ft_atof(*line);
	while (**line && **line != ',' && **line != ' ')
		(*line)++;
	if (**line != ',')
		return (0);
	(*line)++;
	*y = ft_atof(*line);
	while (**line && **line != ',' && **line != ' ')
		(*line)++;
	if (**line != ',')
		return (0);
	(*line)++;
	*z = ft_atof(*line);
	while (**line && **line != ' ')
		(*line)++;
	if (**line != ' ')
		return (0);
	return (1);
}

/* ----------------------------------------------------------------------------
	Parse les trois composantes de couleur (r, g, b).
	Avance le pointeur et renvoie 0 en cas d'erreur.
---------------------------------------------------------------------------- */
static int	parse_color(char **line, int *r, int *g, int *b)
{
	*r = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line != ',')
		return (0);
	(*line)++;
	*g = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line != ',')
		return (0);
	(*line)++;
	*b = ft_atoi(*line);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line == ',')
		return (0);
	return (1);
}

/* ----------------------------------------------------------------------------
	Valide les données d'ambiance contenues dans 'line'.
---------------------------------------------------------------------------- */
int	validate_ambient(char *line)
{
	float	ratio;
	int		r;
	int		g;
	int		b;

	if (line[0] != 'A' || line[1] != ' ')
		return (0);
	line += 2;
	ratio = ft_atof(line);
	while (*line && *line != ' ')
		line++;
	if (*line == '\0' || *(++line) == '\0')
		return (0);
	if (!parse_color(&line, &r, &g, &b))
		return (0);
	if (!check_only_spaces(line))
		return (0);
	if (ratio < 0.0f || ratio > 1.0f)
		return (0);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (1);
}

/* ----------------------------------------------------------------------------
	Valide les données de lumière contenues dans 'line'.
	Format : L x,y,z brightness R,G,B
---------------------------------------------------------------------------- */
int	validate_light(char *line)
{
	float	x, y, z;
	float	brightness;
	int		r, g, b;

	if (line[0] != 'L' || line[1] != ' ')
		return (0);
	line += 2;
	if (!parse_coordinates(&line, &x, &y, &z))
		return (0);
	while (*line == ' ')
		line++;
	brightness = ft_atof(line);
	if (brightness < 0.0f || brightness > 1.0f)
		return (0);
	while (*line && *line != ' ')
		line++;
	if (*line == '\0' || *(++line) == '\0')
		return (0);
	if (!parse_color(&line, &r, &g, &b))
		return (0);
	if (!check_only_spaces(line))
		return (0);
	return (1);
}

/* ----------------------------------------------------------------------------
   Valide les données de caméra contenues dans 'line'.
   Format : C x,y,z 0,0,1 70
   ∗ view point: x,y,z
   ∗ orientation vector (normalisé, chaque composante dans [-1,1])
   ∗ FOV: horizontal field of view en degrés dans [0,180]
---------------------------------------------------------------------------- */
int	validate_camera(char *line)
{
	float	x, y, z;
	float	ox, oy, oz;
	float	fov;

	if (line[0] != 'C' || line[1] != ' ')
		return (0);
	line += 2;
	if (!parse_coordinates(&line, &x, &y, &z))
		return (0);
	while (*line == ' ')
		line++;
	if (!parse_coordinates(&line, &ox, &oy, &oz))
		return (0);
	if (ox < -1.0f || ox > 1.0f ||
		oy < -1.0f || oy > 1.0f ||
		oz < -1.0f || oz > 1.0f)
		return (0);
	while (*line == ' ')
		line++;
	fov = ft_atof(line);
	while (*line && *line != ' ')
		line++;
	if (fov < 0.0f || fov > 180.0f)
		return (0);
	if (!check_only_spaces(line))
		return (0);
	return (1);
}

/* ----------------------------------------------------------------------------
    Parse une ligne du fichier de scène.
---------------------------------------------------------------------------- */
void	parse_line(char *line)
{
	if (line[0] == 'A')
	{
		if (!validate_ambient(line))
		{
			write(2, "Error\nInvalid ambient lighting data\n", 36);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 'L')
	{
		if (!validate_light(line))
		{
			write(2, "Error\nInvalid light data\n", 27);
			exit(EXIT_FAILURE);
		}
	}
	else if (line[0] == 'C')
	{
		if (!validate_camera(line))
		{
			write(2, "Error\nInvalid camera data\n", 28);
			exit(EXIT_FAILURE);
		}
	}
	// Autres vérifications pourront être ajoutées ici
}

/* ----------------------------------------------------------------------------
	Traite le tampon lu depuis le fichier.
---------------------------------------------------------------------------- */
static void	process_buffer(char *buf)
{
	char	*line;
	int		i;

	line = buf;
	while (*line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		line[i] = '\0';
		parse_line(line);
		line += i + 1;
	}
}

/* ----------------------------------------------------------------------------
	Lit le fichier et le traite par blocs.
---------------------------------------------------------------------------- */
void	read_file(int fd)
{
	char	buf[256];
	int		ret;

	while ((ret = read(fd, buf, 255)) > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf);
	}
	if (ret == -1)
	{
		perror("Failed to read file");
		exit(EXIT_FAILURE);
	}
}

/* ----------------------------------------------------------------------------
	Ouvre et parse le fichier de scène.
---------------------------------------------------------------------------- */
void	parse_scene_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	close(fd);
}
