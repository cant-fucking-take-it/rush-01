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

#include "reqs.c"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	wc;
	int	side;
	int	*reqs[4];

	if (argc != 2)
	{
		printf("error\n");
		return (0);
	}
	wc = ft_count_words(argv[1]);
	side = wc / 4;
	if (side != 0 && wc % 4 == 0)
		printf("costat de %d\n", side);
	else
		printf("error\n");
	parse_reqs(argv[1], side, reqs);
	printf("reqs:");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < side; j++)
		{
			printf("%d, ", reqs[i][j]);
		}
		printf("\n");
	}
}
