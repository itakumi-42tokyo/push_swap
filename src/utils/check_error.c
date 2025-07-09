/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:14:27 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 21:21:14 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../lib/libft/libft.h"

int	check_duplication(int *numbers, int low, int high)
{
	int	i;

	quick_sort(numbers, low, high);
	i = 0;
	while (i < high)
	{
		if (numbers[i] == numbers[i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_sorted(int *numbers, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (numbers[i] >= numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*check_error(int argc, char *argv[])
{
	int		i;
	bool	error;
	int		*numbers;

	i = 0;
	error = false;
	numbers = malloc(sizeof(int) * (argc - 1));
	if (numbers == NULL)
		return (NULL);
	while (*argv)
	{
		numbers[i] = ut_atoi_with_error(*argv, &error);
		if (error)
			return (free(numbers), NULL);
		i++;
		argv++;
	}
	if (check_sorted(numbers, argc - 1) != 0)
	{
		free(numbers);
		exit (EXIT_SUCCESS);
	}
	if (check_duplication(numbers, 0, argc - 2) != 0)
		return (free(numbers), NULL);
	return (numbers);
}
