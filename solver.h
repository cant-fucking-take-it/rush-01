/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 20:03:13 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 10:28:29 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	repeated(int *array, int size);
int	*extr_line(int *board, char type, int index, int size);
int	*reverse_array(int *array, int size);
int	check_visible(int *array, int size);
int	place_num(int *board, int *reqs, int pos, int side_size);
