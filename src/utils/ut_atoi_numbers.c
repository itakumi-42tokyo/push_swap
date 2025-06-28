/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_atoi_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 22:09:25 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/28 06:39:40 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	*ut_atoi_numbers(int argc, char *argv[])
{
	int	i;
	int	*result;

	result = malloc(sizeof(int) * (argc - 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*argv)
	{
		result[i] = ft_atoi(*argv);
		i++;
		argv++;
	}
	return (result);
}
