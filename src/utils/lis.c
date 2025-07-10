/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:38:14 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:23:05 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

/*
** Initialize dp and prev arrays for LIS computation
*/
static void	init_lis_arrays(int n, int dp[], int prev[])
{
	int	i;

	i = 0;
	while (i < n)
	{
		dp[i] = 1;
		prev[i] = -1;
		i++;
	}
}

/*
** Compute LIS dp values and predecessor indices
*/
static void	compute_lis_dp(int arr[], int n, int dp[], int prev[])
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

/*
** Find the maximum LIS length and its ending index
*/
static int	find_lis_max(int dp[], int n, int *max_len, int *max_idx)
{
	int	i;

	i = 0;
	*max_len = 0;
	*max_idx = -1;
	while (i < n)
	{
		if (dp[i] > *max_len)
		{
			*max_len = dp[i];
			*max_idx = i;
		}
		i++;
	}
	return (*max_len);
}

/*
** Reconstruct the LIS into the result array
*/
static void
	construct_lis(int arr[], int prev[], int max_len0_idx1[], int result[])
{
	int	k;

	k = max_len0_idx1[0] - 1;
	while (max_len0_idx1[1] != -1)
	{
		result[k--] = arr[(max_len0_idx1[1])];
		max_len0_idx1[1] = prev[(max_len0_idx1[1])];
	}
}

/*
** Main LIS function - finds longest increasing subsequence
*/
int	lis(int arr[], int n, int result[])
{
	int	dp[500];
	int	prev[500];
	int	max_len0_idx1[2];

	init_lis_arrays(n, dp, prev);
	compute_lis_dp(arr, n, dp, prev);
	find_lis_max(dp, n, &max_len0_idx1[0], &max_len0_idx1[1]);
	construct_lis(arr, prev, max_len0_idx1, result);
	return (max_len0_idx1[0]);
}
