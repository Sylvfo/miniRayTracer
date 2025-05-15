/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:10:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 14:08:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_matrix(float *matrix)
{
	if (matrix)
	{
		free(matrix);
		matrix = NULL;
	}
}

void	free_coord(t_coord *coord)
{
	if (coord)
	{
		free(coord);
		coord = NULL;
	}
}

void	free_color(t_color *color)
{
	if (color)
	{
		free(color);
		color = NULL;
	}
}

void	free_ima(t_program_context *context)
{
	if (!context->ima)
		return ;
	if (context->ima->img)
	{
		mlx_destroy_image(context->ima->mlx_ptr, context->ima->img);
		context->ima->img = NULL;
	}
	if (context->ima->mlx_win)
	{
		mlx_destroy_window(context->ima->mlx_ptr, context->ima->mlx_win);
		context->ima->mlx_win = NULL;
	}
	if (context->ima->mlx_ptr)
	{
		mlx_destroy_display(context->ima->mlx_ptr);
		free(context->ima->mlx_ptr);
		context->ima->mlx_ptr = NULL;
	}
	free(context->ima);
	context->ima = NULL;
}
