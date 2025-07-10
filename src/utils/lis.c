/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:38:14 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/09 23:00:35 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

/*
** Convert linked list to array for LIS computation
*/
int	*format_array(t_root *root)
{
	int		i;
	int		*arr;
	t_list	*cur;

	arr = malloc(sizeof(int) * root->node_len);
	if (arr == NULL)
		return (NULL);
	cur = root->sentinel->next;
	i = 0;
	while (cur != root->sentinel)
	{
		arr[i++] = cur->number;
		cur = cur->next;
	}
	return (arr);
}

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
static void	construct_lis(int arr[], int prev[], int max_idx,
	int max_len, int result[])
{
	int	k;

	k = max_len - 1;
	while (max_idx != -1)
	{
		result[k--] = arr[max_idx];
		max_idx = prev[max_idx];
	}
}

/*
** Main LIS function - finds longest increasing subsequence
*/
int	lis(int arr[], int n, int result[])
{
	int	dp[500];
	int	prev[500];
	int	max_len;
	int	max_idx;

	init_lis_arrays(n, dp, prev);
	compute_lis_dp(arr, n, dp, prev);
	find_lis_max(dp, n, &max_len, &max_idx);
	construct_lis(arr, prev, max_idx, max_len, result);
	return (max_len);
}

/*
** Mark nodes belonging to the LIS
*/
static void	mark_lis_nodes(t_root *stack_a, int result[], int max_len)
{
	int		i;
	t_list	*cur;

	cur = stack_a->sentinel->next;
	while (cur != stack_a->sentinel)
	{
		i = 0;
		while (i < max_len)
		{
			if (cur->number == result[i])
			{
				cur->lis = true;
				stack_a->lis_count++;
			}
			i++;
		}
		cur = cur->next;
	}
}

/*
** Find LIS in stack and mark nodes
*/
int	find_lis(int argc, t_root *stack_a)
{
	int	*arr;
	int	result[500];
	int	max_len;

	arr = format_array(stack_a);
	if (!arr)
		return (0);
	max_len = lis(arr, argc - 1, result);
	mark_lis_nodes(stack_a, result, max_len);
	free(arr);
	return (1);
}
