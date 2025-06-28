/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:36:07 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/27 20:55:05 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// return relative order in numbers
int	binary_search(int numbers[], int target, int len)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = len - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (target == numbers[mid])
			return (mid);
		if (target > numbers[mid])
			left = mid + 1;
		if (target < numbers[mid])
			right = mid - 1;
	}
	return (-1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int numbers[] = {1, 10, 20, 24, 40, 60};
// 	int	target = 30;
// 	int	len = 6;
// 	int index = binary_search(numbers, target, len);
// 	printf("index: %d\n", index);
// 	return (0);
// }
