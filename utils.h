/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:03:22 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/05 20:03:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_coord(char type, int index, int size);
int		get_pos(int row, int col, int size);
void	fill_array(int *array, int size);
void	print_reqs(int **reqs, int size);
void	print_board(int *board, int size);
