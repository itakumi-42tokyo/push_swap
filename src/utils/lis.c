/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:38:14 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/03 13:31:19 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

// リスト構造を使って、lisを実行したい。
// この場合は配列のほうが扱いやすいので、配列にする関数を作るかどうか
//
#include <stdio.h>
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

t_lis	*check_lis(t_root *root, int *arr)
{
	int		i;
	int		j;
	t_lis	*lis;

	lis = malloc(sizeof(t_lis));
	if (lis == NULL)
		return (NULL);
	i = 1;
	while (i < root->node_len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] < arr[j] && lis->dp[i] < lis->dp[j] + 1)
			{
				lis->dp[i] = lis->dp[j] + 1;
				lis->prev[i] = j;
			}
			j++;
		}
		i++;
	}
	lis->max_len = 0;
	lis->max_idx = -1;
	return (lis);
}

t_lis	*check_lis2(t_root *root)
{
	int		i;
	int		*arr;
	t_lis	*lis;

	arr = format_array(root);
	if (arr == NULL)
		return (NULL);
	lis = check_lis(root, arr);
	if (lis == NULL)
		return (free(arr), NULL);
	i = 0;
	while (i < root->node_len)
	{
		if (lis->dp[i] > lis->max_len)
		{
			lis->max_len = lis->dp[i];
			lis->max_idx = i;
		}
		i++;
	}
	lis->arr = arr;
	return (lis);
}



// これをどのようにして、２５行以内に納めろというのか。
// 構造体にして返すしかなさそう。
// 構造体の中の配列は保持されるのだろうか。

t_list	*judge_lis(t_root *root)
{
	int		i;
	int		result[MAX_ARG];
	t_lis	*lis;
	t_list	*cur;

	lis = check_lis2(root);
	if (lis == NULL)
		return (NULL);
	i = lis->max_len - 1;
	printf("max_idx: %d\n", lis->max_idx);
	while (lis->max_idx != -1)
	{
		result[i--] = (lis->arr)[lis->max_idx];
		printf("max_idx: %d\n", lis->max_idx);
		lis->max_idx = (lis->prev)[lis->max_idx];
		printf("%p\n", lis->prev);
	}
	cur = root->sentinel->next;
	while (cur != root->sentinel)
	{
		i = 0;
		while (i < lis->max_len)
		{
			if (cur->number == result[i++])
				cur->lis = true;
		}
		cur = cur->next;
	}
	return (free(lis->arr), free(lis), cur);
}

// index化するときにlisも確認すればよくね？
//　numbersにlisを掛けて、
// い
