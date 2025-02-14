/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:03:54 by syl               #+#    #+#             */
/*   Updated: 2025/02/14 11:23:53 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void print_matrix(float **m_matrix, unsigned int row, unsigned int col)
{
	int a;
	int b;

	a = 0;
	while(a < row)
	{
		printf("||");
		b = 0;
		while(b < col)
		{
			printf(GREEN1 " %.2f |" RESET, m_matrix[a][b]);
			b++;
		}
		printf("|\n");
		a++;
	}
}

/*
void print_matrix_44(float **m_matrix)
{
	int a;
	int b;

	a = 0;
	while(a < 4)
	{
		printf("||");
		b = 0;
		while(b < 4)
		{
			printf(" %.2f |", m_matrix[a][b]);
			b++;
		}
		printf("|\n");
		a++;
	}
}

void print_matrix_33(float **m_matrix)
{
	int a;
	int b;

	a = 0;
	while(a < 3)
	{
		printf("||");
		b = 0;
		while(b < 3)
		{
			printf(" %.2f |", m_matrix[a][b]);
			b++;
		}
		printf("|\n");
		a++;
	}
}

void print_matrix_22(float **m_matrix)
{
	int a;
	int b;

	a = 0;
	while(a < 2)
	{
		printf("||");
		b = 0;
		while(b < 2)
		{
			printf(" %.2f |", m_matrix[a][b]);
			b++;
		}
		printf("|\n");
		a++;
	}
}*/