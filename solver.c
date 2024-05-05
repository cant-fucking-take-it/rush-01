/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:36:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/05 17:32:55 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// checks if the array has repeated numbers
// returns 1 if some numbers are repeated, 0 otherwise
int	repeated(int num, int *array, int size)
{
	int	i;
	int	j;
	int	*seen_nums;

	seen_nums = malloc(size);
	fill_array(seen_nums, size);
	i = 0;
	while (i < size && array[i] != 0)
	{
		while (seen_nums[j] != 0)
		{
			if (array[i] == seen_nums[j])
			{
				free(seen_nums);
				return (1);
			}
			j++;
		}
		seen_nums[i] = array[i];
		i++;
	}
	free(seen_nums);
	return (0);
}

// extracts a line (row or column) with the given index from the board
// returns a pointer to an array of ints with the numbers of the given line
// returns a null pointer if given invalid params
int	*extr_line(int *board, char type, int index, int size)
{
	int	i;
	int	*result;

	i = 0;
	if (type != 'r' && type != 'c')
		return (0);
	result = malloc(size);
	while (i < size)
	{
		if (type == 'r')
			result[i] = board[get_pos(index, i)];
		if (type == 'c')
			result[i] = board[get_pos(i, index)];
		i++;
	}
	return (result);
}

// creates a new array with the contents of the original array reversed
// returns a pointer to the new array
int	*reverse_array(int *array, int size)
{
	int	i;
	int	*reversed;

	i = 0;
	reversed = malloc(size);
	while (i < size)
	{
		reversed[i] = array[i];
		i++;
	}
	return (reversed);
}

// counts the number of visible towers, traversing the array from start to end
// returns how many towers would be visible
int	check_visible(int *array, int size)
{
	int	i;
	int	max_height;
	int	total;

	i = 0;
	max_height = 0;
	total while (i < size)
	{
		if (array[i] > max_height)
		{
			max_height = array[i];
			total++;
		}
	}
	return (total);
}

// verifies if the board is currently valid at the given coordinates
// returns 1 if valid, 0 otherwise
int	valid_board(int *board, int **reqs, int pos, int side_size)
{
	int	*row;
	int	*rev_row;
	int	*col;
	int	*rev_col;

	row = extr_line(board, 'r', get_coord('r', pos, side_size), side_size);
	rev_row = reverse_array(row);
	col = extr_line(board, 'c', get_coord('c', pos, side_size), side_size);
	rev_col = reverse_array(col);
	if (repeated(row) || repeated(col))
		return 0;
	if //TODO 
}

// tries to place a number at the given position
// returns 1 if the board has been filled, 0 otherwise
int	place_num(int *board, int **reqs, int pos, int side_size)
{
	int	candidate;

	if (pos = side_size * side_size)
		return (1);
	candidate = 1;
	while (candidate < size)
	{
		board if (valid_board(board, pos, side_size)) return (place_board(board,
				pos + 1, side_size));
		candidate++;
	}
}
