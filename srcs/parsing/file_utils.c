/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 14:12:15 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"

/* ----------------------------------------------------------------------------
	Traite chaque ligne lue depuis le buffer.
---------------------------------------------------------------------------- */
void	process_buffer(char *buf)
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
	Lit le fichier ligne par ligne et traite les données.
---------------------------------------------------------------------------- */
void	read_file(int fd)
{
	char	buf[256];
	int		ret;

	ret = read(fd, buf, 255);
	while (ret > 0)
	{
		buf[ret] = '\0';
		process_buffer(buf);
		ret = read(fd, buf, 255);
	}
	if (ret == -1)
		error_exit("Failed to read file");
}
