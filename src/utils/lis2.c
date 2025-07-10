/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:09:14 by itakumi           #+#    #+#             */
/*   Updated: 2025/07/10 21:14:41 by itakumi          ###   ########.fr       */
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
