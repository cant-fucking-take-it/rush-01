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
	printf("\n\nreqs:\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d, ", reqs[i][j]);
		}
		printf("\n");
	}
}
void	print_board(int *board, int size)
{
	printf("\n\nboard:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d, ", board[get_pos(i, j, size)]);
		}
		printf("\n");
	}
}
