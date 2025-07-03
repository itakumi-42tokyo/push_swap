/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:10:52 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 14:27:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"

// 入力された数字そのものの情報はいらないのです。
// malloc list
// 1. sorted_numbers.
// 2. unchange_numbers.
// 3. stack_a.
// 4. stack_b.
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int		*unchange_numbers;
	int		*sorted_numbers;
	t_root	*stack_a;
	t_singl	*operation;

	if (argc == 1 || argv == NULL || argv[1][0] == '\0')
		exit(EXIT_SUCCESS);
	argv++;
	sorted_numbers = check_error(argc, argv);
	if (sorted_numbers == NULL)
		exit_and_errormsg();
	unchange_numbers = ut_atoi_numbers(argc, argv);
	if (unchange_numbers == NULL)
		exit_and_errormsg();
	stack_a = coordinate_compression(unchange_numbers, sorted_numbers, argc - 1);
	if (stack_a == NULL)
		exit_and_errormsg();
	free(unchange_numbers);
	free(sorted_numbers);
	if (argc < 7)
		operation = sort_under_five(argc, stack_a);
	else
		operation = sort_over_six(argc, stack_a);
	// if (operation == NULL)
	// 	exit_and_errormsg();
	// print_node(operation);
	lst_clear(&operation);
	cdll_clear(&stack_a, cdll_delone);
	return (0);
}
// mallocできなかったときは、error_msgを返すべきなのかが分からない。
