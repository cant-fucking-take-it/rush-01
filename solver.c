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

// checks if the array has repeated numbers
// returns 1 if some numbers are repeated, 0 otherwise
int	repeated(int *array, int size)
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
			result[i] = board[get_pos(index, i, size)];
		if (type == 'c')
			result[i] = board[get_pos(i, index, size)];
		i++;
	}
	return (result);
}

// creates a new array with the contents of the original array reversed
// the zeroes (empty space) won't be reversed)
// returns a pointer to the new array
int	*reverse_array(int *array, int size)
{
	int	i;
	int	*reversed;

	i = size - 1;
	reversed = malloc(size);
	fill_array(reversed, size);
	while (i < size)
	{
		if (array[size - 1 - i] != 0)
			reversed[i] = array[size - 1 - i];
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
	total = 0;
	while (i < size)
	{
		if (array[i] > max_height)
		{
			max_height = array[i];
			total++;
		}
		i++;
	}
	return (total);
}

// checks if the correct number of towers are seen
// returns 1 if the number is correct (or could be correct later on)
// otherwise returns 0
int correct_view(int *array, int should_see, int size)
{
	int placed;
	int visible;

	placed = 0;
	while (array[placed] != 0 && placed < size)
	{
		placed++;
	}
	visible = check_visible(array, size);
	if (visible < should_see && placed + 1 < size)
		return (1);
	if (visible == should_see)
		return (1);
	return (0);
}

// verifies if the board is currently valid at the given coordinates
// returns 1 if valid, 0 otherwise
int	valid_board(int *board, int **reqs, int pos, int side_size)
{
	int	*row;
	int	*row_rev;
	int	*col;
	int	*col_rev;
	int	row_num;
	int	col_num;

	row_num = get_coord('r', pos, side_size);
	col_num = get_coord('c', pos, side_size);
	row = extr_line(board, 'r', row_num, side_size);
	row_rev = reverse_array(row, side_size);
	col = extr_line(board, 'c', col_num, side_size);
	col_rev = reverse_array(col, side_size);
	if (repeated(row, side_size) || repeated(col, side_size))
		return (0);
	if (!correct_view(col, reqs[0][col_num], side_size))
		return (0);
	if (!correct_view(col_rev, reqs[1][col_num], side_size))
		return (0);
	if (!correct_view(row, reqs[2][row_num], side_size))
		return (0);
	if (!correct_view(row_rev, reqs[3][row_num], side_size))
		return (0);
	return (1);
}

// tries to place a number at the given position
// returns 1 if the board has been filled, 0 otherwise
int	place_num(int *board, int **reqs, int pos, int side_size)
{
	int	candidate;
	int next_valid;

	if (pos == side_size * side_size)
		return (1);
	
	candidate = 1;
	next_valid = 0;
	while (candidate <= side_size)
	{
		print_board(board, side_size);
		printf("%d", candidate);
		board[pos] = candidate;
		if (!valid_board(board, reqs, pos, side_size))
			continue;
		else
			next_valid = place_num(board, reqs, pos + 1, side_size);
		candidate++;
	}
	return (next_valid);
}
