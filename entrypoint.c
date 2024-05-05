/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entrypoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:25:11 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/05 15:56:05 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.c"
#include "reqs.c"
#include "solver.c"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	wc;
	int	side;
	int	*reqs[4];
	int *board;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	wc = ft_count_words(argv[1]);
	side = wc / 4;
	if (side != 0 && wc % 4 == 0)
		printf("costat de %d\n", side);
	else
	{
		printf("Error\n");
		return (0);
	}
	parse_reqs(argv[1], side, reqs);
	board = malloc(4*side*side);
	fill_array(board, side*side);
	print_reqs(reqs, side);
	place_num(board, reqs, 0, side);
	print_board(board, side);
}
