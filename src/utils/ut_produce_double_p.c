/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_produce_double_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:17:08 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/26 20:15:47 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// 片方がNULLの場合はもう片方だけのダブルポインタを作りたい。

static char	**process(const char *s1, const char *s2)
{
	int		i;
	char	**result_str;

	result_str = malloc(sizeof(char *));
	if (result_str == NULL)
		return (NULL);
	i = 0;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL)
			result_str[i] = ft_strdup(s2);
		if (s2 == NULL)
			result_str[i] = ft_strdup(s1);
		if (result_str[i++] == NULL)
		{
			free(result_str);
			return (NULL);
		}
		result_str[i] = NULL;
		return (result_str);
	}
	return (result_str);
}

char	**ut_produce_double_p(const char *s1, const char *s2)
{
	int		i;
	char	**result_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
	{
		result_str = process(s1, s2);
		if (result_str == NULL)
			return (NULL);
		return (result_str);
	}
	result_str = malloc(sizeof(char *));
	if (result_str == NULL)
		return (NULL);
	i = 0;
	result_str[i] = ft_strdup(s1);
	if (result_str[i++] == NULL)
		return (free(result_str), NULL);
	result_str[i] = ft_strdup(s2);
	if (result_str[i++] == NULL)
		return (free(*result_str),free(result_str),  NULL);
	result_str[i] = NULL;
	return (result_str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *s1 = "hello";
// 	char *s2 = "world";
// 	char **res = ut_produce_double_p(s1, s2);
// 	while (*res != NULL)
// 	{
// 		printf("%s\n", *res);
// 		res++;
// 	}
// 	return (0);
// }
