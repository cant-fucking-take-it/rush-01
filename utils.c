/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:03:48 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/05 20:38:40 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// calculates and returns the coordinate of a cell's row or column
// type must be 'r' or 'c', to pick between row and column
// returns -1 if the input is invalid
int	get_coord(char type, int index, int size)
{
	if (type == 'r')
		return (index / size);
	if (type == 'c')
		return (index % size);
	return (-1);
}

// calculates and returns the position of a cell in the board
// returns -1 if the input is invalid
int	get_pos(int row, int col, int size)
{
	if (row > size || col > size)
		return (-1);
	return (row * size + col);
}

// fills a given array with 0s
void	fill_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
	}
}

void	print_reqs(int **reqs, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n\nreqs:\n");
	while (i < 4)
	{
		while (j < size)
		{
			printf("%d, ", *reqs[i*4+j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_board(int *board, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n\nboard:\n");
	while (i < size)
	{
		while (j < size)
		{
			printf("%d, ", board[get_pos(i, j, size)]);
			j++;
		}
		printf("\n");
		i++;
	}
}
