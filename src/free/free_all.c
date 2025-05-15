/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:00:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 15:55:26 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_context_content(t_program_context *context)
{
	if (context->pix && context->pix[0] && context->pix[0][0])
	{
		if (context->pix[0][0]->obj)
			free_object(context->pix[0][0]->obj, context->num_obj);
		if (context->pix[0][0]->lux)
			free_light_memory(context->pix[0][0]->lux, 2);
		if (context->pix[0][0]->cam)
			free_camera(context->pix[0][0]->cam);
	}
}

void	free_all(t_program_context *context)
{
	if (!context)
		return ;

	free_ima(context);
	free_hits(context);
	free_context_content(context);
	if (context->pix)
		free_pix(context->pix, context->height, context->width,
			context->num_obj);
	if (context->num_obj)
		free(context->num_obj);
	free(context);
}
