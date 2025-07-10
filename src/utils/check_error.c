/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:14:27 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:24:08 by itakumi          ###   ########.fr       */
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

/*
** Parse argv to int array, set error flag if any conversion fails
*/
static int	*parse_numbers(int argc, char **argv, bool *err)
{
	int	*nums;
	int	i;

	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (NULL);
	i = 0;
	while (*argv)
	{
		nums[i] = ut_atoi_with_error(*argv, err);
		if (*err)
			return (free(nums), NULL);
		i++;
		argv++;
	}
	return (nums);
}

/*
** Validate array: sorted/duplication rules
*/
static int	validate_numbers(int *nums, int count)
{
	if (check_sorted(nums, count) != 0)
	{
		free(nums);
		exit(EXIT_SUCCESS);
	}
	if (check_duplication(nums, 0, count - 1) != 0)
		return (-1);
	return (0);
}

int	*check_error(int argc, char *argv[])
{
	int		*numbers;
	bool	error;

	error = false;
	numbers = parse_numbers(argc, argv, &error);
	if (numbers == NULL)
		return (NULL);
	if (validate_numbers(numbers, argc - 1) == -1)
		return (free(numbers), NULL);
	return (numbers);
}
