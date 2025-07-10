/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:59:05 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 00:12:42 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include <stdio.h>

/*
** Validate inputs and build stack A. Exit on any error.
*/
static t_root	*prepare_stack(int argc, char **argv)
{
	int		*sorted;
	int		*raw;
	t_root	*stack;

	sorted = check_error(argc, argv + 1);
	if (sorted == NULL)
		exit_and_errormsg();
	raw = ut_atoi_numbers(argc, argv + 1);
	if (raw == NULL)
	{
		free(sorted);
		exit_and_errormsg();
	}
	stack = coord_comp(raw, sorted, argc - 1);
	free(raw);
	free(sorted);
	if (stack == NULL)
		exit_and_errormsg();
	return (stack);
}

/*
** Dispatch to proper sorting routine
*/
static int	execute_sort(int argc, t_root *stack_a)
{
	if (argc < 6)
		return (sort_under_five(argc, stack_a));
	return (sort_over_six(argc, stack_a));
}

/*
** Program entry point
*/
int	main(int argc, char **argv)
{
	t_root	*stack_a;
	int		status;

	if (argc <= 1)
		return (0);
	stack_a = prepare_stack(argc, argv);
	if (check_sorted_s(stack_a) == 1)
		return (cdll_clear(&stack_a, cdll_delone), EXIT_SUCCESS);
	status = execute_sort(argc, stack_a);
	if (status == -1)
	{
		cdll_clear(&stack_a, cdll_delone);
		exit_and_errormsg();
	}
	cdll_clear(&stack_a, cdll_delone);
	return (0);
}

