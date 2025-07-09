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

// リスト構造を使って、lisを実行したい。
// この場合は配列のほうが扱いやすいので、配列にする関数を作るかどうか
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

int lis(int arr[], int n, int result[])
{
	int	i;
	int	j;
	int	k;
	int	max_len;
	int	max_idx;
	int	prev[500];
	int	dp[500];

	i = 0;
	while (i < n)
	{
		prev[i] = -1;
		dp[i] = 1;
		i++;
	}
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
	i = 0;
	max_len = 0;
	max_idx = -1;
	while (i < n)
	{
		if (dp[i] > max_len)
		{
			max_len = dp[i];
			max_idx = i;
		}
		i++;
	}
	k = max_len - 1;
	while (max_idx != -1)
	{
		result[k--] = arr[max_idx];
		max_idx = prev[max_idx];
	}
	return (max_len);
}

int	find_lis(int argc, t_root *stack_a)
{
	int		i;
	int		*arr;
	int		*result;
	t_list	*cur;

	arr = format_array(stack_a);
	if (!arr)
		return (0);
	result = malloc(sizeof(int) * 500);
	if (!result)
		return (free(arr), 0);
	int	max_len = lis(arr, argc - 1, result);
	cur = stack_a->sentinel->next;
	while (cur != stack_a->sentinel)
	{
		i = 0;
		while (i < max_len)
		{
			if (cur->number == result[i])
			{
				cur->lis = true;
				stack_a->lis_count += 1;
			}
			i++;
		}
		cur = cur->next;
	}
	return (free(arr), free(result), 1);
}
