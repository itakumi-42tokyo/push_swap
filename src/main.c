/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:59:05 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 22:49:34 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include <stdio.h>

/*
** Select appropriate sorting algorithm based on element count
*/
static t_singl	*select_sort_algorithm(int argc, t_root *stack_a)
{
	if (argc <= 6)
		return (sort_under_five(argc, stack_a));
	else
		return (sort_over_six(argc, stack_a));
}

/*
** Main entry point - parse arguments, sort, and output operations
*/
int	main(int argc, char **argv)
{
	int		*sorted_numbers;
	int		*unchange_numbers;
	t_root	*stack_a;
	t_singl	*operation;

	if (argc <= 1)
		return (0);
	sorted_numbers = check_error(argc, argv + 1);
	if (sorted_numbers == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	unchange_numbers = ut_atoi_numbers(argc, argv + 1);
	if (unchange_numbers == NULL)
	{
		free(sorted_numbers);
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = coord_comp(unchange_numbers, sorted_numbers, argc - 1);
	free(unchange_numbers);
	free(sorted_numbers);
	if (stack_a == NULL)
		return (0);
	if (check_sorted_s(stack_a) == 1)
		return (cdll_clear(&stack_a, cdll_delone), 0);
	operation = select_sort_algorithm(argc, stack_a);
	print_node(operation);
	cdll_clear(&stack_a, cdll_delone);
	return (0);
}

