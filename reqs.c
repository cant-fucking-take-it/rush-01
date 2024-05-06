/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:29:53 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 11:38:27 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// counts words in a string
// for the purpose of this exercice, a word may only contain numbers
// words are separated by one or more spaces
// returns the number of words, or -1 if an invalid character has been found
int	ft_count_words(char *words)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*words != '\0')
	{
		if (*words >= '0' && *words <= '9')
		{
			if (!in_word)
				count++;
			in_word = 1;
		}
		else if (*words == ' ')
			in_word = 0;
		else
			return (-1);
		words++;
	}
	return (count);
}

int	parse_next_int(char **str)
{
	int	in_word;
	int	num;

	in_word = 0;
	num = 0;
	while (**str != '\0')
	{
		if (**str >= '0' && **str <= '9')
		{
			in_word = 1;
			num *= 10;
			num += **str - '0';
			printf("%d\n", num);
		}
		else if (**str == ' ' && in_word)
			break ;
		*str += 1;
	}
	return (num);
}

void	parse_reqs(char *words, int side_size, int *out)
{
	int		i;
	char	**bookmark;

	i = 0;
	bookmark = &words;
	while (i < side_size * 4)
	{
		out[i] = parse_next_int(bookmark);
		i++;
	}
}
