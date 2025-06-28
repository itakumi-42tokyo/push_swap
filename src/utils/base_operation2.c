/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_operation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 05:47:13 by itakumi           #+#    #+#             */
/*   Updated: 2025/06/28 06:48:46 by itakumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "list.h"
#include "libft.h"

void	print_oparation(char *operation[])
{
	if (operation == NULL)
		return ;
	while (*operation)
	{
		write(1, *operation, ft_strlen(*operation));
		write(1, "\n", 1);
		operation++;
	}
}
