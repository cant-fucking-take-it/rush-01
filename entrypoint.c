/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entrypoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:25:11 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 11:39:07 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reqs.h"
#include "solver.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	wc;
	int	side;
	int	*reqs;
	int	*board;

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
	reqs = malloc (4 * wc);
	parse_reqs(argv[1], side, reqs);
	print_reqs(reqs, side);
	board = malloc(4 * side * side);
	fill_array(board, side * side);
	printf("bb\n");
	int r = place_num(board, reqs, 0, side);
	printf("r: %d\n", r);
	print_board(board, side);
	return (0);
}
